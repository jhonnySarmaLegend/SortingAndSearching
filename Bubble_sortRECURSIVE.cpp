#include <bits/stdc++.h>
using namespace std;

void bubbleRec(vector<int> &arr,int n){
    if (n == 1) return;
    for (int j = 0; j < n - 1; j++) {
        if (arr[j] > arr[j + 1])swap(arr[j],arr[j+1]);
    }
    //Range reduced after recursion:
    bubbleRec(arr, n - 1);
}

int main() {
    vector<int> arr={3,2,1,1,2,3};
    cout<<"Before Sorting : {";
    for(auto it:arr)cout<<it<<" ";
    cout<<"}\n";  
    int n=arr.size();
    bubbleRec(arr,n);
    cout<<"After Sorting : {";
    for(auto it:arr)cout<<it<<" ";
    cout<<"}\n";
    return 0;
}
