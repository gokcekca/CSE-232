/* 
 * File:   madlib.h
 * Author: cangokcek
 *
 * Created on February 18, 2014, 6:26 PM
 */

#ifndef MADLIB_H
#define	MADLIB_H
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <map>

using std::vector;
using std::string;
using std::default_random_engine;
using std::size_t;
using std::map;

vector<string> load_word_file(string filename);

string random_word(vector<string>& , default_random_engine&);

void split(string, vector<string>&);

void process_document(string, string, string, string, int seed = 98765);

#endif	/* MADLIB_H */