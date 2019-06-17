#ifndef QSORT_H
#define QSORT_H
#include <iostream>
typedef struct {
  int front;
  int back;
} Partition;

class QuickSort{
public:
  void sort(int* numbers, int head, int tail){
    std::cout << "QuickSort(numbers, "<< head<<", "<<tail<<")"<<std::endl;
    if (tail<=head) {
      std::cout << "tail <= head, return"<<std::endl;
      return;
    }
    Partition p = getPartition(numbers, head, tail);

    sort(numbers, head, p.front);
    sort(numbers, p.back, tail);
  }
private:
  Partition getPartition(int* numbers, int head, int tail ){
    std::cout <<"getPartition(numbers, "<<head<<", "<<tail<<")"<<std::endl;
    int front = head-1;
    int back = tail+1;
    int pivot = numbers[tail];
    int temp;
    std::cout <<"pivot index = "<< tail<<"; value = "<< pivot<<std::endl;
    for (int i =head ; i<tail && i<back; i++){
      std::cout <<"traversing index = "<<i<<std::endl;
      if (numbers[i]<pivot){
        front++;
        temp = numbers[i];
        numbers[i] = numbers[front];
        numbers[front] = temp;
        std::cout<<"value "<<temp <<" < pivot " << pivot<<std::endl;
        std::cout<<"swap "<<temp << " with value "<< numbers[i] <<" at index "<<front<<std::endl;

      } else if (numbers[i] > pivot){
        back--;
        temp = numbers[i];
        numbers[i] = numbers[back];
        numbers[back] = temp;
        std::cout <<"value "<< temp <<" > pivot "<< pivot<<std::endl;
        std::cout <<"swap "<<temp << " with value "<< numbers[i]  <<" at index "<<back<<std::endl;
        i--;

      } else {
        std::cout <<"value "<< numbers[i]<<" == pivot " <<pivot<<std::endl;
        std::cout <<"do nothing"<<std::endl;
      }
    }

    Partition p;
    p.front = front;
    p.back = back;
    std::cout <<"traversal terminated with partition result: front = "<<p.front<<", back = "<<p.back<<std::endl;
    return p;
  }
};

#endif
