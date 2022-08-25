#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int arr[1000], arr2[3], n, i, sum = 0;
    cout << "Enter the size of the array : ";   cin >> n;                       //To take size of array to input
    cout << "\nEnter the elements of the array : ";                             //Array input
    for (i = 0; i < n; i++)
    cin >> arr[i];
    cout << "\nSum of array elements : " << accumulate(arr , arr+n , sum);      //Sum and Output
    cout<<"\nProduct: "<< accumulate(arr, arr+n, 1, multiplies<int>());         //Product and Output
    cout<<"\nSubtraction: "<< accumulate(arr, arr+n, 0, minus<int>()) << endl;  //Subtraction
    cout<<"Division: "<< accumulate(arr, arr+n, 1, divides<double>());             //Division
    return 0;
}