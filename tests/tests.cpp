//#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <cassert>
#include <fstream>
#include <sstream>
#include <fenv.h>
#include <signal.h>
#include "file_read.h"
#include "Graph.h"
#include "Algorithm.h"
#include <utility>
#include <cmath>
#include <catch2/catch_test_macros.hpp>
using std::pair;
using std::list;


TEST_CASE("Adjcancey list small", "[weight=2]") {
    string data = file_to_string("/workspaces/cs225/Final_Project/testpr1");
    Graph t(data);
    list<int>* a;
    a = t.getAdj();
    int test_count = 1;
    list<int>::iterator i;
    for (i = a[0].begin(); i != a[0].end(); ++i){
        REQUIRE( (*i) == test_count++);
    }
}

TEST_CASE("Adjcancey list large", "[weight=2]") {
    string data = file_to_string("/workspaces/cs225/Final_Project/test_data.txt");
    Graph t(data);
    list<int>* a;
    int test_large[5] = {63, 97, 99, 307, 430};
    a = t.getAdj();
    int ct = 0;
    list<int>::iterator i;
    for (i = a[100].begin(); i != a[100].end(); ++i){
        REQUIRE( (*i) == test_large[ct++]);
    }
}


TEST_CASE("BFS small test", "[weight=2]") {
    string data = file_to_string("/workspaces/cs225/Final_Project/testpr3");
    Graph t(data);
    vector<int> test_dis;
    test_dis = distance(4,t);
    int test[5] = {2,3,4,1,0};
    REQUIRE( test_dis[0] == test[0] );
    REQUIRE( test_dis[1] == test[1] );
    REQUIRE( test_dis[2] == test[2] );
    REQUIRE( test_dis[3] == test[3] );
    REQUIRE( test_dis[4] == test[4] );
}


TEST_CASE("BFS on cycle", "[weight=1]") {
    string data = file_to_string("/workspaces/cs225/Final_Project/testpr2");
    Graph t(data);
    vector<int> test_dis;
    test_dis = distance(0,t);
    int test[3] = {0,1,2};
    REQUIRE( test_dis[0] == test[0] );
    REQUIRE( test_dis[1] == test[1] );
    REQUIRE( test_dis[2] == test[2] );
}

TEST_CASE("BFS no path test", "[weight=2]") {
    string data = file_to_string("/workspaces/cs225/Final_Project/testpr3");
    Graph t(data);
    vector<int> test_dis;
    test_dis = distance(2,t);
    int test[5] = {-1,-1,0,-1,-1};
    REQUIRE( test_dis[0] == test[0] );
    REQUIRE( test_dis[1] == test[1] );
    REQUIRE( test_dis[2] == test[2] );
    REQUIRE( test_dis[3] == test[3] );
    REQUIRE( test_dis[4] == test[4] );
}


TEST_CASE("BFS big data test", "[weight=2]") {
    string data = file_to_string("/workspaces/cs225/Final_Project/amazon0302 (1).txt");
    Graph t(data);
    vector<int> test_dis;
    test_dis = distance(8,t);
    REQUIRE( test_dis[22]  == 1 );
    REQUIRE( test_dis[38]  == 4 );
    REQUIRE( test_dis[87]  == 15 );
}
/*
void testscc(){
	Graph g1(5);
	g1.addEdge(0, 1);
	g1.addEdge(1, 2);
	g1.addEdge(2, 3);
	g1.addEdge(3, 0);
	g1.addEdge(2, 4);
	g1.addEdge(4, 2);
	g1.isSC()? cout << "Yes\n" : cout << "No\n";

	Graph g2(4);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 3);
	g2.isSC()? cout << "Yes\n" : cout << "No\n";
}*/


TEST_CASE("PageRank works with simple data and small n") {
    string d = file_to_string("/workspaces/cs225/Final_Project/testpr1");
    Graph obj(d);
    vector<pair<int, double> > finalrank = pageRank(4, obj);
    REQUIRE((int)((finalrank[0].second * 100000)/10) == 3598);
    REQUIRE((int)((finalrank[1].second * 100000)/10) == 2133);
    REQUIRE((int)((finalrank[2].second * 100000)/10) == 2133);
    REQUIRE((int)((finalrank[3].second * 100000)/10) == 2133);
}

TEST_CASE("PageRank works with simple data and large n") {
    
    string d = file_to_string("/workspaces/cs225/Final_Project/testpr1");
    Graph obj(d);
    vector<pair<int, double> > finalrank = pageRank(100, obj);
    REQUIRE((int)((finalrank[0].second * 100000)/10) == 4797);
    REQUIRE((int)((finalrank[1].second * 100000)/10) == 1734);
    REQUIRE((int)((finalrank[2].second * 100000)/10) == 1734);
    REQUIRE((int)((finalrank[3].second * 100000)/10) == 1734);
}

TEST_CASE("PageRank works with cycles in the graph") {
       string d = file_to_string("/workspaces/cs225/Final_Project/testpr2");
    Graph obj(d);
    vector<pair<int, double> > finalrank = pageRank(4, obj);
    REQUIRE((int)((finalrank[0].second * 100000)/10) == 3333);
    REQUIRE((int)((finalrank[1].second * 100000)/10) == 3333);
    REQUIRE((int)((finalrank[2].second * 100000)/10) == 3333);
}

TEST_CASE("PageRank works with complex data and small n") {
    
    string d = file_to_string("/workspaces/cs225/Final_Project/testpr3");
    Graph obj(d);
    vector<pair<int, double> > finalrank = pageRank(3, obj);
    REQUIRE((int)((finalrank[0].second * 100000)/10) == 2818);
    REQUIRE((int)((finalrank[1].second * 100000)/10) == 2196);
    REQUIRE((int)((finalrank[2].second * 100000)/10) == 1159);
    REQUIRE((int)((finalrank[3].second * 100000)/10) == 3324);
    REQUIRE((int)((finalrank[4].second * 100000)/10) == 501);
}

TEST_CASE("PageRank works with complex data and large n") {
    
    string d = file_to_string("/workspaces/cs225/Final_Project/testpr3");
    Graph obj(d);
    vector<pair<int, double> > finalrank = pageRank(100, obj);
    REQUIRE((int)((finalrank[0].second * 100000)/10) == 3170);
    REQUIRE((int)((finalrank[1].second * 100000)/10) == 1871);
    REQUIRE((int)((finalrank[2].second * 100000)/10) == 1319);
    REQUIRE((int)((finalrank[3].second * 100000)/10) == 3113);
    REQUIRE((int)((finalrank[4].second * 100000)/10) == 524);
}