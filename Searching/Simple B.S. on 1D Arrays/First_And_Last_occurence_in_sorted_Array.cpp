//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
  int last(vector<int>& nums, int target){
     int ans=-1;
     int l=0,h=nums.size()-1;
     while(l<=h){
        int mid= l +((h-l)/2);

        if(nums[mid]==target){
            ans=mid;l=mid+1;
        }
        else if(nums[mid]<target)l=mid+1;
        else h=mid-1;
     }
     return ans;
   }

   int first(vector<int>& nums, int target){
     int ans=-1;
     int l=0,h=nums.size()-1;
     while(l<=h){
        int mid= l +((h-l)/2);

        if(nums[mid]==target){
            ans=mid;h=mid-1;
        }
        else if(nums[mid]<target)l=mid+1;
        else h=mid-1;
     }
     return ans;
   }


// VARIATION --> COUNT No. of occurences of a number in a sorted array containing duplicate elements
return ans= last-first+1;

    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target),last(nums,target)};
    }
};
