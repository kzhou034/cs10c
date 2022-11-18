//CS10C - Spring 2021
//Lab 10
//Pair: Baron Fung, Kelley Zhou
//Resource(s): Zybooks, cplusplus.com

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>

#include "Vertex.h"

using namespace std;

class Graph {
private:
  vector<Vertex> vertices; //vector containing all vertices in the graph. start vertex is 1st position in vector
public:
  Graph();
  Graph(ifstream&); //reads graph input file; instantiates graph object
  ~Graph();

  /* outputs graph object to a .dot file, then makes system call that calls dotty
  on this file. in the dotty file, each node should include vertex label and distance value */
  void output_graph(const string &);  
  void bfs();

  
};

#endif /* GRAPH_H_ */
