adjlist, visited = {}, []

with open("./adjlist.file", "r", encoding="utf-8") as f:
  for line in f:
    line = line.strip("\n")
    src, conns = line.split(":")
    connlist = []

    for conn in conns.split(" "):
      id, weight = conn.split("|")
      weight = int(weight)
      x = {}
      x[id] = weight
      connlist.append(x)

    adjlist[src] = connlist

source = input("Source node: ")
visited.append(source)


def getMinWeightedPath(nonvisitedConns):
  minValue = 9999
  temp = 0
  for item in nonvisitedConns:
      if list(item.values())[0] < minValue:
          minValue = list(item.values())[0]
          temp = item
  return temp

while len(visited) != len(adjlist):
  for src in visited:
    # find non-visited connections
    nonVisitedConns = []
    for conn in adjlist[src]:
      conn_id = list(conn.keys())[0]
      if conn_id not in visited:
        x = {}
        x[conn_id] = conn[conn_id]
        nonVisitedConns.append(x)

    # find the minimum weighted connection
    if len(nonVisitedConns) != 0:
      shortPath = getMinWeightedPath(nonVisitedConns)
      visited.append(list(shortPath.keys())[0])

print(visited)
