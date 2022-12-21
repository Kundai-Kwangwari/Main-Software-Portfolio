import sys
import time
from collections import defaultdict



def searchFrequentAndPrune(itemSet, transactionList, minSupport, freqSet):
    """enumarates all occurences and prunes using minSupport"""
    freqItemSet = set()
    localFrequencyLibrary = defaultdict(int)

    for item in itemSet:
        for transaction in transactionList:
            if item.issubset(transaction):
                freqSet[item] += 1
                localFrequencyLibrary[item] += 1

    for item, count in localFrequencyLibrary.items():
        if float(count) >= minSupport:
            freqItemSet.add(item)
    return freqItemSet


def joinSet(itemSet, length):
    """returns a set with all combinations of length = parameter length"""
    return set([i.union(j) for i in itemSet for j in itemSet if len(i.union(j)) == length])

def getItemSetTransactionList(Database):

    transactionList = list()
    uniqueItemSet = set()
    for record in Database:
        transaction = frozenset(record)
        transactionList.append(transaction)
        for item in transaction:
            uniqueItemSet.add(frozenset([item]))  # Generate 1-itemSets
    return uniqueItemSet, transactionList


def runApriori(Database, minSup):
    """

    :param Database: List of Lists containing all transactions performed
    :param minSup:
    :return: null
    """

    start = time.time()
    uniqueItemSet, transactionList = getItemSetTransactionList(Database)

    allFrequentItemSet = dict()
    freqSet = defaultdict(int)

    len_1_Set = searchFrequentAndPrune(uniqueItemSet, transactionList, minSup, freqSet)

    currentLSet = len_1_Set
    allFrequentItemSet[0] = currentLSet
    patterns = len(len_1_Set)

    length = 2
    while currentLSet != set([]):

        currentLSet = joinSet(currentLSet, length)
        currentCSet = searchFrequentAndPrune(currentLSet, transactionList, minSup, freqSet)
        currentLSet = currentCSet
        allFrequentItemSet[length - 1] = currentLSet
        patterns += len(currentCSet)
        length = length + 1

        end = time.time()
        outFile = sys.argv[2]
        f = open(outFile, "w")
        for i in range(len(allFrequentItemSet)):
            for x in allFrequentItemSet[i]:
                f.write(str(list(x)) +" freq -->"+ str(freqSet[x]) +"\n")
        f.close()



    print(patterns, 'patterns > minsupport found')
    print('Run time', end - start, 'seconds')



if __name__ == "__main__":

    inputFile = sys.argv[1]
    minSupport = int(sys.argv[3])
    Database = []
    try:

        with open(inputFile, 'r') as f:

            Database = [set([i.rstrip() for i in line.split('\t')]) for line in f]

    except IOError:
        print("File Not Found")
        quit()

    runApriori(Database, minSupport)
