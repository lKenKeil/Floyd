#include <stdio.h>

#define V 10
#define INF 99999

void floydWarshall(int graph[V][V]) {
    int i, j, k;

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF && graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

void printShortestPath(int parent[V][V], int start, int end) {
    if (parent[start][end] == -1) {
        printf("%d ", end + 1);
        return;
    }

    printShortestPath(parent, start, parent[start][end]);
    printf("%d ", end + 1);
}

void printResult(int graph[V][V], int start, int end) {
    printf("Floyd-Warshall Algorithm\n");
    printf("Start Node: %d\n", start);
    printf("End Node: %d\n", end);
    printf("Shortest Distance: %d\n", graph[start - 1][end - 1]);

    printf("Shortest Path: %d ", start);
    printShortestPath(graph, start - 1, end - 1);
    printf("\n");
}

int main() {
    int graph[V][V] = {
        {0, 12, 3, 11, INF, INF, INF, INF, INF, INF},
        {1, 0, 3, 4, 5, 7, 8, INF, INF, INF},
        {1, 3, 0, 4, 5, 7, 8, 2, 5, 6},
        {INF, 2, 4, 0, 13, 14, INF, 16, 17, INF},
        {1, INF, INF, INF, 0, 9, INF, 13, INF, 17},
        {INF, INF, INF, INF, INF, 0, 7, 9, INF, 11},
        {INF, INF, INF, INF, INF, INF, 0, INF, 12, 13},
        {INF, INF, INF, INF, 5, INF, INF, 0, 14, 15},
        {INF, INF, INF, INF, INF, INF, INF, INF, 0, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 0}
    };

    int start, end;

    floydWarshall(graph);

    printf("시작 노드를 입력하세요: ");
    scanf("%d", &start);
    printf("목적 노드를 입력하세요: ");
    scanf("%d", &end);

    printResult(graph, start - 1, end - 1);

    return 0;
}
