/* 
 * File:   functions.h
 * Author: gokcekca
 *
 * Created on February 25, 2014, 2:58 PM
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#include <cstdlib>
#include <map>
#include <vector>
#include <string>

using std::map;
using std::vector;
using std::pair;
using std::string;

long collatz(long);

string pair_to_string(const pair<long, vector<long> > &);

void fill_vector(map<long, vector<long> > &, vector<long> &, long);



#endif	/* FUNCTIONS_H */

