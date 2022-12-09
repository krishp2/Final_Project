#include <iostream>
#include <string>
#include <fstream>
#include "BFS.h"
#include "Graph.h"
#include "file_read.h"
using std::string;
#include <bits/stdc++.h>
int V = 262211;



void distance(int v, Graph obj1)
{
  vector<int> vertex;
  vertex = obj1.getvertex();
 
    list<int>* adj = obj1.getAdj();
    vector<int> distance(vertex.size(), -1);
	  list<int> queue;
    distance[v] =0;
   
    int dist = 0;
    queue.push_back(v);
    std::ofstream myfile;
    myfile.open ("/workspaces/cs225/Final_Project/output/tpep");
    list<int>::iterator i;
    while (!queue.empty())
    {
        // Dequeue a vertex from queue
        v = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it
        // visited and enqueue it
         dist = dist +1;
        
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
        //std::cout << *i  << std::endl;
            if (distance[*i] == -1)
            {
                distance[*i] = dist;
                queue.push_back(*i);
            }
        }
      myfile << v << " at level " << distance[v] <<'\n';
    }
    myfile.close();
  
}


void BFSUtil(int v, bool visited[], Graph obj1)
{
  //string d = file_to_string("/workspaces/cs225/Final_Project/amazon0302 (1).txt");
  //Graph obj1(262211);
  //obj1.makeadj2(d);
  //obj1.readVertex(d);
  //vector<string> vertex = obj1.getvertex();
  //vector<bool> visited(262211,false);
  list<int>* adj = obj1.getAdj();

	 list<int> queue;
   
    // Mark the current node as visited and enqueue it
    visited[v] = true;
    
    queue.push_back(v);

    // 'i' will be used to get all adjacent vertices
    // of a vertex
    list<int>::iterator i;

    while (!queue.empty())
    {
        // Dequeue a vertex from queue
        v = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it
        // visited and enqueue it
         
        
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
        //std::cout << *i  << std::endl;
        
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
         
        }
        
        
    }
  
}

bool isSC(Graph obj, const string& d)
{
	// Step 1: Mark all the vertices as not
	// visited (For first BFS)
	//vector<bool> visited(V,false);
  bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
	BFSUtil(0, visited, obj);
 std::cout << "Reached line " << __LINE__ << std::endl;
	// If BFS traversal doesn’t visit all
	// vertices, then return false.
  std::cout << "Reached line " << __LINE__ << std::endl;
   std::cout << visited[262111] << std::endl;
	for (int i = 0; i < 262110; i++){
    //std::cout << visited[i] << std::endl;
		if (visited[i] == false){
       std::cout << i << std::endl;
			return false;
      }
      
  }
std::cout << "Reached line " << __LINE__ << std::endl;
	// Step 3: Create a reversed graph
	Graph gr(V);
  
  gr = obj.getTranspose();

  gr.printadj();
	// Step 4: Mark all the vertices as not
	// visited (For second BFS)
  
	for(int i = 0; i < V; i++)
		visited[i] = false;

	// Step 5: Do BFS for reversed graph
	// starting from first vertex.
	// Starting Vertex must be same starting
	// point of first DFS
  
	BFSUtil(0, visited, gr);
  
std::cout << "Reached line " << __LINE__ << std::endl;
	// If all vertices are not visited in
	// second DFS, then return false
  
	for (int i = 5; i < 262110; i++){
		if (visited[i] == false){
      std::cout << i << std::endl;
			return false;
      }
    }
  std::cout << "Reached line " << __LINE__ << std::endl;

	return true;
}