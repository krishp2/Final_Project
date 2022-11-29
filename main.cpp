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
using std::list;
using std::vector;
using std::string;

int main(){
    list<vector<string> > test;
    string d = file_to_string("/Users/apple/Desktop/Final_Project/amazon0302 (1).txt");
    //readVertex();
    test = readEdge(d);
    list< vector<string> >::iterator list_it;
    vector<string>::iterator vec_it;
    for (list_it = test.begin(); list_it != test.end(); 
++ list_it){
     for (vec_it = list_it->begin(); vec_it != list_it->end(); ++ vec_it)
     {
          //do something with vec_it
          //for example call member function of Class
          std::cout<< (*vec_it) << std::endl;
     } }

    return 0;
}