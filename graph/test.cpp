#include "Graph.h"
#include <random>
#include <iostream>
#include <vector>
#include "../catch2.hpp"
#define SIZE 100
using namespace std;
int getRandomIndex(){
  const int range_from  = 0;
  const int range_to   = SIZE-1;
  random_device rand_dev;
  mt19937 generator(rand_dev());
  uniform_int_distribution<int> distro(range_from, range_to);
  return distro(generator);
}
TEST_CASE("test vec"){
  vector<vector<int>> t;
  t.reserve(100);
  t[99].push_back(0);
  // t[0].push_back(10);
}
// TEST_CASE("test"){
//   Graph g = Graph(SIZE);
//   for (int i =0; i <10; i++){
//     int source = getRandomIndex();
//     int dest = getRandomIndex();
//     Edge e;
//     e.source = source;
//     e.dest = dest;
//     std::cout<<"adding edge "<<e.source<<"->"<<e.dest<<endl;
//     REQUIRE(true==g.addEdge(e));
//   }
//
//
// }
