#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    cout << "Try programiz.pro\n";
    
    vector<int> arr={3,2,1,1,2,3};
    cout<<"Before Sorting : {";
    for(auto it:arr)cout<<it<<" ";
    cout<<"}\n";
    
    int n=arr.size();
    
    // (SELECTION SORT)
    // for(int i=0;i<n-1;i++){
    //     int mini=i;
        
    //     for(int j=i+1;j<n;j++){
    //         if(arr[j]<arr[mini])mini=j;
    //     }
        
    //     if(mini!=i)swap(arr[mini],arr[i]);
        
    // }
    // cout<<"After Sorting : {";
    // for(auto it:arr)cout<<it<<" ";
    // cout<<"}\n";
    
    // (BUBBLE SORT)
    // for(int i=0;i<n-1;i++){
    //     for(int j=0;j<n-i-1;j++){
    //         if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);
    //     }
    // }
    // cout<<"After Sorting : {";
    // for(auto it:arr)cout<<it<<" ";
    // cout<<"}\n";
    
    
//     (Insertion Sort)
//   for(int i=0;i<n;i++){
//       for(int j=0;j<=i;j++){
//           if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);
//       }
//   }
//       cout<<"After Sorting : {";
//     for(auto it:arr)cout<<it<<" ";
//     cout<<"}\n";


    return 0;
}