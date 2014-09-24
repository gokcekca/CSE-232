
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include "functions.h"
#include <iostream>
#include <algorithm>
using std::map;
using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::endl;
using std::copy;
using std::to_string;
using std::iterator;

long collatz(long n){
    
    if (n%2==0){
        n=n/2;
        return n; 
    }
    else{
        n = (3*n)+1;
        return n;
    }
}
string pair_to_string(const pair<long, vector<long> > &p){
    long head = p.first;
    vector<long> rest = p.second;
    string rest_str;
    for(auto c : rest){
        rest_str+=to_string(c);
    }
    return to_string(head)+" "+rest_str;
}

void fill_vector(map<long, vector<long> > &m, vector<long> &v, long start){
    //v.clear();
    long current = start;
    vector<long> l;
    int exit=0;  
    while(exit != 1){
        
        auto itr = m.find(current);
        if(itr == m.end()){
            current = collatz(current);
            l.push_back(current);
            v.push_back(current);
        }
        if(itr != m.end()){
            cout << "For "<< start<< " "<< "program copies the rest starting from "<< itr->first<< endl;
            copy(itr->second.begin(), itr->second.end() ,v.begin());
            copy(l.begin(),l.end(),v.begin());
            
            //if (v.empty() == false){
            //    v.insert(v.end(),l.begin(),l.end());
            //}
            return;
        }
        
        if (v.empty()==false){
            exit = v.back();
        }
        
    }
    return;
}



