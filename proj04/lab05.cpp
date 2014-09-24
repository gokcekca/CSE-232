/* 
 * File:   lab04.cpp
 * Author: gokcekca
 *
 * Created on February 4, 2014, 3:01 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long loc_to_dec(string loc)
{
    int sum=0;
    for (auto c : loc)   
    {
        sum = sum + pow(2.0,c - 'a');
    }
    return sum;
    
}

string abbreviate(string loc)
{
    bool changed = true;
    while (changed)
    {
        sort(loc.begin(),loc.end());
        changed = false;

        for (int i=0;i<loc.length()-1;i++)
        {
            if (loc[i] == loc[i+1])
            {
                loc[i]++;
                loc.erase(i+1,1);
                changed = true;
            }
        }
    }
    return loc;
}

string dec_to_loc(long dec)
{
    string stri="";
    for (int i = 1 ; i<dec+1; i++)
    {
        stri.push_back('a'); 
    }
    stri = abbreviate(stri);

    return stri;
    
}

long add_loc(string loc1,string loc2)
{
    string new_str = loc1+loc2;
    sort(new_str.begin(),new_str.end());
    
}

int main(int argc, char** argv) {
    cout << dec_to_loc(37);
    

    return 0;
}

