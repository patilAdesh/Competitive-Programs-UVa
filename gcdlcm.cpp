#include <bits/stdc++.h>
using namespace std;

int gcd(int u, int v)
{
    return (v != 0) ? gcd(v, u % v) : u;
}

int main()
{
    int num1, num2, result;
    cout << "Enter two numbers to find GCD using Euclidean algorithm: ";
    cin >> num1 >> num2;
    result = gcd(num1, num2);
    if (gcd)
        cout << "\nThe GCD of " << num1 << " and " << num2 << " is: " << result
                << endl;
    else
        cout << "\nInvalid input!!!\n";
        
    int lcm = num1 * num2 / result;
    cout<<"LCM= "<<lcm;
    return 0;
}