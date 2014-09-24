//////////////////////////////////////////////////////////////
//Can Gokcek - Computer Project #2 - Goldbach's Conjecture  //
//////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

//Function to test if an integer is a prime number.
bool is_prime(int p){
    //0, 1, and 2 are not primes.
    if (p < 2){
        return false;
    }
    //Iterate through a list of integers less than the number,
    //checking if the number is evenly divisible by that integer.
    //If it is, then the number is not a prime.
    for(int i=2 ; i < p ; i++){
    	if (p % i == 0){
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv){
    int num;
    int first;
    int second;
    bool flag;
    cout << "Give me an even number >= 4 or 0 to quit:" << endl;
    cin >> num;
    if(num == 0){
        cout <<"THANKS FOR PLAYING!"<<endl;
        return 0;   
    }      
    
    while(num < 4 || num % 2 != 0){
        cout << "DID YOU READ THE INSTRUCTIONS?!?!"<<endl;  
        cout<<"Just in case: 'Give me an even number >= 4 or 0 to quit:'"<<endl; 
        cin >>num;
    }
    //Outside loop for first number:
    for(int m = 2; m <= num; m++){
        //Inside loop for second number:
    	for(int n = 2; n <= num; n++){
            //Check if the two numbers add up to input:
            if(n+m == num){
                //Check if both numbers are primes:
                if (is_prime(n) && is_prime(m)){
                    first = m;
                    second = n;
                    flag = true;
                    break;
                }
            }       
        }
        if (flag == true){
            break;
        }   
    }
    cout << "The number " << num << " is the sum of the primes: ";
    cout << first << " and "<< second<<endl;
}