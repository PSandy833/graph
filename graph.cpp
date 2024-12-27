/*graph.h*/

//
// Graph class implemented as ...
//
//    ?????????
//
// For this implementation of graph, the vertices are
// string, and the weights are doubles.  Example:
//
//   graph  G;
//   G.addVertex("Chicago");
//   G.addVertex("New York");
//   G.addEdge("Chicago", "New York", -999.99);
//
// NAME: SANDY BOCKARIE
//
// Northwestern University
// CS 211: Winter 2023
//


#include "graph.h"

using namespace std;


graph::graph(){
  numEdges = 0;
  N = 0;
};
// Returns the # of vertices currently in the graph.
int graph::NumVertices() const { return (int) this->vertexList.size(); }

// Returns the # of edges currently in the graph.
int graph::NumEdges() const { return this->numEdges; }

// Adds the vertex v to the graph and returns true. However,
// if v is already in the graph, it is not added again and
// false is returned.
bool graph::addVertex(string v) {
  if (vertexList.find(v) != vertexList.end()) {
    return false;
  }
  vertexList.emplace(v, NumVertices());
  N++;
  edgeList.push_back(map<string, double>());
  return true;
 }

// Adds the edge (from, to, weight) to the graph, and returns
// true. If the vertices do not exist then no edge is added
// and false is returned.
//
// NOTE: if the edge already exists, the existing edge weight
// is overwritten with the new edge weight.
bool graph::addEdge(string from, string to, double weight) {
  if (vertexList.find(from) == vertexList.end() ||
      vertexList.find(to) == vertexList.end()) {
    return false;
  }
  auto P = edgeList[vertexList.find(from)->second].find(to);
  if (P == edgeList[vertexList.find(from)->second].end()) {
    edgeList[vertexList.find(from)->second].emplace(to, weight);
    numEdges++;
  } else {
    P->second = weight;
  }
  return true;
}

// Returns the weight associated with a given edge. If
// the edge exists, the weight is returned via the reference
// parameter and true is returned. If the edge does not
// exist, the weight parameter is unchanged and false is
// returned.
bool graph::getWeight(string from, string to, double &weight) const {
  if (vertexList.find(from) == vertexList.end() ||
      vertexList.find(to) == vertexList.end()) {
    return false;
  }
  auto P = edgeList[vertexList.find(from)->second];
  if (P.find(to) == P.end()) {
    return false;
  } else {
    weight = P[to];
    return true;
  }
}

// Returns a set containing the neighbors of v, i.e. all
// vertices that can be reached from v along one edge. If
// v does not exist, an empty set is returned.
set<string> graph::neighbors(string v) const {
  set<string> result;
  if (vertexList.find(v) == vertexList.end()) {
    return result;
  }
  for (auto &entry : edgeList[vertexList.find(v)->second]) {
    result.insert(entry.first);
  }
  return result;
}

vector<string> graph::getVertices() const {
  vector<string> Vertices;

  for (auto &entry : vertexList) {
    Vertices.push_back(entry.first);
  }
  return Vertices;
}
void graph::print(ostream &output) const {

  output << "******************* GRAPH **********************" << endl;

  output << "Number of vertices: " << NumVertices() << endl;
  output << "Number of edges: " << numEdges << endl;

  // Output all vertices with their weights
  output << "Vertices:" << endl;
  for (const auto &vertex : vertexList) {
    output << vertex.first << " (weight: " << vertex.second << ")" << endl;
  }
  output << endl;

  // // Output all edges
  // output << "Edges:" << endl;
  // for (const auto& edge : edgeList) {
  //     output << edge.first.first << " --" << edge.second << "-- " <<
  //     edge.first.second << endl;
  // }
}
