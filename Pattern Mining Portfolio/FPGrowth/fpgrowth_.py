import sys
import itertools
import time
from urllib.request import urlopen

import matplotlib.pyplot as plt
import pandas as pd
import validators

Database = []
rank = {}
rankDup = {}
iFile = ''
oFile = ''
sep = '\t'
minSup = ''
mapSupport = {}

def creatingItemSets():

    global Database  #here database will be a list of lists
    global sep
    if isinstance(iFile, pd.DataFrame):
        if iFile.empty:
            print("its empty..")
        i = iFile.columns.values.tolist()
        if 'Transactions' in i:
            Database = iFile['Transactions'].tolist()

        # print(self.Database)
    if isinstance(iFile, str):
        if validators.url(iFile):
            data = urlopen(iFile)
            for line in data:
                line.strip()
                line = line.decode("utf-8")
                temp = [i.rstrip() for i in line.split(sep)]
                temp = [x for x in temp if x]
                Database.append(temp)
        else:
            try:
                with open(iFile, 'r', encoding='utf-8') as f:
                    for line in f:
                        line.strip()
                        temp = [i.rstrip() for i in line.split(sep)]
                        temp = [x for x in temp if x]
                        Database.append(temp)
            except IOError:
                print("File Not Found")
                quit()

def frequentOneItem():
    """get all unique item with freq > minsup
    mapSupport contains all unique 1-items in Database whose sup > minsup
    Genlist is the list of all items arranged in decreasing order
    rank dictionary with key = transactionID and value = position (once ranked in decreasing order)
    """
    global mapSupport,rank
    for transaction in Database:
        for i in range(0, len(transaction)):
            if transaction[i] not in mapSupport:
                mapSupport[transaction[i]] = 1
            else:
                mapSupport[transaction[i]] += 1
    mapSupport = {key_transID: value_freq for key_transID, value_freq in mapSupport.items() if value_freq >= minSup}
    genList = [key_transID for key_transID, value_freq in sorted(mapSupport.items(), key=lambda x: x[1], reverse=True)] #genslist stores the keys
    rank = dict([(transID, index) for (index, transID) in enumerate(genList)])
    """print(mapSupport,"\n")
    print(genList, "\n")
    print("rank", rank,"\n")"""
    return genList

def updateTransactions(itemSet):
    """
     Updates the items in transactions with rank of items according to their support
            :Example: oneLength = {'a':7, 'b': 5, 'c':'4', 'd':3}
                        rank = {'a':0, 'b':1, 'c':2, 'd':3}
            Parameters
            ----------
            itemSet: list of one-frequent items
            -------
     Convert the database contents into rank format.
     Each element in database takes the index of its position once ranked using Rank format(highest support to lowest
     Only items whose freq in database > minsup will be added
            """

    Database_as_rank = [] #list of lists of ranks
    global rank
    for transactions in Database:
        transaction_as_rank = [] #list of ranks
        for i in range(len(transactions)):
            if transactions[i] in itemSet:
                transaction_as_rank.append(rank[transactions[i]])
        if len(transaction_as_rank) >= 1:
            transaction_as_rank.sort()
            Database_as_rank.append(transaction_as_rank)
    return Database_as_rank


class Node:
    """
        A class used to represent the node of frequentPatternTree

    Attributes:
    ----------
        itemId: int
            storing item of a node
        counter: int
            To maintain the support of node
        parent: node
            To maintain the parent of node
        children: list
            To maintain the children of node

    Methods:
    -------

        addChild(node)
            Updates the nodes children list and parent for the given node

    """

    def __init__(self, item, children):
        self.itemId = item
        self.counter = 1
        self.parent = None
        self.children = children

    def addChild(self, node):
        """
            Retrieving the child from the tree

            :param node: Children node
            :type node: Node
            :return: Updates the children nodes and parent nodes

        """
        self.children[node.itemId] = node
        node.parent = self


