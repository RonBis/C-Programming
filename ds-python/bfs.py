import graph_input

adjlist = graph_input.graph_input()
queue, visited = [], []

# adjList = {"a": [], "b": [], "c": [], "d": [], "e": []}

# let there be 5 nodes
# for item in list(adjList.keys()):
#     x=input(f'Connections of {item}: ').split(" ")
#     adjList[item]=[item for item in x if lambda element: element in 'abcde']

src = input("Source node: ")
visited.append(src)
queue.append(src)

while len(queue) > 0:
    nd = queue.pop(0)
    print(f'{nd}\t')

    for item in adjlist[nd]:
        if item not in visited:
            visited.append(item)
            queue.append(item)
