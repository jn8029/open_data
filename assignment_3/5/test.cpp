#include "Graph.h"
#include <iostream>
#include "../catch2.hpp"
#include <vector>
#include <random>
using namespace std;
// Edges as shown in the graph.
// 0 1
// 0 4
// 0 5
// 1 0
// 1 2
// 2 1
// 2 3
// 2 5
// 3 2
// 3 6
// 4 0
// 4 8
// 5 0
// 5 2
// 5 9
// 6 3
// 6 7
// 6 9
// 6 10
// 7 6
// 7 14
// 8 4
// 8 9
// 8 12
// 8 13
// 9 5
// 9 6
// 9 8
// 10 6
// 10 14
// 11 15
// 12 8
// 13 8
// 13 14
// 14 7
// 14 10
// 14 13
// 14 15
// 15 11
// 15 14
int main(){
  Graph g(16);
  int  num;
  for (int i = 0; i < 40; i++){
    Edge e;
    cin >> e.source;
    cin >> e.dest;
    g.addEdge(e);

  }
  cout <<"DFS:"<<endl;
  g.DFS(6);
  cout <<"BFS:"<<endl;
  g.BFS(1);

}
