#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr,int n){
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini])mini=j;
        }
        if(i!=mini)swap(arr[i],arr[mini]);
    }
}

void bubbleSort(vector<int> &arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])swap(arr[j+1],arr[j]);
        }
       
    }
}

void bubbleSortRec(vector<int> &arr,int n){
   if(n==1)return;
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1])swap(arr[j+1],arr[j]);
        }
       bubbleSortRec(arr,n-1);//sorts 1 element from end hence reducing search space by 1
    
}

void insertionSort(vector<int> &arr,int n){
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
}}


int main() {
   vector<int> arr={7,4,1,8,5,2,9,6,3};
   cout<<"Before Sorting : [ ";
   for(auto it:arr)cout<<it<<" ";
   cout<<"]\n";
   
   int n=arr.size();
   // Sorting Algorithm
   
   //Selection sort
   //selectionSort(arr,n);
   
   //Bubble sort
   //bubbleSort(arr,n);
   
   //Bubble sort Recursive
   //bubbleSortRec(arr,n);
   
   //Insertion Sort
   //insertionSort(arr,n);
   
   cout<<"After Sorting : [ ";
   for(auto it:arr)cout<<it<<" ";
   cout<<"]\n";

    return 0;
}
