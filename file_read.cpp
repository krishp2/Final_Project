#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <fenv.h>
#include <signal.h>
#include "Graph.h"
#include "file_read.h"
using std::list;
using std::vector;
using std::string;

std::string file_to_string(const std::string& filename){
  std::ifstream text(filename);

  std::stringstream strStream;
  if (text.is_open()) {
    strStream << text.rdbuf();
  }
  return strStream.str();
}

// void readVertex(){
//     for(int i = 0 ; i< 262111; i++){
//         insertVertex(i);
//     }
// }
    
list<vector<string> > readEdge(const string& data){
    vector<string> row;
    string temp = "";
    string t;
    list<vector<string> > obj;
    for (unsigned i=0; i< data.size(); i++){
        if (data[i]!='\t' && data[i]!='\n'){
            t = t+ data[i];
        }
        else if(data[i]== '\t'){
            row.push_back(t);
            temp = t;
            t = "";
        }
          else if(data[i]== '\n'){
            row.push_back(t);
            row.push_back(temp + "_" + t);
            obj.push_back(row);
            row.clear();
            t="";
            temp ="";
        }
    }
    return obj;
}   

