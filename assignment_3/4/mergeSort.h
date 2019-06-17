#ifndef QSORT_H
#define QSORT_H
#include <iostream>

class MergeSort{
public:
   void sort(int *numbers, int size){

     if(size <= 1) return;
     std::cout << "MergeSort on:"<<std::endl;
     print(numbers, size);
     int mid = (size-1)/2;
     std::cout<<"mid index = "<<mid <<std::endl;
     int front_size = mid-0+1;
     int back_size = (size-1)-mid;
     int* front = new int[front_size];
     int* back = new int[back_size];


     copy(numbers, 0, mid, front);
     copy(numbers, mid+1, size-1, back);
     std::cout<<"split front array: "<<std::endl;
     print(front, front_size);
     std::cout<<"split back array: "<<std::endl;
     print(back, back_size);

     sort(front, front_size);
     sort(back, back_size);
     merge(numbers, front, back, front_size, back_size);
   }
private:
  void print(int* numbers, int size){
    for (int i =0; i <size; i ++){
        std::cout<<numbers[i]<<"\t";
    }
    std::cout<<std::endl;
  }
  void merge(int *numbers, int* front ,int* back, int front_size, int back_size){
    std::cout <<"merging two arrays:"<<std::endl;
    print(front, front_size);
    print(back, back_size);

    int front_counter = 0;
    int back_counter = 0;
    for (int i = 0; i < front_size + back_size; i++){
      std::cout<<"front_counter = "<<front_counter<<", back_counter = "<<back_counter<<std::endl;
      if (front_size == front_counter ){
        std::cout<<"front array traversal ended..."<<std::endl;
        std::cout<<"insert back["<<back_counter<<"]="<<back[back_counter]<<" into merged array at index "<<i<<std::endl;
        numbers[i] = back[back_counter++];

      } else if (back_size == back_counter){
        std::cout<<"back array traversal ended..."<<std::endl;
        std::cout<<"insert front["<<front_counter<<"]="<<front[front_counter]<<" into merged array at index "<<i<<std::endl;
        numbers[i] = front[front_counter++];
      } else if (front[front_counter] < back[back_counter]){
        std::cout<<"front["<<front_counter<<"]="<<front[front_counter]<<"<back["<<back_counter<<"]="<<back[back_counter]<<std::endl;
        std::cout<<"insert front["<<front_counter<<"]="<<front[front_counter]<<" into merged array at index "<<i<<std::endl;
        numbers[i] = front[front_counter++];
      } else {
        std::cout<<"front["<<front_counter<<"]="<<front[front_counter]<<">=back["<<back_counter<<"]="<<back[back_counter]<<std::endl;
        std::cout<<"insert back["<<back_counter<<"]="<<back[back_counter]<<" into merged array at index "<<i<<std::endl;

        numbers[i] = back[back_counter++];
      }
    }
    std::cout<<"Merge Result:"<<std::endl;
    for (int i =0; i< front_size + back_size; i++){
      std::cout<<numbers[i]<<"\t";
    }
    std::cout<<std::endl;
  }
  void copy(int *numbers, int start, int finish, int* destination){
    int counter = 0;
    for (int i = start; i<=finish; i++){
        destination[counter] = numbers[i];
        counter ++;
    }
  }


};

#endif
