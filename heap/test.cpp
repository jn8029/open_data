#include "binaryHeap.h"
#include <iostream>
#include "../catch2.hpp"

#define SIZE 10
using namespace std;
TEST_CASE("go"){
  priorityQueue q;
  for (int i = SIZE ; i>=0 ; i--){
    q.add(i);

  }
  q.print();
  for (int i = 0 ; i<SIZE ; i++){
    int k  = q.remove();
    REQUIRE(k==i);
  }
}
