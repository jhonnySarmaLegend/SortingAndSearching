#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    int arr[]={1,2,3,4,5,6,7,8,9};
    int k =7;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)if(arr[i]==k)cout<<i;
    return 0;
}

// T.C. = O(N)
