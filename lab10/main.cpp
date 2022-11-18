//CS10C - Spring 2021
//Lab 10
//Pair: Baron Fung, Kelley Zhou
//Resource(s): Zybooks, cplusplus.com

#include <cstring>
#include "Graph.h"
using namespace std;

int main(int argc, char* argv[]) {
  if(argc != 2) {
    cerr << "Usage error: expected <executable> <input>" << endl;
    exit(1);
  }
  
  ifstream ifs(argv[1]);
  if(!ifs) {
    cerr << "Input file not found." << endl;
    exit(1);
  }
  
  //cout << "graph g(ifs)" << endl;
  Graph g(ifs);
  //cout << "ifs.close" << endl;
  ifs.close();
  //cout << "bfs used" << endl;
  g.bfs();
  //cout << "string file name" << endl;
  string filename = strcat(argv[1] , ".dot");
  //cout << "output_graph" << endl;
  g.output_graph(filename);
  cout << "The End." << endl;
  
  return 0;
}
