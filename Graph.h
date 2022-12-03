
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

    Graph();

    void insertVertex(string k);

    list<string> incident(string v);

    bool areAdjacent(string v1, string v2);

    void insertEdge(string k);

    /* 
    *
    *
    */
    void readVertex();

    /* 
    *
    *
    */
    void readEdge(const string& data);

    void makeAdj(const string& data);

    void printedge();

    void printadj();

    vector<vector<string> >  getEdges();

    vector<list<string> > getAdj();

    private:
    vector<string> vertex;     //vector for the vertices
    vector<list<string> >adj;        //doubly linked list for the edges
    vector<vector<string> > edges;
    string data;
    vector<string> row;
    int vertex_c;
};

