#include <iostream>
#include <string>
#include <iomanip>
#include "USet.h"
#include <vector>
#include <iterator>
#include <cstring>
#include <map>
#include "arrayList.h"
using namespace std;

void invalid_input(){
  cout <<"Invalid input, try again"<<endl;
}

int main(){
  string operation;
  USet uset;
  cout << "Usage: [OPERATION] [ARGS]"<<endl;
  cout << "Operations:"<<endl;
  cout <<setw(25)<<left<< "add i"<<setw(20)<<left<<"add item i in the uset;"<<endl;
  cout <<setw(25)<<left<< "remove i"<<setw(20)<<left<<"remove item i from the uset;"<<endl;
  cout <<setw(25)<<left<< "find i"<<setw(20)<<left<<"find i in uset;"<<endl;
  cout <<setw(25)<<left<< "findAll i"<<setw(20)<<left<<"find all i in uset;"<<endl;
  cout <<setw(25)<<left<< "size"<<setw(20)<<left<<"get the size of the uset;"<<endl;
  cout <<setw(25)<<left<< "print"<<setw(20)<<left<<"print all item in bag;"<<endl;
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
        int index = stoi(results[1]);
        uset.add(index);

      } catch (const std::exception &e) {
        cout<<"Error! "<<e.what()<<endl;
      }
    } else if (results[0]=="size" && results.size()==1){
      cout << uset.size() << endl;
    } else if (results[0]=="remove" && results.size()==2){
      try {
        int index = stoi(results[1]);
        int removed = uset.remove(index);
        cout <<"item " << removed << " is removed."<<endl;

      } catch(const exception &e){
        cout<<"Error! "<<e.what()<<endl;
      }
    } else if (results[0]=="find" && results.size()==2){
        try {
          int target = stoi(results[1]);
          int found = uset.find(target);
          cout <<"found item " << found <<endl;

        } catch(const exception &e){
          cout<<"Error! "<<e.what()<<endl;
        }
    } else if (results[0]=="findAll" && results.size()==2){
        try {
          int target = stoi(results[1]);
          arrayList<int> found = uset.findAll(target);
          cout <<"found "<< found.getElementCount() << " items." <<endl;
          found.print();

        } catch(const exception &e){
          cout<<"Error! "<<e.what()<<endl;
        }
    } else if(results[0]=="exit"){
      break;
    } else if(results[0]=="print" && results.size()==1){
        uset.print();

    } else {
      cout<<"Invalid input, try again."<<endl;
    }
  }
}
