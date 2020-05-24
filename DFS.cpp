#include <iostream>
#include "Graph.h"

#define V_START 1

void Graph::DFSVisited(int v, bool visited[]) {
    visited[v-1] = true;
    std::cout << v << " ";
    node<int> *it = graph[v-1].getListHead();
    while(it != nullptr) {
        if(!visited[it->data-1]) {
            DFSVisited(it->data, visited);
        }
        it = it->next;
    }
}


void Graph::DFS() { // TODO: add finding time and retreat time
    bool dfs_visited[v_size] = {0};
    DFSVisited(V_START, dfs_visited);   // loop through all v ?
}