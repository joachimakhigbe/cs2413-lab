#include "graph.h"

int has_triangle(Graph* g) {
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = i + 1; j < MAX_NODES; j++) {
            for (int k = j + 1; k < MAX_NODES; k++) {
                if (g->adj[i][j] == 1 &&
                    g->adj[i][k] == 1 &&
                    g->adj[j][k] == 1) {
                    return 1;  // triangle found
                }
            }
        }
    }
    return 0;  // no triangle
}