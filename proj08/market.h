#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>
#include <map>
#include <vector>
#include <iomanip>

using std::ifstream;
using std::to_string;
using std::stringstream;
using std::cout;
using std::endl;
using std::stol;
using std::vector;
using std::map;
using std::make_pair;
using std::pair;
using std::stod;
using std::setprecision;
using std::string;

#ifndef MARKET_H
#define	MARKET_H

struct Market {
    map<long, vector<double> > stocks;
    map <string,long> id_map;
    Market();
    Market(string s);
    Market(char f[]);

    double get_price(string, long);
  
};


#endif	/* MARKET_H */

