#include "graph.h"

int count_isolated(Graph* g) {
    int count = 0;

    for (int i = 0; i < MAX_NODES; i++) {
        int isolated = 1;  // assume node is isolated

        for (int j = 0; j < MAX_NODES; j++) {
            if (g->adj[i][j] != 0) {
                isolated = 0;  // found an edge
                break;
            }
        }

        if (isolated) {
            count++;
        }
    }

    return count;
}