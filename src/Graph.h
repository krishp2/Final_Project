
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
using std::stack;
using std::list;
using std::vector;
using std::string;

class Graph{
    public:
    Graph();
    Graph(const string& d);
    Graph(int v);
    void clear();
    Graph& operator=(const Graph& other);
    void insertVertex(int k);
    int versize();
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

    void DFSUtil(int v, bool visited[]);

    //void fillStack(bool visited[], int v, std::stack<int> & s );
    
    Graph getTranspose();

    vector<vector<string> >  getEdges();

    list<int>* getAdj();
 
    vector<int> getvertex();

    vector<vector<int> > getadj2();

    void copy(const Graph& other);

    vector<int> sscrowget();

    void sscrowclear();
    
    ~Graph();

    private:
    vector<int> vertex;     //vector for the vertices
    vector<vector<string> > edges;
    vector<vector<int> > adjvect;
    list<int> *adj;
    string data;
    vector<string> row;
    int vertex_c;
    vector<int> sscrow;
};

