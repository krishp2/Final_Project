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
using std::list;
using std::vector;
using std::string;
int x = 9;

int main(){
    
    string d = file_to_string("/workspaces/cs225/Final_Project/testpr3");
    //std::cout<< d;
    //readVertex();
    Graph obj(d);
    distance(4,obj);
    //obj.readEdge(d);
    //obj.makeadj2(d);
    //obj.readVertex(d);
    //obj.makeAdj(d);
    //Graph(3);
    //obj.printadj();
    //obj.getTranspose();
    //BFSUtil(0);
    //bool check;
    //printssc(obj);
    //scc(obj);
    //std::cout << check << std::endl;
    std::cout << "Reached line " << __LINE__ << std::endl;
    //obj.printadj();
    //AdjcanceylistTest();
    //edgestest();
    //obj.printedge();

    return 0;

}