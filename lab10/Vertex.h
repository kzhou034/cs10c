//CS10C - Spring 2021
//Lab 10
//Pair: Baron Fung, Kelley Zhou
//Resource(s): Zybooks, cplusplus.com

#ifndef VERTEX_H_
#define VERTEX_H_

#include <string>
#include <list>
#include <map>
#include <climits>

using namespace std;

class Vertex {
public:
/* STL list of STL pairs. for each int,int pair, the integer values are the 
neighboring vertex's position in the 
graph object's vector vertices and the cost of the edge to that neighbor */
  list<pair<int, int> > neighbors; 
  
  string label; //individual vertex's label
  int distance; //distance the vertex is from start vertex
  string color; 
  Vertex* prev; //pointer to previous vertex in BFS traversal. Initially prev is null for all vertices
  
  Vertex():label(""),distance(INT_MAX),color("WHITE"),prev(0){}
  ~Vertex(){}
};

#endif /* VERTEX_H_ */
