// C++ Program to Find Prime Factors of a Number
#include <bits/stdc++.h>
using namespace std;

int main(){
    int num, i = 1, j, count;
    
    // Asking for input
    cout << "Enter any number to find prime factors: \n";
    cin >> num;
    
    //Checking weather number is prime or not
    while (i <= num){
        count = 0;
        if (num % i == 0){
            j = 1;
            while (j <= i){
                if (i % j == 0){
                    count++;
                }
                j++;
            }
            //Printing the output
            if (count == 2){
                cout << i << " is a prime factor";
            }
        }
        i++;
    }
    return 0;
}
