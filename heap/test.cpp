#include "binaryHeap.h"
#include "meldableHeap.h"
#include <iostream>
#include "../catch2.hpp"

#define SIZE 1000000
using namespace std;
TEST_CASE("binaryHeap"){
  priorityQueue q;
  for (int i = SIZE ; i>=0 ; i--){
    q.add(i);
  }
  for (int i = 0 ; i<=SIZE ; i++){
    int k  = q.remove();
    REQUIRE(k==i);
  }
}

TEST_CASE("meldableHeap"){
  priorityQueueM q;
  for (int i = SIZE ; i>=0 ; i--){
    REQUIRE(true==q.add(i));
  }
  for (int i = 0 ; i<=SIZE ; i++){
    int k  = q.remove();
    REQUIRE(k==i);
  }
}
