#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <iomanip>
#include <deque>
#include <algorithm>
#include "package.h"

using std::deque;
using std::ifstream;
using std::stringstream;
using std::cout;
using std::endl;
using std::stol;
using std::vector;
using std::string;
using std::sort;
using std::swap;
using std::copy;
//using package::package_compare;

#ifndef KNAPSACK_H
#define	KNAPSACK_H




class Knapsack{
 private:
  Package* data_;
  long weight_limit_;
  long capacity_;
  long size_;

 public:
  Knapsack(long max);
  bool add(Package p);
  bool empty();
  long weight();
  long priority();
  friend ostream& operator<<(ostream &, const Knapsack &);
  friend void solve_KS(vector<Package>& , Knapsack&);
  
  };

#endif /* KNAPSACK_H */

