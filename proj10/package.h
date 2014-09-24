/* 
 * File:   package.h
 * Author: cangokcek
 *
 * Created on April 7, 2014, 9:21 PM
 */
 
#include <iostream>
 //#include "knapsack.h"
using std::ostream;
#ifndef PACKAGE_H
#define	PACKAGE_H

struct Package{
  long weight_;
  long priority_;
  Package(){};
  Package(long weight, long priority);
  friend ostream& operator << (ostream &, const Package &);
};
bool package_compare(const Package&, const Package&);




#endif	/* PACKAGE_H */

