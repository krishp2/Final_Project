#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
using std::list;
using std::vector;
using std::string;

class Graph{
    public:
    void insertVertex(int k);

    list<int> incident(int v);

    bool areAdjacent(int v1, int v2);

    void insertEdge(int v1, int v2, int key);

    private:
    vector<int> vertex;     //vector for the vertices
    list<int> adj;         //doubly linked list for the edges
    list<vector<int> > edges;
};
