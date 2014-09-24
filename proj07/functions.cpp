//////////////////////////////////////////////////////
//Can Gokcek - Computer Project #7 - Implementation //
//////////////////////////////////////////////////////
#include "functions.h"


string lower_and_strip(string s){
    string target = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";   //Set up string with all allowed chars.
    size_t start = s.find_first_of(target);                                             //Set up size_t for position of first allowed char.
    size_t end = s.find_last_of(target);                                                //Set up size_t for position of last allowed char.
    string out = "";                                                                    //Set up empty string.
    if (start != -1){                                                                   //If start is within the bounds of the string,
        string pre_out = s.substr(start,end-start+1);                                   //Create substring within the two positions.
        for (auto c : pre_out){                                                         //Iterate through all chars, and lowercase them.
    	   out += tolower(c);
        }
    }
    return out;
}

void read_stopwords(vector<string> &v , string file_name){
	string a;                  //Initialize empty string.
	ifstream in_file;          //Initialize ifstream to open file.
	in_file.open(file_name);   //Open file.
	while (!in_file.eof()){    //While not at the end of the file,
		in_file >> a;          //Put data from file into a.
		v.push_back(a);        //Put data from a into the vector.
	}
	in_file.close();           //Close file.
}

void read_file(map<string,long> &m, vector<string> &stop_list, string file_name){
    string a;                                                       //Initialize empty string.
    ifstream in_file;                                               //Initialize ifstream to open file.
    in_file.open(file_name);                                        //Open file.
    while (!in_file.eof()){                                         //While not at end of file,
        in_file >> a;                                               //Put data from file into a.
        a = lower_and_strip(a);                                     //Lowercase and strip the string in a.
        auto it = find( stop_list.begin(), stop_list.end(), a);     //Try to find the word in the stopwords vector.
        if (it == stop_list.end() && a != ""){                      //If it is not there, and it is not a blank string,
            if(m.find(a) == m.end()){                               //If it is not in the map,
                pair<string,long> my_pair = make_pair(a,1);         //Create a pair from the string and 1.
                m.insert(my_pair);                                  //Insert the pair into the map.
            }
            else{                                                   //If it is in the map,
                m.find(a)->second +=1;                              //Increment its count.
            }
        }
    }
    in_file.close();                                                //Close the file.
}

string pair_to_string(pair<string,long> p){
  ostringstream oss;                //Initialize ostringstream for putting data into.
  oss << p.first <<":"<<p.second;   //Put data in, as "first : second".
  return oss.str();                 //Return as a string.
}

bool smaller_count(pair<string,long> first, pair<string,long> second){
    if (first.second == second.second){         //If first pair's count is equal to second pair's count,
        if (first.first < second.first){        //If first pair's first letter is less than second pair's first letter,
            return true;                        //First is smaller.
        }
        else{                                   //Otherwise,
            return false;                       //Second is smaller.
        }
    }
    else if (first.second < second.second){     //If first's count is less than second's count,
        return true;                            //First is smaller.
    }
    else{                                       //In any other case,
        return false;                           //Second is smaller.
    }
}

string print_map(map<string,long> &m , string order){
    vector< pair<string,long> > v;          //Initialize vector of pairs.
    ostringstream Out;                      //Initialize ostringstream to output to.
    string out_string;                      //Initialize empty output string.
    for(auto c : m){                        //For every pair of elements in the map,
        v.push_back(c);                     //Put it in the vector of pairs.
    }
    if(order == "alpha"){                   //If order is alpha,
        sort(v.begin(),v.end());            //Sort by default argument.
    }
    else if(order == "count"){              //If order is count,
        sort(v.begin(),v.end(),smaller_count);  //Sort by smaller_count function.
    }
    //Use transform to put all elements in vector into the ostream using the pair_to_string function:
    transform(v.begin(), v.end(), ostream_iterator<string>(Out, ", "), pair_to_string); 
    return Out.str().substr(0, Out.str().size() - 1);  //Return a substring from beginning to one before the end.
}

vector<string> sorted_words(map<string,long> &m){
    vector<string> v;           //Initialize empty vector of strings.
    for(auto c : m){            //For every pair of elements in the map,
        v.push_back(c.first);   //Put the string in the vector of strings.
    }
    sort(v.begin(),v.end());    //Sort the vector from beginning to end.
    return v;
}

