#include "PriorityQueue.h"
#include <queue>
#include "../catch2.hpp"

TEST_CASE("initiate empty PriorityQueue") {
  PriorityQueue pQueue;
  SECTION("test size()"){
    REQUIRE(pQueue.size()==0);
  }
  SECTION("test deleteMin()"){
    REQUIRE_THROWS(pQueue.deleteMin());
  }
}

TEST_CASE("initiate PriorityQueue with 100 elements with range 0-99") {
  PriorityQueue pQueue;

  int size = 10;
  int comparisonArray[size];
  for (size_t i = 0 ; i < size; i++){
    int value = rand()%size;
    pQueue.add(value);
    comparisonArray[i] = value;
  }
  sort(comparisonArray, comparisonArray+size);
  cout<<"pQueue"<<endl;
  pQueue.print();
  cout<<"Compare"<<endl;
  for (size_t i = 0 ; i < size; i++){
    cout<<comparisonArray[i] <<'\t';
  }
  cout<<"\n------------"<<endl;

  SECTION("test size()"){
    REQUIRE(pQueue.size()==size);
  }
  SECTION("test deleteMin()"){
    for (size_t i =0 ; i < size; i++){
      int popped = pQueue.deleteMin();
      cout<<popped<<'\t';
    }
    cout<<endl;



  }

}