class Tree:
    """
    A class used to represent the frequentPatternGrowth tree structure

    Attributes:
    ----------
        root : Node
            The first node of the tree set to Null.
        summaries : dictionary
            Stores the addresses of nodes which shares same itemId
        info : dictionary
            frequency of items in the transactions

    Methods:
    -------
        addTransaction(transaction, freq)
            adding items of  transactions into the tree as nodes and freq is the count of nodes
        getFinalConditionalPatterns(node)
            getting the conditional patterns from fp-tree for a node
        getConditionalPatterns(patterns, frequencies)
            sort the patterns by removing the items with lower minSup
        generatePatterns(prefix)
            generating the patterns from fp-tree
    """

    def __init__(self):
        self.root = Node(None, {})
        self.summaries = {}
        self.info = {}

    def addTransaction(self, transaction, count):
        """adding transaction into tree

        :param transaction: it represents the one transactions in database

        :type transaction: list

        :param count: frequency of item

        :type count: int
        """

        # This method takes transaction as input and returns the tree
        currentNode = self.root
        for i in range(len(transaction)):
            itemID = transaction[i]
            if itemID not in currentNode.children:
                newNode = Node(itemID, {})
                newNode.freq = count
                currentNode.addChild(newNode)
                if itemID in self.summaries:
                    self.summaries[itemID].append(newNode)
                else:
                    self.summaries[itemID] = [newNode]
                currentNode = newNode
            else:
                currentNode = currentNode.children[itemID]
                currentNode.freq += count

    def getFinalConditionalPatterns(self, alpha):
        """
        generates the conditional patterns for a node

        Parameters:
        ----------
            alpha: node to generate conditional patterns

        Returns
        -------
            returns conditional patterns, frequency of each item in conditional patterns

        """
        finalPatterns = []
        finalFreq = []
        print("sumarry values: ", len(self.summaries[alpha]))
        for i in self.summaries[alpha]: #for all node addresses stored in currentnode.summaries
            set1 = i.freq
            set2 = []
            while i.parent.itemId is not None:
                set2.append(i.parent.itemId)
                i = i.parent
            if len(set2) > 0:
                set2.reverse()
                finalPatterns.append(set2)
                finalFreq.append(set1)
        print("Final patterns & freq: ", len(finalFreq))
        for i in range(len(finalPatterns)):
            print("finalPatterns are:", finalPatterns[i], "finalFreq is:", finalFreq[i])
        finalPatterns, finalFreq, info = self.getConditionalTransactions(finalPatterns, finalFreq)
        return finalPatterns, finalFreq, info

    @staticmethod
    def getConditionalTransactions(ConditionalPatterns, conditionalFreq):
        """
        To calculate the frequency of items in conditional patterns and sorting the patterns
        Parameters
        ----------
        ConditionalPatterns: paths of a node
        conditionalFreq: frequency of each item in the path

        Returns
        -------
            conditional patterns and frequency of each item in transactions
        """
        global _minSup
        pat = []
        freq = []
        data1 = {}
        print("Getting Conditional Transactions")
        for i in range(len(ConditionalPatterns)):
            for j in ConditionalPatterns[i]:
                #print("in getConditional| i is: ", i , " j is: ",j)
                if j in data1:
                    data1[j] += conditionalFreq[i]
                else:
                    data1[j] = conditionalFreq[i]
        print("data1", data1)
        up_dict = {key_index: value_freq for key_index, value_freq in data1.items() if value_freq >= minSup} #sum up freq of all individual items
        print("updict", up_dict)
        count = 0
        for sublist in ConditionalPatterns:
            temp = [item for item in sublist if item in up_dict]
            temp = sorted(temp, key=lambda x: (up_dict.get(x), -x), reverse=True)
            if len(temp) > 0:
                pat.append(temp)
                freq.append(conditionalFreq[count])
                print("pattern",pat, freq)
            count += 1
        return pat, freq, up_dict

    def generatePatterns(self, prefix):
        """
        To generate the frequent patterns
        Parameters
        ----------
        prefix: an empty list

        Returns
        -------
        Frequent patterns that are extracted from fp-tree
        Recursion is applied here
        """
        for i in sorted(self.summaries, key=lambda x: (self.info.get(x), -x)):
            pattern = prefix[:]
            print("\nInput pattern: ",pattern)
            pattern.append(i)
            print("Generating patterns \nI is: ",i ,"Mining pattern is: ", pattern, "freq is: ", self.info[i])
            print("\nYielding .....")
            yield pattern, self.info[i]
            print("\ngetFinalConditional patterns....")
            patterns, freq, info = self.getFinalConditionalPatterns(i)
            conditionalTree = Tree()
            conditionalTree.info = info.copy()
            for i in range(len(patterns)):
                conditionalTree.addTransaction(patterns[i], freq[i])
            if len(patterns) > 0:
                print("\nInto conditionalTree.generate...")
                for q in conditionalTree.generatePatterns(pattern):
                    print("Yielding q...", q)
                    yield q


