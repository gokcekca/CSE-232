//////////////////////////////////////////////////////
//Can Gokcek - Computer Project #8 - Market         //
//////////////////////////////////////////////////////
#include "market.h"

Market::Market(){}

Market::Market(string a){
    Market(char *c[a.size()]);
}

Market::Market(char f[]){
    string a = string(f);       //Convert from char[] to string.
    ifstream in_file;           //ifstream object for opening file.
    vector<double> v;           //Vector for adding data to.
    in_file.open(a);            //Open file.
    string in_str;              //String for parsing document.       
    long id;                    //Long to store Stock ID.

    in_file >> in_str;          //Get first ID.

    id = stol(in_str);          //Convert to long from string.

    while (in_file >> in_str){  //Keep taking in data as long as there is data to input.
        if(in_str.size() > 7){  //If data size is greater than 7 (an ID), we're on the next line of data.
            pair<long, vector<double> > my_pair = make_pair(id,v);   //Make a pair from ID and the vector with data.
            stocks.insert(my_pair);      //Insert the pair into stocks.
            v.clear();           //Clear the vector for the next line of data.
            id = stol(in_str);    //Get next line's ID.
        }

        else{                  //If it is not an ID,
            v.push_back(stod(in_str));    //Put the data into the vector.
        }
    } 
    pair<long, vector<double> > last_pair = make_pair(id,v);    //Make a pair with the last line of data.
    stocks.insert(last_pair);                                   //Insert into map.
    in_file.close();                                            //Close file.

    
    ///HARDCODING MAP////
    pair<string , long > my_pair = make_pair("AA" , 0);id_map.insert(my_pair);
    my_pair = make_pair("AXP" , 1);id_map.insert(my_pair);
    my_pair = make_pair("BA" , 2);id_map.insert(my_pair);
    my_pair = make_pair("BAC" , 3);id_map.insert(my_pair);
    my_pair = make_pair("CAT" , 4);id_map.insert(my_pair);
    my_pair = make_pair("CSCO" , 5);id_map.insert(my_pair);
    my_pair = make_pair("CVX" , 6);id_map.insert(my_pair);
    my_pair = make_pair("DD" , 7);id_map.insert(my_pair);
    my_pair = make_pair("DIS" , 8);id_map.insert(my_pair);
    my_pair = make_pair("GE" , 9);id_map.insert(my_pair);
    my_pair = make_pair("HD" , 10);id_map.insert(my_pair);
    my_pair = make_pair("HPQ" , 11);id_map.insert(my_pair);
    my_pair = make_pair("IBM" , 12);id_map.insert(my_pair);
    my_pair = make_pair("INTC" , 13);id_map.insert(my_pair);
    my_pair = make_pair("JNJ" , 14);id_map.insert(my_pair);
    my_pair = make_pair("JPM" , 15);id_map.insert(my_pair);
    my_pair = make_pair("KFT" , 16);id_map.insert(my_pair);
    my_pair = make_pair("KO" , 17);id_map.insert(my_pair);
    my_pair = make_pair("MCD" , 18);id_map.insert(my_pair);
    my_pair = make_pair("MMM" , 19);id_map.insert(my_pair);
    my_pair = make_pair("MRK" , 20);id_map.insert(my_pair);
    my_pair = make_pair("MSFT" , 21);id_map.insert(my_pair);
    my_pair = make_pair("PFE" , 22);id_map.insert(my_pair);
    my_pair = make_pair("PG" , 23);id_map.insert(my_pair);
    my_pair = make_pair("T" , 24);id_map.insert(my_pair);
    my_pair = make_pair("TRV" , 25);id_map.insert(my_pair);
    my_pair = make_pair("UTX" , 26);id_map.insert(my_pair);
    my_pair = make_pair("VZ" , 27);id_map.insert(my_pair);
    my_pair = make_pair("WMT" , 28);id_map.insert(my_pair);
    my_pair = make_pair("XOM" , 29);id_map.insert(my_pair);
}



double Market::get_price(string stock, long date) {
    auto it = id_map.find(stock);          //Try to find the stock name in the ID map.
    auto stock_it = stocks.find(date);     //Try to find the price of a stock on a date in stocks map.
    if (it != id_map.end() && stock_it != stocks.end()){   //If the stock name exists, and there is data for the date,
        return stock_it->second[it->second];            //Return the value at the returned 
    }
    else{
        return -1.0;
    }
}

