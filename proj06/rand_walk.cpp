#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <cassert>
#include "rand_walk.h"
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

 void read_index(map<long, string> &m , string &file_name){
 	ifstream in_file;
	in_file.open(file_name);
	string a;
	string b;
	pair<long, string> ind_pair;
	while (!in_file.eof()){		//Loop while not at end of file.
		in_file >> a;
		in_file >> b;
		ind_pair = make_pair(stol(b),a);
		m.insert(ind_pair);
	}
 	return;


 }

 void read_arc(map<long, vector<long>> &m , string &file_name){
 	ifstream in_file;
	in_file.open(file_name);
	string a;
	string b;
	string curr="";
	long c;
	vector<long> v;
	pair<long, vector<long>> ind_pair;
	while(!in_file.eof()){
		in_file >> a;
		in_file >> b;
		try{
			c=stol(curr);
		}
		catch(const invalid_argument& ia){
			v.push_back(stol(b));
			curr = a;
			continue;
		}
		if (curr == a){
			v.push_back(stol(b));
		}
		if (curr != a){
			c = stol(curr);
			ind_pair = make_pair(c,v);
			m.insert(ind_pair);
			v.clear();
			v.push_back(stol(b));
		}
		curr = a;
	}
 	return;


 }
    
 long select(default_random_engine &dre, vector<long> &container){
	uniform_int_distribution<long> distribution(1,container.size());		
	long myrand = distribution(dre);		//Generate random number.
	return container[myrand];			//Return the value at the random spot.
 }

 map<string, long> do_walk(map<long, vector<long> > &arc_map , map<long, string> &index_map, long total_walks ,long walk_length, default_random_engine &dre){

 	map<long,long> visit_count;
 	map<string, long> out_map;

	uniform_int_distribution<long> distribution(1,arc_map.size());	
	cout << arc_map.size()<<endl;
	long myrand = distribution(dre);		//Generate random number.
	long site;
	long count=0;
	long len_count=0;
	long vis_count = 0;
	pair<long,long> vis_pair;
	pair<string,long> str_vis_pair;
	cout <<"MYRAND: "<<myrand<<endl;
	auto arc_itr = arc_map.find(myrand);
	site = arc_itr->first;
	cout<<"OG SITE: "<<site<<endl;


 	while (count <= total_walks){

 		long myrand = distribution(dre);		//Generate random number.
 		auto arc_itr = arc_map.find(myrand);
 		cout <<"Trying to find site "<<myrand<<endl;
 		if(arc_itr == arc_map.end()){
 			cout<<"end of walk. , doesnt even exist."<<endl;
 		}

		while(len_count <= walk_length){

			long myrand = distribution(dre);

	 		if(arc_itr == arc_map.end()){
	 			cout<<"end of walk."<<endl;
	 			cout <<endl<<endl;
	 			break;
	 		}
			site = arc_itr->first;
			cout << "Site: "<<site<<endl;


	 		auto vis_itr = visit_count.find(site);
	 		if (vis_itr == visit_count.end()){
	 			cout <<"Time 1 at "<<site<<endl;
	 			cout<<endl;
	 			vis_pair = make_pair(site,1);
	 			visit_count.insert(vis_pair);
	 		}
	 		if (vis_itr != visit_count.end()){
	 			vis_itr->second++;
	 			vis_count = vis_itr->second;
	 			cout <<"Time "<<vis_count<<" at "<<site<<endl;
	 		}
	 		arc_itr = arc_map.find(select(dre,arc_itr->second));
	 		cout <<"New Site: "<< arc_itr->first <<endl;
	 		len_count++;

 		}	
 		len_count = 0;
 		count++;


 	}

 	for(auto q : visit_count){

 		string name = to_string(q.first);
 		long visits = q.second;
 		str_vis_pair=make_pair(name,visits);
 		out_map.insert(str_vis_pair);
 	}

 	return out_map;


 }