def buildTree(Database_as_ranks, info):
    """
            Builds the tree with updated transactions
            Parameters:
            ----------
                transactions: updated transactions
                info: support details of each item in transactions

            Returns:
            -------
                transactions compressed in fp-tree

            """
    rootNode = Tree()
    rootNode.info = info.copy()
    for i in range(len(Database_as_ranks)):
        rootNode.addTransaction(Database_as_ranks[i], 1)
    return rootNode

def savePeriodic( itemSet):
    """
        The duplication items and their ranks
        Parameters:
        ----------
            itemSet: frequent itemSet that generated

        Returns:
        -------
            patterns with original item names.

    """
    temp = str()
    for i in itemSet:
        temp = temp + rankDup[i] + " "
    return temp


def runFPgrowth():
    """
        main program to start the operation

    """
    global rankDup
    global minSup
    #self.startTime = time.time()
    if iFile is None:
        raise Exception("Please enter the file path or file name:")
    if minSup is None:
        raise Exception("Please enter the Minimum Support")
    creatingItemSets()
    #minSup = convert(minSup)
    itemSet = frequentOneItem()
    Database_as_ranks = updateTransactions(itemSet)
    for key_transID, value_index in rank.items():
        rankDup[value_index] = key_transID #switches values of keys vs value in dic rank
    info = {rank[key_transID]: value_freq for key_transID, value_freq in mapSupport.items()} #mapSupport contains data (trnasID, freq) >minsup
    #info --> key(index), value(freq)
    Tree = buildTree(Database_as_ranks, info)
    patterns = Tree.generatePatterns([]) #creating a generator
    finalPatterns = {}
    print("\nsaving patterns...")
    print("patterns:", patterns)
    for k in patterns:  #loop through generator
        print("\nReceived message... Saving pattern info,\nk:k[0] ", k, k[0])
        s = savePeriodic(k[0])
        #print(" s: ", s)
        finalPatterns[str(s)] = k[1]
    print("Frequent patterns were generated successfully using frequentPatternGrowth algorithm")
    print('total patterns: --> ', len(finalPatterns))
    """count = 0
    f = open(oFile, "w")
    for x, y in finalPatterns.items():
        count+=1
        f.write(x)
        f.write("\n")
    f.close()

    self.__endTime = _fp._time.time()
    self.__memoryUSS = float()
    self.__memoryRSS = float()
    process = _fp._psutil.Process(_fp._os.getpid())
    self.__memoryUSS = process.memory_full_info().uss
    self.__memoryRSS = process.memory_info().rss"""





if __name__ == "__main__":

    iFile = sys.argv[1]
    oFile = sys.argv[2]
    minSup = int(sys.argv[3])
    runTimeList = []

    minSupList = []
    start = time.time()
    runFPgrowth()
    end = time.time()
    print(end - start)
    """
    for minSup in range(1000, 6000, 500):
        
        start = time.time()
        uniqueItemList = getUniqueItemList(inputFile, minSup)
        #runEclat(uniqueItemList, minSup)
        end = time.time()
        Runtime = end - start
        print(len(freqItems.keys()))
        runTimeList.append(Runtime)
        minSupList.append(minSup)
        print('minSup', minSup, 'Run time', end - start, 'seconds')
        tidSets = {}
        freqItems = {}
        trans_set = set()
    graphResults(minSupList, runTimeList)"""