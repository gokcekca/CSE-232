//////////////////////////////////////////////////////////////
//Can Gokcek - Computer Project #3 - Narcissistic Numbers   //
//////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

void order_parameters(int &first, int &second){
    if (first > second){
        int third = first;      //Create new int temporarily.
        first = second;         //Put Second into First.
        second = third;         //Bring back first and put into second.
    }
}

bool narc_num(int num,int power){
    int nums[power-1];          //Initialize array of numbers.
    double total=0;             //Initialize double for total.
    int org_num = num;
    //Parse the number into individual digits, by taking the modulo with 10
    //as an individual digit, and then repeatedly dividing the original number
    //by 10 in order to get to the next digit.
    for(int i=0;i!=power;i++){
        nums[power-i-1] = num%10;
        num = int(num/10);
    }
    //Take each digit in the number, raise it to the power, and sum.
    for(int j = power;j>1-1;j--){
        total = total+(pow( double(nums[power-j]), double(power))) ;
    }
    //If the total is equal to the original number, it is narcissistic.
    if (total == org_num){
        return true;
    }
    else{
        return false;
    }       
}

int check_range(int first,int last,int power){
    order_parameters(first,last);       //Make sure parameters are in order.
    int total = 0;
    //Iterate through integers in the range, checking if they are narcissistic.
    for (int i = first;i<=last;i++){
        if (narc_num(i,power)){
            total++;
            cout << i<< " is a narcissistic number of order:"<< power<<endl;
        }    
    }
    return total;
}

int main(int argc, char** argv){
    int start;
    int stop;
    int power;
    int total_nn;
    cout << "Input start stop power:>> "<< endl;
    cin >> start >> stop>> power;
    //Loop through as long as input is not zero.
    while (start != 0 && stop != 0 && power != 0){
        total_nn = check_range(start,stop,power);
        cout << "Saw "<<total_nn<<" order "<<power<<" narc numbers in the ";
        cout << "in the range " << start<<" to "<< stop<<endl<<endl;
        cout << "Input start stop power:>> "<< endl;
        cin >> start >> stop>> power;
    }
    cout << "Thanks for playing!"<<endl;
    return 0; 
}