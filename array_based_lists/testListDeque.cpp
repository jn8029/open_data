#include "listDeque.h"
#include "catch2.hpp"

TEST_CASE("initiate empty listDeque") {
  listDeque<int> deque;
  REQUIRE( deque.getArraySize() == 1 );
  REQUIRE( deque.getElementCount() == 0);
  SECTION("test push(): n elements"){
    int n = 10;
    for (int i = 0 ; i<n; i++){
      deque.pushFront(i);
    }
    REQUIRE(deque.getElementCount()==n);
  }
  SECTION("test popFront(): pop an element from empty deque"){
    REQUIRE_THROWS(deque.popFront());
  }
  SECTION("test popBack(): pop an element from empty deque"){
    REQUIRE_THROWS(deque.popBack());
  }
}

TEST_CASE("initiate listDeque with n elements") {
  listDeque<int> deque;
  int n = 10;
  for (int i = 0 ; i<n; i++){
    deque.pushFront(i);
  }
  deque.printAll();


  REQUIRE( deque.getArraySize() == 16 );
  REQUIRE( deque.getElementCount() == 10);
  SECTION("test popFront(): pop all elements"){
    int counter = 9;
    while(deque.getElementCount()>0){
      REQUIRE(deque.popFront()==counter);
      counter--;
    }
  }
  SECTION("test popBack(): pop all elements"){
    int counter = 0;
    while(deque.getElementCount()>0){
      REQUIRE(deque.popBack()==counter);
      counter++;
    }
  }
}

TEST_CASE("initiate listDeque with n elements with pushBack") {
  listDeque<int> deque;
  int n = 10;
  for (int i = 0 ; i<n; i++){
    deque.pushBack(i);
  }
  deque.printAll();
  REQUIRE( deque.getArraySize() == 16 );
  REQUIRE( deque.getElementCount() == 10);
  SECTION("test popFront(): pop all elements"){
    int counter = 0;
    while(deque.getElementCount()>0){
      REQUIRE(deque.popFront()==counter);
      counter++;
    }
  }
  SECTION("test popBack(): pop all elements"){
    int counter = 9;
    while(deque.getElementCount()>0){
      REQUIRE(deque.popBack()==counter);
      counter--;
    }
  }
  SECTION("test popBack() and popFront(): pop all elements"){
    REQUIRE(deque.popBack()==9);
    REQUIRE(deque.popFront()==0);
    REQUIRE(deque.popBack()==8);
    REQUIRE(deque.popFront()==1);
    REQUIRE(deque.popFront()==2);
    REQUIRE(deque.popFront()==3);
    REQUIRE(deque.popFront()==4);
    REQUIRE(deque.popBack()==7);
    REQUIRE(deque.popBack()==6);
    REQUIRE(deque.popBack()==5);
    REQUIRE_THROWS(deque.popBack());

  }
}
