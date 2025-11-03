//https://leetcode.com/problems/search-insert-position/description/
int searchInsert(vector<int>& nums, int target) {
        // Array is sorted
        if(target<nums[0])return 0; // EDGE case 1
        if(target>nums[nums.size()-1])return nums.size(); // EDGE case 2
        
        int ans=-1;
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(high-low)/2 + low;

            if(nums[mid]==target)return mid;
            else if(nums[mid]>target){ans=mid;high=mid-1;}//nums[mid]>target  or smaleest number greater than target
            else low=mid+1;
        }
        return ans;
    }

