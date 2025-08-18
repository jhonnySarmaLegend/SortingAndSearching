#include <bits/stdc++.h>
using namespace std;

void binRec(int arr[], int low, int high,int k){
    int mid=(low+high)/2; // or l+ (h-l)/2
    
    if(arr[mid]>k)binRec(arr,low,mid-1,k);
    else if(arr[mid]<k)(arr,mid+1,high,k);
    else {cout<<mid;return;}
}

int main() {
    // Write C++ code here
    int arr[]={1,2,3,4,5,6,7,8,9}; // array must be sirted 1st condition
    int k =7;
    int l=0,h=sizeof(arr)/sizeof(arr[0])-1;
    binRec(arr,l,h,k);
    //handle not found case also 
   return 0;
}

// T.C. = O(logN)
