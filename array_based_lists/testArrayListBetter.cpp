#include "arrayListBetter.h"
#include "catch2.hpp"

TEST_CASE("initiate empty arrayList") {
  arrayListBetter<int> list;
  REQUIRE( list.getArraySize() == 1 );
  REQUIRE( list.getElementCount() == 0);

  SECTION("test add(): n elements to the back"){
    int n = 10;
    for (int i = 0 ; i<n; i++){
      list.add(i,i);
      REQUIRE(list.get(i)==i);

    }
    REQUIRE(list.getElementCount()==n);
  }
  SECTION("test add(): n elements to the front"){
    int n = 10;
    for (int i = 0 ; i<n; i++){
      list.add(0,i);
      REQUIRE(list.get(0)==i);
      list.printAll();
    }
    REQUIRE(list.getElementCount()==n);
  }
  SECTION("test remove(): remove an element from empty list"){
    REQUIRE_THROWS(list.remove(0));
  }
}

TEST_CASE("initiate arrayList with n elements"){
  arrayListBetter<int> list;
  int n = 10;
  for (int i = 0 ; i<n; i++){
    list.add(i,i);

  }
  SECTION("test remove() element from out-of-bound index= n"){
    REQUIRE_THROWS(list.remove(n));
  }
  SECTION("test remove() all n element"){
    while(list.getElementCount()>0){
      list.remove(0);

    }
    REQUIRE(list.getElementCount()==0);
  }
  SECTION("test remove() n+1 element, last remove should throw exception"){
    while(list.getElementCount()>0){
      list.remove(0);
  
    }
    REQUIRE(list.getElementCount()==0);
    REQUIRE_THROWS(list.remove(0));
  }
  SECTION("test get(5)"){
    REQUIRE(list.get(5) == 5);
  }
  SECTION("test set(5, 100)"){
    list.set(5,100);
    REQUIRE(list.get(5)==100);
  }


}
