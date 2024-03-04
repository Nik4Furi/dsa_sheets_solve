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



//------------ heapify function, put ind in its correct index
void heapify(int arr[],int n,int ind){
    int par = ind;
    int left = 2*ind+1;
    int right = 2*ind+2;

    if(left < n && arr[left] > arr[par])
        par = left;

    if(right < n && arr[right] > arr[par])
        par = right;

    //check par is update
    if(par != ind){

        swap(arr[par],arr[ind]);

        //call 
        heapify(arr,n,par);
    }
}

//--------------- function to implment the heap
void buildHeap(int arr[],int n){
    int st = n/2-1; //not traverse its leaf nodes

    for(int i=st;i>=0;i--)
        heapify(arr,n,i); // put element current ind in its right place
}

//--------function to print the heap
void print(int arr[],int n){
    for(int i=0;i<n;i++)
        cout << arr[i]<< " ";
    cout << endl;
}


//--------------- Main function to running the program
int main() {
   int n = 11;

   int arr[n] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

  cout << "Build heap "<<endl;
   buildHeap(arr,n);

   //print heap

   cout << "Printing the max-heap"<<endl;
   print(arr,n);

   return 0;
}