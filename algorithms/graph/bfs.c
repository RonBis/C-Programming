#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vert_count = 0;

typedef struct AdjConn {
    char src;
    char *conns;
    int conns_count;
} adjconn;

adjconn *adjlist;
adjconn getConnections(char src) {
    for (int i = 0; i < vert_count; i++) {
        if (adjlist[i].src == src) {
            return adjlist[i];
        }
    }
}

char *queue;
int qfront = -1, qrear = 0;
void enqueue(char nd) {
    queue[qrear] = nd;
    qrear++;
    if (qfront == -1) qfront++;
}
char dequeue() {
    char popped = queue[qfront];
    qfront++;
    return popped;
}

int main() {
    FILE *fp = fopen("./src/undirected2.graph", "r");
    adjlist = (adjconn *)malloc(sizeof(adjconn));
    char *visited;
    int visited_count = 0;

    char *lines, line[100], ch;
    while ((ch = getc(fp)) != EOF) {
        // here getc() seeks fp by +1,
        // so the src gets stored in ch
        fgets(line, 100, fp);

        long line_length = strlen(line);
        int conn_count = 0;
        for (int i = 0; i < line_length - 1; i++) {
            if (line[i + 1] == ' ') conn_count++;
            line[i] = line[i + 1];
        }

        // remove newline character from end of string
        // and colon(:) at front
        line[line_length - 2] = '\0';
        // 1 space means 2 connections
        conn_count++;

        char *conns = (char *)malloc(conn_count * sizeof(char));
        for (int i = 0; i < conn_count; i++) {
            conns[i] = line[i * 4];
        }

        adjlist =
            (adjconn *)realloc(adjlist, (vert_count + 1) * sizeof(adjconn));
        vert_count++;
        adjlist[vert_count - 1] =
            (adjconn){.src = ch, .conns = conns, .conns_count = conn_count};
    }

    // for (int i = 0; i < vert_count; i++) {
    //     printf("src=%c, conns=%s\n", adjlist[i].src, adjlist[i].conns);
    // }

    char source;
    printf("Source node: ");
    scanf("%c", &source);

    queue = (char *)malloc(vert_count * sizeof(char));
    visited = (char *)malloc(vert_count * sizeof(char));
    visited[0] = source;
    visited_count++;
    enqueue(source);

    while ((qrear - qfront) > 0) {
        char src = dequeue();
        printf("%c\t", src);
        adjconn adjconns = getConnections(src);

        for (int i = 0; i < adjconns.conns_count; i++) {
            char conn = adjconns.conns[i];
            bool isVisited = false;

            for (int j = 0; j < visited_count; j++) {
                if (conn == visited[j]) {
                    isVisited = true;
                    break;
                }
            }
            if (!isVisited) {
                visited[visited_count++] = conn;
                enqueue(conn);
            }
        }
    }

    // free(adjlist);
    // free(queue);
    fclose(fp);
    printf("\n");

    return 0;
}
