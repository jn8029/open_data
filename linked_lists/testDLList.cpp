#include "DLList.h"
#include "../catch2.hpp"

TEST_CASE("initiate empty DLList") {
  DLList<int> dlList;

  SECTION("test add(): n elements"){
    int n = 10;
    for (int i = 0 ; i<n; i++){
      dlList.add(i,i);

    }
    dlList.printAll();
    for (int i = 0 ; i<n; i++){
      REQUIRE(dlList.get(i)==i);

    }
  }

}

TEST_CASE("initiate DLList with n elements") {
  DLList<int> dlList;
  int n = 10;
  for (int i = 0 ; i<n; i++){
    dlList.add(i,i);
  }
  SECTION("test remove()"){
    dlList.remove(0);
    REQUIRE(dlList.get(0)==1);
    dlList.remove(3);
    REQUIRE(dlList.get(4)==6);
    REQUIRE(dlList.get(7)==9);
  }



}
