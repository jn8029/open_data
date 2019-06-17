#include "meldableHeap.h"
#include <iostream>
#include "../catch2.hpp"
#include <vector>
#include <random>
using namespace std;
#define SIZE 1000
const int range_from  = 0;
const int range_to   = SIZE;
random_device rand_dev;
mt19937 generator(rand_dev());
uniform_int_distribution<int> distro(range_from, range_to);

TEST_CASE("meldableHeap"){
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
