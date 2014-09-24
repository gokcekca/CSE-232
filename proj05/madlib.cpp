#include "madlib.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <map>
#include <sstream>

using std::vector;
using std::string;
using std::default_random_engine;
using std::size_t;
using std::map;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::uniform_real_distribution;


vector<string> load_word_file(string filename){
	string a;
	string c;
	string sbstr;
	size_t pos;
	vector<string> v;
	ifstream in_file;
	in_file.open(filename);
	while (!in_file.eof()){		//Loop while not at end of file.
		getline(in_file,a, '\n');	//Get current line and put it in a.
		a+=" ";						//Add a blank space to end.
		while(a != "") {			//While not a blank string.
			pos=a.find(' ');		//Find first space.
			sbstr = a.substr(0,pos);	//Get the substring from beginning to space.
			a.erase(0,pos+1);			//Erase up to and including the space.
			if(sbstr!="")				//If the substring is not blank, add it to vector.
				v.push_back(sbstr);
		}
	}
	in_file.close();
	return v;
}

string random_word(vector<string>& str, default_random_engine& rnd){
	uniform_real_distribution<float> distribution(1,str.size());		
	float myrand = distribution(rnd);		//Generate random number.
	return str[int(myrand)];			//Return the word at the random spot.
}

void split(string str , vector<string>& v){
	string a = str+" ";		//Add blank to string.
	size_t pos;
	size_t post;
	string sbstr;
	while(a.find('\t') < a.length() && a.find('\n') < a.length()){		//While whitespace still exists in the string,
		post = a.find('\t');		//Find tab.
		a.replace(post,1," ");		//Convert to space.
		post = a.find('\n');		//Find newline.
		a.replace(post,1," ");		//Convert to space.
	}
	while(a != "") {		//While string is not empty,
		pos=a.find(' ');	//Find space.
		sbstr = a.substr(0,pos);	//Get substring from beginning to space.
		a.erase(0,pos+1);			//Delete up to and including space.
		if(sbstr!="")				//If substring is not blank,
			v.push_back(sbstr);		//Add to vector.
	}
}

void process_document(string noun_file, string verb_file,
        string in_file, string out_file, int seed){
	default_random_engine engine(seed);
	ofstream out;
	string random;
	out.open(out_file);
	//Load in files.
	vector<string> verbs = load_word_file(verb_file);
	vector<string> nouns = load_word_file(noun_file);
	vector<string> story = load_word_file(in_file);
	vector<string> done_story;

	for (auto c : story){					//For every string in story,
		if(c == "<noun>"){					//Generate random noun and add to output.
			random = random_word(nouns,engine);
			done_story.push_back(random);
			continue;
		}
		else if (c == "<verb>"){
			random = random_word(verbs,engine);		//Generate random verb and add to output.
			done_story.push_back(random);
			continue;
		}
		else{
			done_story.push_back(c);				//Otherwise add other word to output.
		}
	}
	for (auto c : done_story){
		out << c<< endl;
	}
	out.close();
}