#pragma once
#include <iostream>
#include <string>

#include "Graph.h"
using std::string;

void BFSUtil(int v, vector<bool> visited, Graph obj1);
bool isSC(Graph obj, const string& d);
void distance(int v, Graph obj1);