#include<iostream>
using std::cout; using std::endl;
#include "vector.h"
using student::vector;

int main (){
  vector<long> v;
  cout << v.size() << endl;
  cout << v.capacity() << endl;
}
