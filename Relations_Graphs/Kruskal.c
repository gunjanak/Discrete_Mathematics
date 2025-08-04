//Minimum spanning tree using Kruskal's algorithm
#include <stdio.h>
#include <stdlib.h>

#define V 12 // Number of vertices
#define E 17 // Number of edges

// Edge structure
typedef struct {
    int src, dest, weight;
} Edge;

// Parent array for union-find
int parent[V];

// Find operation
int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

// Union operation
void unionSet(int u, int v) {
    int set_u = find(u);
    int set_v = find(v);
    parent[set_u] = set_v;
}

// Compare function for qsort
int compare(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Map a-l to 0-11
int mapChar(char c) {
    return c - 'a';
}

int main() {
    // List of edges
    Edge edges[E] = {
        {mapChar('c'), mapChar('d'), 1},
        {mapChar('b'), mapChar('f'), 1},
        {mapChar('k'), mapChar('l'), 1},
        {mapChar('c'), mapChar('g'), 2},
        {mapChar('f'), mapChar('j'), 2},
        {mapChar('a'), mapChar('b'), 2},
        {mapChar('b'), mapChar('c'), 3},
        {mapChar('a'), mapChar('e'), 3},
        {mapChar('f'), mapChar('g'), 3},
        {mapChar('g'), mapChar('h'), 3},
        {mapChar('i'), mapChar('j'), 3},
        {mapChar('j'), mapChar('k'), 3},
        {mapChar('h'), mapChar('l'), 3},
        {mapChar('e'), mapChar('f'), 4},
        {mapChar('e'), mapChar('i'), 4},
        {mapChar('g'), mapChar('k'), 4},
        {mapChar('d'), mapChar('h'), 5}
    };

    // Initialize parents
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Sort edges
    qsort(edges, E, sizeof(Edge), compare);

    int mstWeight = 0;
    printf("Edges in the Minimum Spanning Tree:\n");

    int edgeCount = 0;
    for (int i = 0; i < E && edgeCount < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(u) != find(v)) {
            printf("%c - %c (%d)\n", u + 'a', v + 'a', edges[i].weight);
            mstWeight += edges[i].weight;
            unionSet(u, v);
            edgeCount++;
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);

    return 0;
}
