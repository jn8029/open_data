#include <iostream>
#include <string>
#include <iomanip>
#include "randomQueue.h"
#include <vector>
#include <iterator>
#include <map>
using namespace std;

void invalid_input(){
  cout <<"Invalid input, try again"<<endl;
}

int main(){
  string operation;
  randomQueue<int> queue;
  cout << "Usage: [OPERATION] [ARGS]"<<endl;
  cout << "Operations:"<<endl;
  cout <<setw(25)<<left<< "add i"<<setw(20)<<left<<"add item i in the priorityQueue;"<<endl;
  cout <<setw(25)<<left<< "remove"<<setw(20)<<left<<"remove a random item;"<<endl;
  cout <<setw(25)<<left<< "size"<<setw(20)<<left<<"get the size of the queue;"<<endl;
  cout <<setw(25)<<left<< "exit"<<setw(20)<<left<<"exit program;"<<endl;
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
      try {
        int value = stoi(results[1]);
        queue.add(value);
        queue.print();
      } catch (const std::exception &e) {
          cout<<"Error! "<<e.what()<<endl;
      }

    } else if (results[0]=="size" && results.size()==1){
      cout << queue.size() << endl;
    } else if (results[0]=="remove" && results.size()==1){
      try {
        int removed = queue.remove();
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
