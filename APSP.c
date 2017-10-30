#include <stdio.h>

#define MAX 105
int graph[MAX][MAX];
int dist[MAX][MAX];
int n, m, x, y, w;

void floyd_warshall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(graph[i][j])	dist[i][j] = graph[i][j];
			else dist[i][j] = MAX;
		}
	}
 
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] && graph[k][j] && dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					dist[j][i] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	while(m--) {
		scanf("%d %d %d", &x, &y, &w);
		graph[x][y] = w;
		graph[y][x] = w;
	}

	floyd_warshall();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(graph[i][j]) printf("%d ", dist[i][j]);
			else printf("%d ", 0);
		}
		printf("\n");
	}
}

/*
Output:
4 4
0 1 3
1 2 2
2 3 1
3 0 2

0 3 0 2 
3 0 2 0 
0 2 0 1 
2 0 1 0 
*/