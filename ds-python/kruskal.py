edgePairs: list[str] = []
edgeWeights: list[int] = []
vertset: list[str] = []

def sortEdgePairs():
    for k in range(len(edgeWeights)):
        for i in range(len(edgeWeights)):
            if edgeWeights[k] <= edgeWeights[i]:
                tmp1 = edgeWeights[i]
                edgeWeights[i] = edgeWeights[k]
                edgeWeights[k] = tmp1

                tmp2 = edgePairs[i]
                edgePairs[i] = edgePairs[k]
                edgePairs[k] = tmp2


# eg. pair: "ab", "bc"
def createPair(pairstring: str, weight: int):
    if pairstring[::-1] in edgePairs:
        return
    edgePairs.append(pairstring)
    edgeWeights.append(weight)

with open("adjlist2.file", "r", encoding="utf-8") as f:
    for line in f:
        line = line.strip("\n")
        src, conns = line.split(":")
        vertset.append(src)

        for conn in conns.split(" "):
            id, weight = conn.split("|")
            createPair(src+id, int(weight))

sortEdgePairs()

resultList: list[str] = []
def partChecker(lst: list[str], pair: str):
    flag = False
    for item in lst:
        if pair in item:
            flag = True
            break
    
    if flag is False:
        resultList.append(pair)

        #TODO: merge pairs
        #return new_list

for edge in edgePairs:
    partChecker(vertset, edge)

print(resultList)
