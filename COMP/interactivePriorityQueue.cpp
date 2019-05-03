#include <iostream>
#include <string>
#include <iomanip>
#include "PriorityQueue.h"
#include <vector>
#include <iterator>
#include <map>
using namespace std;

void invalid_input(){
  cout <<"Invalid input, try again"<<endl;
}

int main(){
  string operation;
  PriorityQueue queue;
  cout << "Usage: [OPERATION] [ARGS]"<<endl;
  cout << "Operations:"<<endl;
  cout <<setw(25)<<left<< "add i"<<setw(20)<<left<<"add item i in the priorityQueue;"<<endl;
  cout <<setw(25)<<left<< "deleteMin"<<setw(20)<<left<<"remove the min value;"<<endl;
  cout <<setw(25)<<left<< "size"<<setw(20)<<left<<"get the size of the queue;"<<endl;

  cout <<endl;
  while (1){
    getline(cin,operation);
    istringstream iss(operation);
    vector<string> results((istream_iterator<string>(iss)),istream_iterator<string>());
    if (results.size()==0){
      cout<<"Invalid input, try again."<<endl;
      continue;
    }
    if(results[0]=="add" && results.size()==2){
      int index = stoi(results[1]);
      queue.add(index);
      queue.print();
    } else if (results[0]=="size" && results.size()==1){
      cout << queue.size() << endl;
    } else if (results[0]=="deleteMin" && results.size()==1){
      try {
        int removed = queue.deleteMin();
        cout <<"item " << removed << " is removed."<<endl;
        queue.print();
      } catch(const exception &e){
        cout<<"Error! "<<e.what()<<endl;
      }
    } else if(results[0]=="exit"){
      break;
    } else {
      cout<<"Invalid input, try again."<<endl;
    }
  }
}
