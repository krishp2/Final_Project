#pragma once
#include <iostream>
#include <string>
#include "BFS.h"
#include "Graph.h"
using std::string;

void Graph::BFS(int start) {

  vector<bool> visited;
  for (int i = 0; i < vertex.size(); i++)
    visited[i] = false;

  list<int> queue;

  visited[start] = true;
  queue.push_back(start);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    std::cout << "Visited " << currVertex << " ";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}