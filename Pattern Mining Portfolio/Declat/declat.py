import sys
import itertools
import time
import matplotlib.pyplot as plt
import numpy as np

def getUniqueItem(Database,negMinSup):

    startGetUnique = time.time()
    universalSet = set()
    tempUniqueItemDic = {}
    uniqueItem = {}
    trans_Num = 0
    for transaction in Database:
        trans_Num +=1
        universalSet.add(trans_Num)
        for item in transaction:
            if item in tempUniqueItemDic:
               tempUniqueItemDic[item].add(trans_Num)
            else:
                tempUniqueItemDic[item] = {trans_Num}


    for key, value in tempUniqueItemDic.items():

        if len(value) >= negMinSup:
            Diffvalue = universalSet.difference(value)
            #print(len(Diffvalue))
            for k in Diffvalue:
                if key in uniqueItem:
                    uniqueItem[key].add(k)
                else:
                    uniqueItem[key] = {k}
    endGetUnique = time.time()
    print('getUnique runtime:',endGetUnique - startGetUnique)
    return uniqueItem

def generateKeys(nextKeyList, length,freqItemsDic,negMinSup):


    newKeySet = set()
    for L in range(0, 1):
        for subset in itertools.combinations(nextKeyList, length):
            subsetList = sorted(list(subset))
            key1 = tuple(subsetList[0:length - 1])

            if key1 in freqItemsDic:
                key2 = []
                for i in range(0,length - 2):
                    key2.append(subsetList[i])
                key2.append(subsetList[-1])
                key2 = tuple(key2)
                if key2 in freqItemsDic:
                    diff1 = set(freqItemsDic[key1]).difference(freqItemsDic[key2])
                    diff2 = set(freqItemsDic[key2]).difference(freqItemsDic[key1])
                    DiffList = diff1.union(diff2)
                    tempInterDiffList = set(freqItemsDic[subsetList[0]]).union(DiffList)
                    if len(Database) - len(tempInterDiffList) >= negMinSup:
                        for i in range(len(subsetList)):
                            newKeySet.add(subsetList[i])
                        freqItemsDic[tuple(subsetList)] = tempInterDiffList

    return newKeySet




def runEclat(Database, negMinSup):

    runTimeList = []
    minSupList = []
    for negMinSup in range(15, 18, 5):
        start = time.time()
        freqItemsDic = {}
        freqItemsDic = getUniqueItem(Database,negMinSup)

        keyList = sorted(list(freqItemsDic.keys()))
        nextKeySet = set()
        length = 2
        for L in range(0, 1):
            for subset in itertools.combinations(keyList, length):
                subsetList = sorted(list(subset))
                diff1 = set(freqItemsDic[subsetList[0]]).difference(freqItemsDic[subsetList[1]])
                diff2 = set(freqItemsDic[subsetList[1]]).difference(freqItemsDic[subsetList[0]])
                DiffList = diff1.union(diff2)
                tempInterDiffList = set(freqItemsDic[subsetList[0]]).union(DiffList)
                if len(Database) - len(tempInterDiffList) >= negMinSup:
                    for i in range(len(subsetList)):
                        nextKeySet.add(subsetList[i])
                    freqItemsDic[tuple(subsetList)] = tempInterDiffList
        print(len(freqItemsDic.keys()))
        end = time.time()
        print('minSup', negMinSup, 'Run time', end - start, 'seconds')

        while(1):
            length += 1
    
            nextKeySet = generateKeys(sorted(list(nextKeySet)),length,freqItemsDic,negMinSup)
            if len(nextKeySet) == 0:
                break
        end = time.time()
        print(len(freqItemsDic.keys()))
        Runtime = end - start
        runTimeList.append(Runtime)
        minSupList.append(negMinSup)

    count = 0


    plt.plot(minSupList, runTimeList, marker = '*')
    plt.title("Kundai: declat")
    plt.xlabel("minSupport")
    plt.ylabel("RunTime(s)")
    plt.show()




if __name__ == "__main__":

    inputFile = sys.argv[1]

    Database = []
    try:

        with open(inputFile, 'r') as f:

            Database = [set([i.rstrip() for i in line.split('\t')]) for line in f]

    except IOError:
        print("File Not Found")
        quit()

    negMinSup = 3000
    runEclat(Database, negMinSup)
