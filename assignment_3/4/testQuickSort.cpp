#include "quickSort.h"
#include <random>
#include <iostream>
#include "../catch2.hpp"
#define SIZE 100
using namespace std;

const int range_from  = 0;
const int range_to   = SIZE;
random_device rand_dev;
mt19937 generator(rand_dev());
uniform_int_distribution<int> distro(range_from, range_to);


TEST_CASE("random"){
  QuickSort sorter;
  for (int arraySize = 0; arraySize < SIZE; arraySize ++){
    int numbers[arraySize];
    for (int i = 0 ; i < arraySize ; i++){
      numbers[i] = distro(generator);
    }
    int *n= &numbers[0];
    sorter.sort(n,  0, arraySize-1);
    for (int i = 0; i < arraySize; i ++){
      if (i+1<arraySize){
        REQUIRE(numbers[i]<=numbers[i+1]);
      }
    }
    cout<<endl;


  }

}
