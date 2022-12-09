
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

    Graph(int v, const string& d);
    Graph(int v);
    void insertVertex(int k);

    list<string> incident(string v);

    bool areAdjacent(string v1, string v2);

    void insertEdge(string v, string w);

    /* 
    *
    *
    */
    void readVertex(const string& data);

    /* 
    *
    *
    */
    void readEdge(const string& data);

    void makeAdj(const string& data);

    void printedge();

    void printadj();

    void insertEdge(int v, int w);

    void makeadj2(const string& data);

    vector<vector<string> >  getEdges();

    list<int>* getAdj();
 
    vector<int> getvertex();

    Graph getTranspose();

    ~Graph();

    private:
    vector<int> vertex;     //vector for the vertices
    //vector<list<string> >adj;        //doubly linked list for the edges
    vector<vector<string> > edges;
    list<int> *adj;
    string data;
    vector<string> row;
    int vertex_c;
};

