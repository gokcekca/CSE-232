#include "market.h"
#ifndef PLAYER_H
#define	PLAYER_H

struct Player {
    double cash;
    
    map<string, long> stocks;
    
    Player();
    
    Player(double c);

    bool buy(Market &, string, long, long);
    
    bool sell (Market &, string,long,long);
    
    string to_str();
    
  
};


#endif	/* PLAYER_H */

