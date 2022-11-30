
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
    
    for(int i = 0 ; i < 20000; i++){
        for(int j =0 ; j< 3; j++){
        std::cout<< edges[i][j] << std::endl;}
}
    
    
    /*
    list< vector<string> >::iterator list_it;
    vector<string>::iterator vec_it;
    for (list_it = edges.begin(); list_it != edges.end(); ++ list_it){
     for (vec_it = list_it->begin(); vec_it != list_it->end(); ++ vec_it)
     {
          //do something with vec_it
          //for example call member function of Class
          std::cout<< (*vec_it) << std::endl;
     } }*/
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

void Graph::makeAdj(){
    int j;
    list<string> temp;
    for(int i =0 ; i < 262111; i++){
        temp.push_back(edges[i][0]);
        j = i;
        while(edges[i][0] == edges[j][0] && i < 262111){
            temp.push_back(edges[i][2]);
            i++;
            std::cout<< i << std::endl;
        }
       i--;
        std::cout<< "help" << std::endl;
       adj.push_back(temp);
    }
}

/*
void Graph::makeAdj(){
    list< vector<string> >::iterator list_it;
    list< vector<string> >::iterator temp;
    temp = edges.begin();
    int i = 0;
    for (list_it = edges.begin(); list_it != edges.end(); list_it++)
    {
            adj[i].push_back(list_it[0]);
            temp = list_it;
            while(list_it[0] == temp[0]){
                adj[i].push_back(list_it[2]);
                list_it++;
                i++;
        }
        list_it--;
    }
}
*/
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

