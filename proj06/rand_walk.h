/* 
 * File:   rand_walk.h
 * Author: cangokcek
 *
 * Created on February 24, 2014, 10:55 AM
 */

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <cassert>
#include <stdexcept>

using std::cout; using std::cin; using std::endl;
using std::ifstream;
using std::map; using std::pair;
using std::vector;
using std::string; using std::to_string;
using std::default_random_engine; using std::uniform_int_distribution;
using std::sort; using std::find;
using std::stol;
using std::invalid_argument;
using std::make_pair;

#ifndef RAND_WALK_H
#define	RAND_WALK_H

 void read_index(map<long, string> & , string &);

 void read_arc(map<long, vector<long>> &, string &);

 long select(default_random_engine &, vector<long> &);

 map<string, long> do_walk(map<long, vector<long>> & , map<long, string> &, long ,long, default_random_engine &);




#endif	/* RAND_WALK_H */

