#include "mergeSort.h"
#include <random>
#include <iostream>
#include "../catch2.hpp"

#define SIZE 10
using namespace std;

const int range_from  = 0;
const int range_to   = SIZE;
random_device rand_dev;
mt19937 generator(rand_dev());
uniform_int_distribution<int> distro(range_from, range_to);


TEST_CASE("test"){
  MergeSort sorter;
  for (int arraySize = 0; arraySize < SIZE; arraySize ++){

    int numbers[arraySize];
    for (int i = 0 ; i < arraySize ; i++){
      numbers[i] = distro(generator);
      cout<<numbers[i]<<"\t";
    }
    cout<<endl;
    int *n= &numbers[0];
    sorter.sort(n,  arraySize);
    for (int i = 0; i < arraySize; i ++){
      cout<<numbers[i]<<"\t";
      if (i+1<arraySize){
        REQUIRE(numbers[i]<=numbers[i+1]);
      }
    }
    cout<<endl;


  }

}
