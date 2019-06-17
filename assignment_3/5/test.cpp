#include "Graph.h"
#include <iostream>
#include "../catch2.hpp"
#include <vector>
#include <random>
using namespace std;



void dfs2(Graph g, int r) {
byte[] c = new byte[g.nVertices()];
Stack<Integer> s = new Stack<Integer>();
s.push(r);
while (!s.isEmpty()) {
  int i = s.pop();
  if (c[i] == white) {
    c[i] = grey;
    for (int j : g.outEdges(i))
      s.push(j);
    }
}
//https://en.wikipedia.org/wiki/Eulerian_path
TEST_CASE("graph"){
  int adjacencyList = {
    {1,4,5}
    {0,2}
    {1,3,5}
    {2,6}
    {0,8}
    {0,2,9}
    {3,7,9,10}
    {6,14}
    {4,9,12,13}
    {5,6,8}
    {6,14}
    {15}
    {8}
    {8,14}
    {7,10,13,15}
    {11,14}

  }
  priorityQueueM q;
  vector<int> v;
  for (int i = SIZE ; i>=0 ; i--){
    int value = distro(generator);
    v.push_back(value);
    REQUIRE(true==q.add(value));
  }
  sort(v.begin(), v.end());
  for (int i = 0 ; i<=SIZE ; i++){
    int k  = q.remove();
    REQUIRE(k==v[i]);
  }
}
