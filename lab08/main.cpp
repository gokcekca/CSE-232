/* 
 * File:   main.cpp
 * Author: gokcekca
 *
 * Created on February 25, 2014, 2:58 PM
 */


#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include "functions.h"
#include <iostream>
#include <utility>
#include <algorithm>
using std::map;
using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::endl;
using std::copy;
using std::cin;
using std::make_pair;
/*
 * 
 */
int main(int argc, char** argv) {
    map<long, vector<long> > collatz_map;
    pair<long, vector<long> > collatz_element;
    vector<long> v;
    vector<long> x;
    long low;
    long high;
    cout << "ENTER A LOW VAL: "<<endl;
    cin >> low;
    cout <<"ENTER A HIGH VAL: "<< endl;
    cin >> high;
    
    for(int c = low; c<=high;c++)
    {
        fill_vector(collatz_map,v, c);
        collatz_element = make_pair(c,v);
        collatz_map.insert(collatz_element);
        //cout <<"and the values are: "<<endl;
    }
    
    for (auto l : collatz_map){
        x.clear();
        cout << l.first;
        cout << ":";
        x = l.second;
        for (auto p : x){
            cout << p << " ";
        }
        cout << endl;
     
        
    }

    return 0;
}

