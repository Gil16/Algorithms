#include <iostream>
#include "Graph.h"
#include "Queue.h"

void Graph::BFS(int src){
    if(src < 0 || src > v_size) {
        throw InvalidInputException();
    }
    if(graph[src-1].getListSize() == 0) {
        return; // no edges, return empty tree
    }
    auto *bfs_queue = new Queue<int>();
    bool bfs_visited[v_size] = {0};

    bfs_queue->enqueue(src);
    bfs_visited[src-1] = true;
    std::cout << src << std::endl;

    while(!bfs_queue->empty()) {
        int v = bfs_queue->getFront()->data;
        node<int> *it = graph[v-1].getListHead();
        if(!it->next) {
            bfs_queue->dequeue();
            continue;
        }

        while(it != nullptr) {
            if(!bfs_visited[it->data-1]) {
                bfs_visited[it->data-1] = true;
                bfs_queue->enqueue(it->data);
                std::cout << it->data << " ";
            }
            it = it->next;
        }
        bfs_queue->dequeue();
        std::cout <<  std::endl;
    }
}