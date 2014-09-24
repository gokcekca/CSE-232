//////////////////////////////////////////////////////
//  Can Gokcek - Computer Project #7 - Header File  //
//////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <cctype>
#include <fstream>
#include <map>
#include <sstream>
#include <utility>

using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::pair;
using std::ostringstream;

using std::ostream_iterator;
using std::cout; using std::endl;
using std::find; using std::set_intersection; using std::set_difference;
using std::string;
using std::vector;
using std::map;
using std::make_pair;


#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

string lower_and_strip(string);

void read_stopwords(vector<string> & , string);

void read_file(map<string,long> &, vector<string> &, string);

string print_map(map<string,long> & , string order = "alpha");

vector<string> sorted_words(map<string,long> &);

template<typename Itr1, typename Itr2, typename Out> 
void my_set_intersection(Itr1 source1_begin, Itr1 source1_end, Itr2 source2_begin, Itr2 source2_end, Out dest){
    while(source1_begin != source1_end){                                //Loop while not at end of source.
        auto it = find( source2_begin, source2_end, *source1_begin);    //Set iterator to the found item, or to the end.
        if (it!=source2_end){                                           //If not at end,
            *dest = *it;                                                //Set dest to found item.
            ++source1_begin;                                            //Increment iterator for source1.
            ++dest;                                                     //Increment dest.
        }
        else{                                                           //Otherwise,
            ++source1_begin;                                            //Just increment iterator for source1.
        }
    }
}

template<typename Itr1, typename Itr2, typename Out> 
void my_set_difference(Itr1 source1_begin, Itr1 source1_end, Itr2 source2_begin, Itr2 source2_end, Out dest){
    while(source1_begin != source1_end){                               //Loop while not at end of source.
        auto it = find( source2_begin, source2_end, *source1_begin);   //Set iterator to the found item, or to the end.
        if (it==source2_end){                                          //If not at end,
            *dest = *source1_begin;                                    //Set dest to item in source1..
            ++source1_begin;                                           //Increment iterator for source1.
            ++dest;                                                    //Increment dest.
        }
        else{                                                          //Otherwise,
            ++source1_begin;                                           //Just increment iterator for source1.
        }
    }
}
#endif	/* FUNCTIONS_H */

