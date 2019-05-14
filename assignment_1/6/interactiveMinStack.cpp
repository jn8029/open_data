#include <iostream>
#include <string>
#include <iomanip>
#include "minStack.h"
#include <vector>
#include <iterator>
#include <cstring>
#include <map>
using namespace std;


int main(){
  string operation;
  MinStack<int> stack;
  cout << "Usage: [OPERATION] [ARGS]"<<endl;
  cout << "Operations:"<<endl;
  cout <<setw(25)<<left<< "push i"<<setw(20)<<left<<"push item i in the stack;"<<endl;
  cout <<setw(25)<<left<< "pop"<<setw(20)<<left<<"remove the top item on the stack;"<<endl;
  cout <<setw(25)<<left<< "min"<<setw(20)<<left<<"get the size of the stack;"<<endl;
  cout <<setw(25)<<left<< "size"<<setw(20)<<left<<"get the size of the stack;"<<endl;
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
    if(results[0]=="push" && results.size()==2){
      try {
        int index = stoi(results[1]);
        stack.push(index);
        stack.print();
      } catch (const std::exception &e) {
        cout<<"Error! "<<e.what()<<endl;
      }
    } else if (results[0]=="size" && results.size()==1){
      cout << stack.size() << endl;
    } else if (results[0]=="min" && results.size()==1){
      cout << stack.min() << endl;
    } else if (results[0]=="pop" && results.size()==1){
      try {
        int removed = stack.pop();
        cout <<"item " << removed << " is removed."<<endl;
        stack.print();
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
