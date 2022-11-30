
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


void Graph::print(){
  
    for(int i = 0 ; i < 250; i++){
    std::cout<< adj[i].front() << adj[i].back() << std::endl;}
   
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
    string adjtemp = "";
    list<string> ab;
    bool flag = false; 
    for (unsigned i=0; i< data.size(); i++){
        if (data[i]!='\t' && data[i]!='\n'){
            t = t+ data[i];
        }
        else if(data[i]== '\t'){
            if(adjtemp != t){
                adjtemp = t;
                adj.push_back(ab);
                ab.clear();
                ab.push_back(t);
                t = "";
                
            }
            temp = t;
            t = "";
        }
        else if(data[i]== '\n'){
            ab.push_back(t);
            ab.push_back(temp + "_" + t);
            t="";
            temp ="";
        }
    }
}

void Graph::readEdge(const string& data){
    
    string temp = "";
    string t;
    for (unsigned i=0; i< data.size(); i++){
        if (data[i]!='\t' && data[i]!='\n'){
            t = t+ data[i];
        }
        else if(data[i]== '\t'){
            row.push_back(t);
            temp = t;
            t = "";
        }
        else if(data[i]== '\n'){
            row.push_back(t);
            row.push_back(temp + "_" + t);
            edges.push_back(row);
            row.clear();
            t="";
            temp ="";
        }
    }
}   

