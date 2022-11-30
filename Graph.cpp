
#include "Graph.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "file_read.h"
using std::list;
using std::vector;
using std::string;


Graph::Graph(){

   // data = file_to_string("/Users/divyamarora/Desktop/Final_Project/amazon0302 (1).txt");
    //edges = readEdge(data);

}


void Graph::printadj(){
  
    for(int i = 0 ; i < 26000; i++){
    std::cout<<  adj[i].back()<< std::endl;}
   
}

void Graph::printedge(){
    std::cout<<  "edges" << std::endl;
    for(int i= 0; i<vertex_c; i++){
        
        std::cout<< edges[i][0];
        std::cout<< " -> ";
        std::cout<< edges[i][1] << std::endl;
    
    }
}

void Graph::insertVertex(string k){
    vertex.push_back(k);
}

list<string> Graph::incident(string v){
    list<string> ab;
    return ab;
}

bool Graph::areAdjacent(string v1, string v2){
    return false;
}

void Graph::insertEdge(string k){
    //edges.push_back(k);
}

void Graph::readVertex(){
    string temp;
    for(int i = 0 ; i< 250; i++){
        temp = std::to_string(i);
        insertVertex(temp);
    }
}

void Graph::makeAdj(const string& data){
    string temp = "";
    string t;
    string first;
    string adjtemp = "";
    list<string> ab;
     for (int i=0; i<= data.size() ; i++){
        if (data[i] == '\t'){
           break;
        }
        first = first+ data[i];
        
     }
     std::cout<< first << std::endl;
     ab.push_back(t);
     adjtemp = first;
     temp = adjtemp;
    for (int i=0; i<= data.size() ; i++){
        if (data[i]!='\t' && data[i]!='\n'){
            t = t+ data[i];
        }
        else if(data[i]== '\t' ){
            if(adjtemp != t){
                adj.push_back(ab);
                ab.clear();
                ab.push_back(t);
                adjtemp = t;
                temp = t;
            }
            t = "";
        }
        else if(data[i]== '\n'){
            //ab.push_back(t);
            ab.push_back(temp + "_" + t);
            t="";
        }
    }
}

void Graph::readEdge(const string& data){
    
    string temp = "";
    string t = "";
    vertex_c = 0;
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
            vertex_c++;
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

vector<list<string> > Graph::getAdj(){
    return adj;
}
