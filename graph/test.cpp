#include "Graph.h"
#include <random>
#include <iostream>
#include <vector>
// #include "../catch2.hpp"
#define SIZE 100
using namespace std;
// int getRandomIndex(){
//   const int range_from  = 0;
//   const int range_to   = SIZE-1;
//   random_device rand_dev;
//   mt19937 generator(rand_dev());
//   uniform_int_distribution<int> distro(range_from, range_to);
//   return distro(generator);
// }
int main(){
  int  num;
  do {
   cout<<"Enter a number, or numbers separated by a space, between 1 and 1000."<<endl;
   cin >> num;
  cout << num <<"found "<<endl;
  } while (true); // or some condition
}
