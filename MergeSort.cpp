//T.C. =O(NlogN)
//S.C.= O(N) --> temp array + auxillary stack space ~ O(N)


// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void   Merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    
    while(left<=mid && right<=high ){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
        }
    }
    
    while(left<=mid ){
            temp.push_back(arr[left++]);
    }
    while(right<=high ){
        temp.push_back(arr[right++]);
    }
    
     for(int i=low;i<=high;i++){
         arr[i]=temp[i-low];
     }
    
    
}

void mergeSort(vector<int> &arr,int low,int high){
    // if(low>=high)return; or  low ==high no element, 
    if(low<high){
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
    }
}



int main() {
   vector<int> arr={10,20,5,10,11,45,28};
   cout<<"Before Sorting : [ ";
   for(auto it:arr)cout<<it<<" ";
   cout<<"]\n";
   
   int n=arr.size();
   mergeSort(arr,0,n-1);
   
   cout<<"After Sorting : [ ";
   for(auto it:arr)cout<<it<<" ";
   cout<<"]\n";

    return 0;
}
