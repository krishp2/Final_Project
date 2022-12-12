#pragma once
#include <iostream>
#include <string>
using std::pair;
#include "Graph.h"
using std::string;

//void BFSUtil(int v, vector<bool> visited, Graph obj1);
bool isSC(Graph obj, const string& d);
vector<int> distance(int v, Graph& obj1);
vector<vector<int> >  scc(Graph o);
vector<pair<int, double> > pageRank(double n, Graph obj);
void print_rank(vector<pair<int, double> > frank );
void fillStack(bool visited[], int v, std::stack<int> & s, Graph& g );
void printscc(Graph& obj);