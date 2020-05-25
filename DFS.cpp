#include <iostream>
#include "Graph.h"

#define V_START 1
#define V_FOUND_NUM 0
#define V_RETREAT_NUM 1

static int counter = 1;

void printDFS(int **find_retreat, int size);


void Graph::DFSVisited(int v, bool visited[], int **find_retreat) {
    visited[v-1] = true;
    if(find_retreat[V_FOUND_NUM][v-1] == 0) {
        find_retreat[V_FOUND_NUM][v - 1] = counter;
        counter++;
    } else if(find_retreat[V_RETREAT_NUM][v-1] == 0) {
        find_retreat[V_RETREAT_NUM][v-1] = counter;
        counter++;
        return;
    }
    node<int> *it = graph[v-1].getListHead();
    while(it != nullptr) {
        if(!visited[it->data-1]) {
            DFSVisited(it->data, visited, find_retreat);
        }
        if(find_retreat[V_RETREAT_NUM][v - 1] == 0) {
            find_retreat[V_RETREAT_NUM][v - 1] = counter;
            counter++;
        }
        it = it->next;
    }
}

void Graph::DFS() { // TODO: add finding time and retreat time
    bool dfs_visited[v_size] = {0};
    int **dfs_find_retreat = new int*[2];
    for(int i=0 ; i < 2 ; i++) {
        dfs_find_retreat[i] = new int[v_size];
        for(int j=0 ; j < v_size ; j++) {
            dfs_find_retreat[i][j] = 0;
        }
    }


    for(int i=V_START ; i <= v_size ; i++) {
        DFSVisited(i, dfs_visited, dfs_find_retreat);
    }
    printDFS(dfs_find_retreat, v_size);
}

void printDFS(int **find_retreat, int size) {
    for(int i=0 ; i < size ; i++) {
        std::cout << i+1 << " found time: " << find_retreat[V_FOUND_NUM][i] << std::endl;
        std::cout << i+1 << " retreat time: " << find_retreat[V_RETREAT_NUM][i] << std::endl;
    }
}