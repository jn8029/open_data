#include <iostream>
#include "quickSort.h"
using namespace std;


int main(){
  // Question: 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5
  int size=  11;
  int question[] = {3,1,4,1,5,9,2,6,5,3,5};
  for (int i =0; i < size ; i ++){
    cout<< question[i] <<", ";
  }
  cout<<endl;
  int* numbers = &question[0];
  QuickSort q;
  q.sort(numbers, 0, size-1);
  for (int i =0; i < size; i++){
    cout<<numbers[i]<<", ";
  }
  cout<<endl;

}
