//shortest path using dijkstra algorithm

#include <stdio.h>
#include <limits.h>

#define V 6 // Number of vertices

// Mapping: a=0, b=1, c=2, d=3, e=4, z=5
char nodes[] = {'a', 'b', 'c', 'd', 'e', 'z'};

// Find the vertex with the minimum distance
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

// Print path using parent[]
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%c", nodes[j]);
        return;
    }
    printPath(parent, parent[j]);
    printf(" -> %c", nodes[j]);
}

// Print distance and path from source
void printSolution(int dist[], int parent[], int src) {
    printf("Vertex\tDist\tPath\n");
    for (int i = 0; i < V; i++) {
        printf("%c\t%d\t", nodes[i], dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}

// Dijkstra's algorithm with path tracking
void dijkstra(int graph[V][V], int src) {
    int dist[V];         // shortest distance from src
    int visited[V];      // visited set
    int parent[V];       // to store path tree

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, src);
}

int main() {
    int graph[V][V] = {
        // a  b  c  d  e  z
        { 0, 4, 0, 2, 0, 0 }, // a
        { 4, 0, 3, 0, 0, 0 }, // b
        { 0, 3, 0, 0, 0, 2 }, // c
        { 2, 0, 0, 0, 3, 0 }, // d
        { 0, 0, 0, 3, 0, 1 }, // e
        { 0, 0, 2, 0, 1, 0 }  // z
    };

    dijkstra(graph, 0); // Start from 'a' (index 0)
    return 0;
}
