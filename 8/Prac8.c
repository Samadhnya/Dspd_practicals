#include <stdio.h>
#define MAX 20

int root[MAX];

int findSet(int x) {
    while (root[x] != -1) {
        x = root[x];
    }
    return x;
}

void doUnion(int x, int y) {
    int p = findSet(x);
    int q = findSet(y);
    root[p] = q;
}

int main() {
    int vertices;
    int graph[MAX][MAX];
    int i, j, a, b;
    int totalCost = 0, edgeCount = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = 999;
        }
    }

    for (i = 0; i < vertices; i++)
        root[i] = -1;

    printf("The edges of Minimum Spanning Tree are:\n");

    while (edgeCount < vertices) {
        int min = 999;
        a = -1;
        b = -1;

        for (i = 0; i < vertices; i++) {
            for (j = 0; j < vertices; j++) {
                if (graph[i][j] < min) {
                    min = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (findSet(a) != findSet(b)) {
            printf("%d edge (%d,%d) = %d\n", edgeCount++, a + 1, b + 1, min);
            totalCost += min;
            doUnion(a, b);
        }

        graph[a][b] = graph[b][a] = 999;
    }

    printf("Minimum cost = %d\n", totalCost);

    return 0;
}

