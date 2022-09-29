#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge {
  char id;
  char cost;
} edge;

typedef struct AdjConn {
  char src;
  edge *conns;
  int conns_count;
} adjconn;

adjconn *adjlist;
char *visited;
int visited_count = 0;
int vert_count = 0;

bool checkIfVertInVisited(int vert_id) {
  for (int i = 0; i < visited_count; i++) {
    if (visited[i] == vert_id)
      return true;
  }
  return false;
}

char findMinCostConn(char src) {
  for (int i = 0; i < vert_count; i++) {
    if (adjlist[i].src == src) {
      // Got the edges from the source
      // iterate over each edges
      adjconn edges = adjlist[i];

      int min_cost = 9999;
      char min_cost_edge_id;
      for (int j = 0; j < edges.conns_count; j++) {
        edge edge = edges.conns[j];
        // if visited, skip iteration
        if (checkIfVertInVisited(edge.id))
          continue;

        if (edge.cost < min_cost) {
          min_cost = edge.cost;
          min_cost_edge_id = edge.id;
        }
      }
      // found the edge with minimum cost
      return min_cost_edge_id;
    }
  }
}

int main() {
  FILE *fp = fopen("./adjlist.file", "r");
  adjlist = (adjconn *)malloc(sizeof(adjconn));

  char *lines, line[100], ch;
  while ((ch = getc(fp)) != EOF) {
    fgets(line, 100, fp);
    int conn_count = 0;

    long line_length = strlen(line) - 1;
    for (int i = 0; i < line_length; i++) {
      if (line[i] == ' ')
        conn_count++;
      line[i] = line[i + 1];
    }

    line[line_length - 1] = '\0';
    conn_count++;

    edge *conns = (edge *)malloc(conn_count * sizeof(edge));
    for (int i = 0; i < conn_count; i++) {
      conns[i] = (edge){.id = line[i * 4], .cost = line[i * 4 + 2]};
    }

    vert_count++;
    adjlist = (adjconn *)realloc(adjlist, vert_count * sizeof(adjconn));
    adjlist[vert_count - 1] =
        (adjconn){.src = ch, .conns = conns, .conns_count = conn_count};
  }

  char source;
  printf("Source node: ");
  scanf("%c", &source);

  visited = (char *)malloc(vert_count * sizeof(char));
  visited[0] = source;
  visited_count++;

  for (int i = 0; i < visited_count; i++) {
    char src = visited[i];
    printf("%c\t", src);

    visited_count++;
    if (visited_count == vert_count + 1)
      break;
    visited[i + 1] = findMinCostConn(src);
  }

  printf("\n");
  return 0;
}
