def graph_input():
    adjdict = {}

    with open("./adjlist.txt", "r") as f:
        lines = f.readlines()
        for line in lines:
            line = line.strip("\n")
            line = line.split(":")
            src = line[0]
            conn = line[1].split(" ")

            adjdict[src] = conn

    return adjdict
