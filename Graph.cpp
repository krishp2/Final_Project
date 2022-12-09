
#include "Graph.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "file_read.h"
#include <fstream>
using std::list;
using std::vector;
using std::string;


Graph::Graph(int v, const string& data){
    vertex_c = v;
    adj = new list<int>[v];
    makeadj2(data);
    //readEdge(data);
    readVertex(data);
}
Graph::Graph(int v){
    vertex_c = v;
    adj = new list<int>[v];
}

Graph::~Graph() { 
    //if (adj != NULL){
        //delete [] adj;
       // adj = NULL; }
}


void Graph::printadj(){
    std::ofstream myfile;
    myfile.open ("/workspaces/cs225/Final_Project/output/tpep");
    list<int>::iterator i;
    //std::cout<< vertex_c << std::endl;
    //std::cout<< vertex.size() << std::endl;
    for (int v = 0; v < vertex.size(); v++)
    {
       //std::cout << v << std::endl;
       //myfile << v << " -> ";
       std::cout << vertex[v] << " -> ";
        for (i = adj[vertex[v]].begin(); i != adj[vertex[v]].end(); ++i){
            std::cout<< ' ' << *i;
            //myfile << ' ' << *i;
        }
            std::cout<< std::endl;
            //myfile << std::endl;
    }
    myfile.close();
}

void Graph::printedge(){
    std::ofstream myfile;
   // myfile.open ("/workspaces/cs225/Final_Project/output/edges_output");
    
    
    for(int i= 0; i<vertex_c; i++){
        myfile << edges[i][0];
        myfile <<  " -> ";
        myfile <<  edges[i][1] << std::endl;
    
    }
    myfile.close();
}

void Graph::insertVertex(int k){
    vertex.push_back(k);
}

list<string> Graph::incident(string v){
    list<string> ab;
    return ab;
}

bool Graph::areAdjacent(string v1, string v2){
    return false;
}

void Graph::insertEdge(int v, int w){
    adj[v].push_back(w);
}

Graph Graph::getTranspose()
{
    std::cout << "Reached line " << __LINE__ << std::endl;
    //std::cout<< vertex_c <<std::endl;
	Graph g(vertex_c);
	for (int v = 0; v < vertex_c; v++)
	{
		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
            //std::cout << ' ' << *i;
            //std::cout<< std::endl;
			g.adj[*i].push_back(v);
	}
	return g;
}


void Graph::makeadj2(const string& data){
    string t;
    string first;
    string adjtemp = "";
    list<int> ab;
    //pushes the first vertex in the list;
    for (int i=0; i<= data.size() ; i++){
        if (data[i] == '\t'){
           break;}
        first = first+ data[i];
     }

    adjtemp = first;
    
    for (int i=0; i< data.size() ; i++){

        if (data[i]!='\t' && data[i]!='\n'){
            t = t+ data[i];
        }
        else if(data[i]== '\t' ){
            if(adjtemp != t){
                adjtemp = t;
            }
            t = "";
        }
        else if(data[i]== '\n'){
            int verint = stoi(adjtemp);
            int edgeint = stoi(t);
    
            insertEdge(verint, edgeint);
    
            t="";
        }

    }
}


void Graph::readVertex(const string& data){
    string t = "";
    //vertex_c = 0;
    string first;
    string adjtemp = "";

    for (int i=0; i<= data.size() ; i++){
        if (data[i] == '\t'){
           break;}
        first = first+ data[i];
     }

    adjtemp = first;
    int verint = stoi(adjtemp);
    vertex.push_back(verint);
    for (int i=0; i< data.size(); i++){
        if (data[i]!='\t' && data[i]!='\n'){
            t = t+ data[i];
        }
        else if(data[i]== '\t'){
            if(adjtemp != t){
            verint = stoi(t);
            vertex.push_back(verint);
            adjtemp = t;
            }
            t = "";
        }
        if(data[i] == '\n'){
            t = "";
        }
    }
}

void Graph::readEdge(const string& data){
    
    string temp = "";
    string t = "";
    for (int i=0; i< data.size(); i++){
        if (data[i]!='\t' && data[i]!='\n'){
            //std::cout << i ;
            t = t+ data[i];

        }
        else if(data[i]== '\t'){
            //std::cout<< t<<  "h" <<std::endl;
            row.push_back(t);
            temp = t;
            t = "";
        }
        else if(data[i]== '\n'){
     
            row.push_back(t);
            //std::cout << i << "h" ;
            //std::cout<< row[i] << std::endl;
            row.push_back(temp + "_" + t);
            edges.push_back(row);
            row.clear();
            t="";
            temp ="";
        }
    }

}   

vector<vector<string> >  Graph::getEdges(){
    return edges;
}

list<int>* Graph::getAdj(){
    return adj;
}


vector<int>  Graph::getvertex(){
    return vertex;
}
