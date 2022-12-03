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
using std::list;

/*
TEST_CASE("Adjcancey list", "[weight=2][part=1]") {
    Graph test;
    //vector<vector<string> >  getEdges();
    vector<list<string> > a;
    list<string> suba;
    suba.push_back("no");
    suba.push_back("yes");
    string d = file_to_string("/Users/apple/Desktop/Final_Project/test_data.txt");
    test.makeAdj();
    a = test.getAdj();
    REQUIRE( (suba.begin()) == a[4].begin() );
}
*/
void AdjcanceylistTest(){
    Graph test;
    //vector<vector<string> >  getEdges();
    vector<list<string> > a;
    list<string> suba;
    suba.push_back("0");
    suba.push_back("1");
    string d = file_to_string("/Users/apple/Desktop/Final_Project/test_data.txt");
    test.makeAdj(d);
    a = test.getAdj();
    std::cout<< d << std::endl;

    for (auto it = a[0].cbegin(); it != a[0].cend(); it++){
    std::cout << ' ' << *it;
    std::cout << "->";
    }

  std::cout << '\n';
    //a[0]
    //for (std::list<string>::iterator it = a[0].begin(); it != a[0].end(); ++it){
    //                        std::cout << ' -> ' << *(it);}
    //std::cout << *(a[0].begin()) << std::endl; 
}

void edgestest(){
    Graph test;
    //vector<vector<string> >  getEdges();
    vector<vector<string> > a;
    vector<string> suba;
    suba.push_back("0");
    suba.push_back("1");
    string d = file_to_string("/Users/apple/Desktop/Final_Project/test_data.txt");
    test.readEdge(d);
    a = test.getEdges();
    //std::cout<< d << std::endl;
    test.printedge();
    
}