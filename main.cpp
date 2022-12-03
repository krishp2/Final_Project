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
#include "test.h"
using std::list;
using std::vector;
using std::string;

int main(){
    
    string d = file_to_string("/Users/apple/Desktop/Final_Project/amazon0302 (1).txt");
    //std::cout<< d;
    //readVertex();
    Graph obj;
    obj.readEdge(d);
   
    //obj.makeAdj(d);
    //obj.printadj();
    //AdjcanceylistTest();
    edgestest();

    //obj.printedge();
    return 0;
}