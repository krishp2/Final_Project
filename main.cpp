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
#include "BFS.h"
using std::list;
using std::vector;
using std::string;
int x = 262211;

int main(){
    
    string d = file_to_string("/workspaces/cs225/Final_Project/amazon0302 (1).txt");
    //std::cout<< d;
    //readVertex();
    Graph obj(x, d);
    distance(8,obj);
    //obj.readEdge(d);
    //obj.makeadj2(d);
    //obj.readVertex(d);
    //obj.makeAdj(d);
    //Graph(3);
    //obj.getTranspose();
    //BFSUtil(0);
    //bool check;
    //check = isSC(obj, d);
    //std::cout << check << std::endl;
    std::cout << "Reached line " << __LINE__ << std::endl;
    //obj.printadj();
    //AdjcanceylistTest();
    //edgestest();
    //obj.printedge();

    return 0;

}