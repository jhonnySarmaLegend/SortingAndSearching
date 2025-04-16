// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    int arr[]={1,2,3,4,5,6,7,8,9}; // array must be sirted 1st condition
    int k =7;
    int l=0,h=sizeof(arr)/sizeof(arr[0])-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]>k)h=mid-1;
        else if(arr[mid]<k)l=mid+1;
        else { cout<<mid;break;}
    }
    //handle not found case also 
   return 0;
}

// T.C. = O(logN)
