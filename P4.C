#include <stdio.h>

#define MAX 20
#define INF 999999

int main() {
    int n, cost[MAX][MAX];
    int dist[MAX], visited[MAX] = {0};
    int source, i, j, count, u, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices\n");
        return 1;
    }

    printf("Enter adjacency matrix (0 means no edge):\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] < 0) {
                printf("Negative weights are not allowed\n");
                return 1;
            }

            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    if (source < 0 || source >= n) {
        printf("Invalid source vertex\n");
        return 1;
    }

    for (i = 0; i < n; i++)
        dist[i] = cost[source][i];

    dist[source] = 0;

    for (count = 0; count < n - 1; count++) {
        min = INF;
        u = -1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && cost[u][j] != INF &&
                dist[u] != INF &&
                dist[u] + cost[u][j] < dist[j]) {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("Vertex %d: Unreachable\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }

    return 0;
}