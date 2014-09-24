//////////////////////////////////////////////////////
//Can Gokcek - Computer Project #4 - Lychrel Numbers//
//////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::stol;
using std::out_of_range;

long rev_num(long n){
    string n_str;
    string new_str;
    long n_reversed;
    n_str = to_string(n);       //Convert to string.
    //Iterate through all characters in reverse order and add them to a new string.
    for (string::reverse_iterator r=n_str.rbegin(); r!=n_str.rend(); ++r){
        new_str.push_back(*r);
    }
    try{
        n_reversed = stol(new_str);     //Try to convert the string back to a long.
    }
    catch(const out_of_range& oor){
        cout <<"Whoa, dude. You've overflowed a long!"<<endl;       //Catch the exception that may occur.
    }
    return n_reversed; 
}

bool is_palindrome(long n){
    if (n == rev_num(n))
        return true;
    else
        return false;
}

void order_parameters(long &first, long &second){
    if (first > second){
        long third = second;
        second = first;
        first = third;
    }
    return;
}

bool check_lychrel(long n, long limit){
    long sum = n;
    int i = 0; 
    //Continuously check if current number is a palindrome,
    //and add to it it's reverse if it is not.
    while (i <= limit){
        if (is_palindrome(sum) && sum!=0 && i > 1)
            return false;
        else
            sum += rev_num(sum);
        i++;
    }
    return true;
}

long check_range(long start, long end, long limit, long &natural_cnt, long &pal_cnt){
    order_parameters(start,end);       //Make sure parameters are in order.
    long total = 0;
    //Iterate through all integers in range.
    for (int i = start;i<=end;i++){
        if (is_palindrome(i)){      //Check if it is a palindrome.
            natural_cnt++;          //If so, add to the count.
        }
        else if (check_lychrel(i,limit) == false){      //Check if it is not lychrel.
            pal_cnt++;                                  //If so, add to palindrome count.
        }
        if (check_lychrel(i,limit) == true){            //Check if it is lychrel.
            cout << "Found a lychrel number: "<< i<<endl;                //If so, output the value and add
            total++;                                    //to the total.
        }
    }
    return total;
}

int main(int argc, char** argv){
    long start;
    long end;
    long limit;
    long natural=0;
    long pal=0;
    long count=0;
    while (true){
        cout << "Provide first last limit all greater than 1."<<endl;
        cin >> start>>end>>limit;
        if(start>=1 && end >=1 && limit >=1)
            break;
        cout<<"Try again. ";
    }
    count = check_range(start,end,limit,natural,pal);
    cout << "Summary for range "<<start<<", "<<end<<" with limit "<<limit<<endl;
    cout << "Lychral count: "<<count<<endl;
    cout << "Natural count: "<<natural<<endl;
    cout << "Palindrome count: " << pal<<endl;
    return 0; 
}