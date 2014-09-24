//////////////////////////////////////////////////////
//Can Gokcek - Computer Project #8 - Player         //
//////////////////////////////////////////////////////
#include "player.h"
#include "market.h"

Player::Player(){
    cash = 0;
}

Player::Player(double c){
    cash = c;
}
bool Player::buy(Market &m, string stock, long date, long quantity){

    double value = m.get_price(stock,date);
    //If the get price function returns a valid amount, and cash is greater than the price,
    if (value != -1.0 && cash >= value*quantity){
        value *= quantity;                        //Multiply value by quantity for price.
        cash -= value;                            //Subtract the price from cash.
        auto map_it = stocks.find(stock);          //Find the stock name in owned stocks map.
        if (map_it == stocks.end()){               //If not found,
            pair<string, long> my_pair = make_pair(stock,quantity);    //Create pair from stock name and quantity.
            stocks.insert(my_pair);                //Insert pair into map.
            return true;
        }
        else{                                        //If already owned,
            stocks.find(stock)->second += quantity;    //Increase quantity owned.
            return true;
        }
        return true;
    }
    return false;
}
    
bool Player::sell (Market &m, string stock, long date, long quantity){

    double value = m.get_price(stock,date);        //Get the price for stock on date.
    auto player_it = stocks.find(stock);        //Find the stock name in owned stocks map.
    //If the get price function returns a valid amount, and player owns the stock,
    if (player_it != stocks.end() && value != -1.0){
        value *=quantity;                        //Multiply value by quantity for price.
        if (stocks.find(stock)->second >= quantity){    //If player has enough to sell,
            cash += value;                                //Add to cash.
            stocks.find(stock)->second -= quantity;        //Subtract from amount owned.
            return true;
        }
    }
    return false;
        
}
    
string Player::to_str(){
    string out = "Player has: " + to_string(cash) + " dollars, Stocks are: \n";
    for (auto l : stocks){    //Iterate through owned stock map, and output.
        out += l.first + ", quantity " + to_string(l.second) + "\n";
    }
    return out;

    
        
}
