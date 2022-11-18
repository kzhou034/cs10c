//CS10C - Spring 2021
//Lab 10
//Pair: Baron Fung, Kelley Zhou
//Resource(s): Zybooks, cplusplus.com
// https://d1b10bmlvqabco.cloudfront.net/attach/ilv1r6m8xjc64o/h7ks2ibk8jg6s3/ioki9sunvh1o/graphs.pdf 

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <utility> //pairs

#include "Graph.h"

using namespace std;

Graph::Graph() {

}

//Reads the graph input file and instantiates a graph object
Graph::Graph(ifstream& inFS) {
    int N = 0; //nodes; assume at most MaxN = 50
    int M = 0; //edges; assume at most MaxM = 200
    string strLabel = ""; //labels; assume at most MaxNameLength = 15 chars (no spaces)

    inFS >> N; //number of nodes (first line of input file)
    inFS >> M; //number of edges (second line of input file)

    //next N lines contain node LABELS (one per line)
    for (int i = 0; i < N; i++) {
        inFS >> strLabel;
        Vertex v = Vertex(); //creates vertex
        v.label = strLabel; //changes label of new vertex
        vertices.push_back(v); //pushes v into vector of vertices 
    }

    //next M lines contain edges e = (u,v,c); source vertex u, sink vertex v, cost c from u to v 
    string source = "";
    string sink = "";
    int cost = 0;
    int sourceIndx = 0; //source index
    int sinkIndx = 0; //sink index
    for (int i = 0; i < M; i++) {
        inFS >> source >> sink >> cost;
        for (long unsigned int j = 0; j < vertices.size(); j++) {
            if (source == vertices.at(j).label) {
                sourceIndx = j;
            }
            
        }
        for (long unsigned int k = 0; k < vertices.size(); k++) {
            if (sink == vertices.at(k).label) {
                sinkIndx = k;
            }
        }

        pair<int,int> pair(sinkIndx, cost); //creates pair   (sink's index, cost between the source and sink)
        vertices.at(sourceIndx).neighbors.push_back(pair); //each element (vertex) in vector vertices has it's own list of neighbors
    }
}

Graph::~Graph() {

}

/*Outputs graph object to a .dot file, then makes a system call that calls 
dotty on this file. 
In the dotty file, each node should include vertex label and its distance value.*/
void Graph::output_graph(const string &outputFilename) {
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    for (long unsigned int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).distance != INT_MAX) {
            outFS << vertices.at(i).label << "[label = \"" << vertices.at(i).label << ", distance = " << vertices.at(i).distance << "\" ];" << endl;
        }
        list<pair<int,int> >::iterator b;
        for (b = vertices.at(i).neighbors.begin(); b != vertices.at(i).neighbors.end(); b++) {
            if (vertices.at(i).distance != INT_MAX) {
            outFS << vertices.at(i).label << " -> " << vertices.at(b->first).label << endl;
            }
        }
    }
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

//Breadth First Search. Via a BFS traversal, this function should assign each 
//individual vertex's distance to the number of hops that the vertex is 
//from the start vertex. 
//You can find the pseudo code for BFS on graphs.pdf
//resource: https://d1b10bmlvqabco.cloudfront.net/attach/ilv1r6m8xjc64o/h7ks2ibk8jg6s3/ioki9sunvh1o/graphs.pdf 
void Graph::bfs() {
    queue<Vertex> vQueue;

    for (unsigned i = 0; i < vertices.size(); i++) {
		vertices.at(i).color = "WHITE";
		vertices.at(i).distance = INT_MAX;
		vertices.at(i).prev = nullptr;
	}

    vertices.at(0).color = "GRAY"; //first node discovered (not expanded)
    vertices.at(0).distance = 0;
    vertices.at(0).prev = nullptr;

    vQueue.push(vertices.at(0));

    while (!vQueue.empty()) {
        Vertex frontV = vQueue.front();
        vQueue.pop();
        frontV.color = "GRAY"; //discovered

        list<pair<int,int> >::iterator a;
        for (a = frontV.neighbors.begin(); a != frontV.neighbors.end(); a++) {
            int idx = a->first; //first int in pair
            if (vertices.at(idx).color == "WHITE") {
                //cout << "entered if statement" << endl;
                vertices.at(idx).color = "GRAY";
                //cout << "changed color to gray" << endl;

                //cout << vertices.at(idx).distance << ", prev distance ";
                //Vertex *frontPrev = frontV.prev;
                //cout << &frontPrev->distance << endl;
                //cout << "segfault" << endl;
                //cout << vertices.at(a->first).prev;

                vertices.at(idx).distance = frontV.distance + 1;

                //cout << "changed distance" << endl;

                vQueue.push(vertices.at(idx));
                //cout << "vertices at idx stuff done" << endl;
            }
            vertices.at(idx).color = "BLACK";
        }
        //cout << "iteration finished, looping again" << endl;
    }
}