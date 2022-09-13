from typing import Dict, List

visited: List[str] = []
adjlist: Dict[str, List[Dict[str, int]]] = {}

with open("./adjspanning.txt", "r", encoding="utf-8") as f:
    for line in f:
        line = line.strip("\n")
        line = line.split(":")
        src = line[0]
        conns = line[1].split(" ")
        tempList=[]
        for conn in conns:
            # print(conn)
            x={}
            temp=conn.split(',')
            # print(temp)
            x[temp[0]]=int(temp[1])
            tempList.append(x)
        adjlist[src]=tempList

def getMinWeightedPath(nonvisitedConn):
    minValue=9999
    temp=0
    for item in nonvisitedConn:
        if list(item.values())[0]<minValue:
            minValue=list(item.values())[0]
            temp=item
    return temp

src = input("Source node: ")
visited.append(src)

while visited != adjlist.keys():
    for src in visited:
        nonvisitedConn = []
        for node in adjlist[list(src.keys())[0]]:
            if list(node.keys())[0] not in visited:
                nonvisitedConn.append(node)
        shortestPath = getMinWeightedPath(nonvisitedConn)
        visited.append(list(shortestPath.keys())[0])
