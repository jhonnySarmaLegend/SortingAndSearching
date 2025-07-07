// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
                        
        int ans = INT_MAX ;
        int l = 0, h = nums.size()-1 ;
        while(l <= h){
            int mid = l + (h-l) / 2 ;
            // find the sorted half
            if(nums[l] <= nums[mid]){ 
                 //left half sorted ,  nums[l] will be minimum
                ans = min(ans, nums[l]) ;
                l = mid + 1 ;
            }
            else{
                // if right half sorted, nums[mid] will be minimum
                ans = min(ans, nums[mid]) ;
                h = mid - 1 ;
            }
        }
        return ans ;
    }
};
