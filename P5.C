#include <stdio.h>

#define MAX 20

int main() {
    int n, adj[MAX][MAX];
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int source, u, v, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices\n");
        return 1;
    }

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    if (source < 0 || source >= n) {
        printf("Invalid source vertex\n");
        return 1;
    }

    visited[source] = 1;
    queue[rear++] = source;

    printf("\nBroadcast Tree Edges:\n");

    while (front < rear) {
        u = queue[front++];

        for (v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;

                printf("%d -> %d\n", u, v);
            }
        }
    }

    printf("\nUnreachable vertices: ");

    for (v = 0; v < n; v++) {
        if (!visited[v])
            printf("%d ", v);
    }

    printf("\n");

    return 0;
}