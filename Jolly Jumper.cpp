#include <bits/stdc++.h>
using namespace std;

int main(){

    int ar[10],ar2[10],n;
    while(cin >> n){
        for(int i = 0; i < n; i++)cin >> ar[i];
        int k = 1;
        for(int i = 1; i < n;i++){
            ar2[k++] = abs(ar[i]-ar[i-1]);
        }
        sort(ar2, ar2+k);
        bool ok = true;
        for(int i = 1; i < k; i++){
            if(ar2[i] != i){
                ok = false;
            }
        }
        if(ok)cout << "Jolly";
        else cout << "Not jolly";
    }
    return 0;
}