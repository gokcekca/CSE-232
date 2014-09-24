#include<iostream>
using std::cout; using std::endl;
#include "vector.h"
using student::vector;

int main (){
  vector<long> v;
  long i;
  cout << v.size() << endl;
  cout << v.capacity() << endl;
  for(i=0; i<12; i++)
    v.push_back(i);
  cout << v.size() << endl;
  cout << v.capacity() << endl;
  for(i=0; i<v.size(); i++)
    cout<<v[i]<<", ";
  cout << endl;
}
