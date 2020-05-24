#ifndef ALGORITHMS_GRAPH_H
#define ALGORITHMS_GRAPH_H

#include "LinkedList.h"
#include "Exceptions.h"

class Graph{
protected:
    LinkedList<int> *graph;
    int v_size;

    bool findEdge(int v, int w) {
        if(graph[v-1].getListSize() == 0) {
            return false;
        }
        node<int> *tmp = graph[v-1].getListHead();
        while(tmp->next != nullptr) {
            if(tmp->data == w) {
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }
public:
    explicit Graph(int v) {
        graph = new LinkedList<int>[v];
        v_size = v;
    }
    virtual ~Graph() { delete[] graph; }

    virtual void addEdge(int v, int w) = 0;
    void BFS(int src);
};


class UnDirectedGraph : public Graph {
public:
    explicit UnDirectedGraph(int v) : Graph(v) {}

    void addEdge(int v, int w) override {
        if(findEdge(v, w) || findEdge(w, v)) {
            throw AlreadyExistException();
        }
        graph[v-1].addNode(w);
        graph[w-1].addNode(v);
    };
};


class DirectedGraph : public Graph {
public:
    explicit DirectedGraph(int v) : Graph(v) {}

    void addEdge(int v, int w) override {
        if(findEdge(v, w)) {
            throw AlreadyExistException();
        }
        graph[v-1].addNode(w);
    };
};

#endif //ALGORITHMS_GRAPH_H
