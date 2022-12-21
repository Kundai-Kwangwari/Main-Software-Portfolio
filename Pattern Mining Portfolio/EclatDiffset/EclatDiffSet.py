import sys
import time

# trans_set will store all the tids
trans_set = set()
# diffSets stores the values of the supp and differences
frequentItems = {}


def getUniqueItemList(iFile, minSup):
    tidSets = {}
    uniqueItem = []
    try:

        with open(iFile, 'r') as transactionDB:
            transNum = 0
            for transaction in transactionDB:
                transNum += 1
                trans_set.add(transNum)
                for item in transaction.rstrip().replace(",", " ").split('\t'):
                    if item in tidSets:
                        tidSets[item].add(transNum)
                    else:
                        tidSets[item] = {transNum}
            transactionDB.close()
    except IOError:
        print("File Not Found")
        quit()

    for key, value in tidSets.items():
        supp = len(value)
        if supp >= minSup:
            frequentItems[key] = [supp, trans_set.difference(value)]
            uniqueItem.append(key)

    uniqueItem.sort(key=int)
    return uniqueItem


def runEclatDiffset(candidateList, minSup):

    new_freqList = []
    for i in range(0, len(candidateList)):
        item1 = candidateList[i]
        i1_list = item1.split()
        for j in range(i + 1, len(candidateList)):
            item2 = candidateList[j]
            i2_list = item2.split()
            if i1_list[:-1] == i2_list[:-1]:
                union_DiffSet = frequentItems[item2][1].difference(frequentItems[item1][1])
                union_supp = frequentItems[item1][0] - len(union_DiffSet)
                if union_supp >= minSup:
                    newKey = item1 + " " + i2_list[-1]
                    frequentItems[newKey] = [union_supp, union_DiffSet]
                    new_freqList.append(newKey)
            else: break

    if len(new_freqList) > 0:
        runEclatDiffset(new_freqList, minSup)

def writeResults(oFile):

    count = 0
    with open(oFile, 'w') as f:
        for pattern in frequentItems.keys():
            count += 1
            print(count, pattern)

            f.write(pattern)
            f.write("\n")

    f.close()

if __name__ == "__main__":

    iFile = sys.argv[1]
    oFile = sys.argv[2]
    minSup = int(sys.argv[3])
    for i in range(0,6):
        start = time.time()
        uniqueItemList = getUniqueItemList(iFile, minSup)
        runEclatDiffset(uniqueItemList, minSup)
        end = time.time()
        #writeResults(oFile)
        Runtime = end - start
    print("\nTotal patterns found:", len(frequentItems.keys()), '\nminSup', minSup, 'Run time', Runtime, 'seconds')