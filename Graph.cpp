#pragma once
#include 'Graph.h'
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;

Graph::Graph(){
    list<string> *adj;
    list<vector<string> > edges;
}
void Graph::insertVertex(int k){
    vertex.push_back(k);
}

list<int> Graph::incident(int v){
    return 
}

bool Graph::areAdjacent(int v1, int v2){
    

}

void Graph::insertEdge(int k){
    edge.push_back(k);
    //add pointer to v1 adj
    //to v2 adj
}
