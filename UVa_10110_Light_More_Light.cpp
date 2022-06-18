#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    
    cout<<"Enter the number of bulbs: \n"; cin>>n;
    
    if(n==0) 
        cout<<"Enter a valid number";
        
    x=sqrt(n);
        
    if(n==x*x)
        cout<<"yes\n";
    else
        cout<<"no\n";

    return 0;
}
