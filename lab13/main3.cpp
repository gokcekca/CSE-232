#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include "vector.h"
using student::vector;

void print_vector(vector<long>& v, ostream& out){
  for(int i=0; i<v.size(); i++){
    out << v[i] << ", ";
  }
  out<<endl;
}

int main (){
  vector<long> v;
  long i;
  cout << v.size() << endl;
  cout << v.capacity() << endl;
  for(i=0; i<12; i++)
    v.push_back(i);
  cout << v.size() << endl;
  cout << v.capacity() << endl;

  print_vector(v, cout);
  vector<long> v2(v);
  v2.push_back(100);
  print_vector(v, cout);
  print_vector(v2, cout);

  vector<long> v3;
  v3 = v2;
  v3.push_back(200);
  print_vector(v2, cout);
  print_vector(v3, cout);
  cout << endl;
}
