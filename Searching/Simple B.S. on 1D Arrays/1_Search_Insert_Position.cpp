//https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    //edge case         
       if(nums[0]>target)return 0;
       if(nums[nums.size()-1]<target)return nums.size();
    //general flow  
        int ans=-1;
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=l+((h-l)/2);

            if(nums[mid]==target)return mid;
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{//nums[mid]>target  or smaleest number greater than target
                ans=mid;
                h=mid-1;
            }
        }

        return ans;
    }
};
