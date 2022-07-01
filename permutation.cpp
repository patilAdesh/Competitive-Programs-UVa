#include<bits/stdc++.h>
using namespace std;

void permute(string a, int l, int r)
{
    if(l==r)
        cout<<a<<"\n";
    else
    {
        for(int i=0; i<=r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l+1, r);
            swap(a[l],a[i]);
        }
    }
}
int main()
{
    string a;
    
    cout<<"\nEnter a string: ";
    cin>>a;
    
    int n = a.size();
    permute(a,0,n=1);
    return 0;
}