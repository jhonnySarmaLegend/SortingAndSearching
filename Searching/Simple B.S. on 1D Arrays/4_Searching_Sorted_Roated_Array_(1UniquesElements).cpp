
//https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0; // Changed from 'low'
        int h = n - 1; // Changed from 'high'
        while (l <= h) {
            // Calculate mid to prevent potential integer overflow
            int mid = l + (h - l) / 2; // Better way than (l+h)/2
            if (nums[mid] == target) {
                return mid; // Target found
            }
            // Determine which half is sorted
            // Case 1: Left half is sorted (nums[l] to nums[mid])
            if (nums[l] <= nums[mid]) {
                // Check if target lies within this sorted left half
                if (nums[l] <= target && target < nums[mid]) { // Use < nums[mid] for range -- NOT INCLUDED , target <=nums[mid] , since already checked nums[mid] == target
                    h = mid - 1; // Target is in the left sorted half
                } else {
                    l = mid + 1; // Target is in the right unsorted half
                }
            }
            // Case 2: Right half is sorted (nums[mid] to nums[h])
            else { // nums[mid] > nums[h] implies right half is sorted
                // Check if target lies within this sorted right half
                if (nums[mid] < target && target <= nums[h]) { // Use > nums[mid] for range  -- NOT INCLUDED , nums[mid] <=target, since already checked nums[mid] == target
                    l = mid + 1; // Target is in the right sorted half
                } else {
                    h = mid - 1; // Target is in the left unsorted half
                }
            }
        }
        return -1; // Target not found
    }
};
