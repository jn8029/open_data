#include <iostream>
using namespace std;
#define SIZE 10

int main(){
  // Question: 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5
  int question[] = {3,1,4,1,5,9,2,6,5,3,5};
  for (int i =0; i < 11 ; i ++){
    cout<< question[i] <<", ";
  }
  cout<<endl;
  int* numbers = &question[0];
  quickSort(numbers, 0, 10);
  for (int i =0; i < 11; i++){
    cout<<numbers[i]<<", ";
  }
  cout<<endl;

}
