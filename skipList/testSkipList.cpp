#include "skipList.h"
#include "../catch2.hpp"


TEST_CASE("initiate empty skipList") {
  skipList testList(30);
  SECTION("insert"){
    vector<int> inserted;
    cout <<"Inserting ..."<<endl;
    for (int i = 0 ; i < 10; i++){
      int toInsert = rand()%100;
      cout << toInsert << '\t';
      testList.insert(toInsert);
      inserted.push_back(toInsert);
    }
    cout <<endl;
    testList.print();
    SECTION("checking if inserted exists"){
      REQUIRE(testList.exists(inserted[5])==true);
      REQUIRE(testList.exists(105)==false);
      int toDelete = inserted[5];
      testList.remove(inserted[5]);
      REQUIRE(testList.exists(toDelete)==false);
      cout <<"after deleting "<<toDelete<<endl;
      testList.print();

    }




  }


}
