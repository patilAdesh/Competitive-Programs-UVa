#include <iostream>
using namespace std;

int main() {
    int number,pos_of_factor,i,c=0;
    cin>>number;
    cin>>pos_of_factor;
    for(i=number;i>=1;i--){
        if((number%i)==0)
        c++;
        if(c==pos_of_factor){
            cout<<i;
            break;
        }
    }
    if(c<pos_of_factor)
        cout<<1;
    return 0;
}