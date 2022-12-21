import sys
import time

#trans_set will store all the tids
trans_set = set()
#diffSets stores the values of the supp and differences
frequentItems = {}

def getUniqueItemList(inputFile,minSup):

    # tidSets will store all the initial tids
    tidSets = {}
    # uniqueItem will store all frequent 1 items
    uniqueItem = []
    try:

        with open(inputFile, 'r') as inputData:
            transNum = 0
            for transaction in inputData:
                transNum += 1
                trans_set.add(transNum)
                for item in transaction.rstrip().replace(",", " ").split(' '):
                    if item in tidSets:
                        tidSets[item].add(transNum)
                    else:
                        tidSets[item] = {transNum}
            inputData.close()
    except IOError:
        print("File Not Found")
        quit()

    for key, value in tidSets.items():
        supp = len(value)
        if supp >= minSup:
            frequentItems[key] = value
            uniqueItem.append(key)

    uniqueItem.sort(key=int)
    return uniqueItem


def writeResults():

    output = 'results.txt'
    count = 0
    with open(output, 'w') as f:
        for key, value in frequentItems.items():
            count += 1
            print(count, ". | Key" ,key, " |Occurences:", value, " | frequency: ", len(value))
            pattern = key + " |Occurences:"+ str(value) + "| frequency: " + str(len(value))

            f.write(pattern)
            f.write("\n")

    f.close()


def runEclat(prev_freqList, minSup):

    new_freqList = []
    for i in range (0, len(prev_freqList)):
        item1 = prev_freqList[i]
        i1_list = item1.split()
        for j in range(i + 1, len(prev_freqList)):
            item2 = prev_freqList[j]
            i2_list = item2.split()
            if i1_list[:-1] == i2_list[:-1]:
                intersect = frequentItems[item2].intersection(frequentItems[item1])
                if len(intersect) >= minSup:
                    newKey = item1 + " " + i2_list[-1]
                    frequentItems[newKey] = intersect
                    new_freqList.append(newKey)
            else: break


    if len(new_freqList) > 0:
        runEclat(new_freqList,minSup)

if __name__ == "__main__":

    inputFile = sys.argv[1]
    minSup = int(sys.argv[3])
    runTimeList = []
    minSupList = []
    start = time.time()
    uniqueItemList = getUniqueItemList(inputFile, minSup)
    runEclat(uniqueItemList, minSup)
    end = time.time()
    writeResults()
    Runtime = end - start
    print(len(frequentItems.keys()))
    runTimeList.append(Runtime)
    minSupList.append(minSup)
    print('minSup', minSup, 'Run time', end - start, 'seconds')
