#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define lli long long int
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

//-------------function to implement the heapify function
void heapify(int arr[],int n,int ind){
    int par = ind;
    int left = 2*ind+1,right=2*ind+2;

    if(left < n&&arr[left]> arr[par]) par = left;

    if(right < n && arr[right] > arr[par]) par = right;

    //update parent
    if(par != ind){
        swap(arr[par],arr[ind]);
        heapify(arr,n,par);
    }
}

//------------function to implment heapsort in o(nlogn)

void heapSort(int arr[],int n){

    //1. build the heap
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    

    //Now apply to sort the heap
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);

        heapify(arr,i,0);
    }

}

//print the heap
void print(int arr[],int n){
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout <<endl;
}


//--------------- Main function to running the program
int main() {
    
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = 6;

    //--------- Sort the heap in increasing order
    cout << "Heap sort"<<endl;
    heapSort(arr,n);

    //------------ Print sorted array
    cout << "Printing sorted array "<<endl;
    print(arr,n);

    return 0;
}