//https://leetcode.com/problems/single-element-in-a-sorted-array/description/

//BINARY SEARCH APPROACH
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.

    //Edge cases:
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        //we are in the left:
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            //eliminate the left half:
            low = mid + 1;
        }
        //we are in the right:
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
    }
};



//BRUTE FORCE O(N)
 int singleNonDuplicate(vector<int>& nums) {
        int xr=0;
        for(auto it:nums)xr^=it;
        return xr;
    }



//OPTIMAL
    int singleNonDuplicate(vector<int>& nums) {
        // 1^1 =0 , 1^0=1
        // pairs will be in  {even,odd} indexes 

        int l = 0; //even index
        int h = nums.size() - 2; //even index
        
        while(l <= h){
            int mid = (l + h) / 2;// even+even/2 =even
            if(nums[mid] == nums[mid^1]){ //nums[even]==nums[even^1] or nums[even]==nums[odd]
                l = mid + 1; // sorted till now 
            }else{ // either present on mid or left to mid
                h = mid - 1;
            }
        }
        
        return nums[l];
    }



/*
In essence, mid^1 always gives you the other index that would form a pair with mid, assuming a standard (even_idx, odd_idx) pairing pattern.

Why nums[mid] == nums[mid^1] is the Key Condition
The problem states that every number appears twice, except for one. In a sorted array, these pairs will always be adjacent.

Consider the structure of the array around the non-duplicate element:

[pair, pair, ..., pair, SINGLE_ELEMENT, pair, pair, ..., pair]

Let's look at the indices:

Case 1: mid is part of a pair, and mid is at an even index.

Example: nums = [1, 1, 2, 3, 3, 4, 4]

Let mid = 0. nums[0] = 1.

mid^1 = 0^1 = 1. nums[1] = 1.

nums[0] == nums[1] is true.

This means nums[mid] is the first element of a pair, and nums[mid+1] is its match.

The pair (nums[mid], nums[mid+1]) is correctly formed. All elements before or including this pair are correctly paired up. The single non-duplicate element must be to the right of mid.

Case 2: mid is part of a pair, and mid is at an odd index.

Example: nums = [1, 1, 2, 3, 3, 4, 4]

Let mid = 3. nums[3] = 3.

mid^1 = 3^1 = 2. nums[2] = 2.

Wait, this example nums[3] = 3 and nums[2] = 2 doesn't illustrate this perfectly due to the non-duplicate at index 2. Let's use [1,1,2,2,3,3,4,4,5,5] for this case.

nums = [1, 1, 2, 2, 3, 3, 4, 4, 5, 5] (all pairs)

Let mid = 3. nums[3] = 2.

mid^1 = 3^1 = 2. nums[2] = 2.

nums[3] == nums[2] is true.

This means nums[mid] is the second element of a pair, and nums[mid-1] is its match.

The pair (nums[mid-1], nums[mid]) is correctly formed. All elements before or including this pair are correctly paired up. The single non-duplicate element must be to the right of mid.

In summary of these two cases:
If nums[mid] == nums[mid^1], it implies that nums[mid] is part of a valid pair that follows the (even_idx, odd_idx) pattern. This means all elements up to and including mid (or mid's pair) are correctly matched. Therefore, the single non-duplicate element must be in the part of the array to the right of mid. This is why we set l = mid + 1.

Case 3: nums[mid] is the single non-duplicate element itself, or the single non-duplicate is to its left.

Example: nums = [1, 1, 2, 3, 3, 4, 4]

Let mid = 2. nums[2] = 2. (This is the single non-duplicate).

mid^1 = 2^1 = 3. nums[3] = 3.

nums[2] == nums[3] is false (2 != 3).

This immediately tells us that nums[mid] is NOT paired with its expected adjacent element. This could mean one of two things:

nums[mid] is the single non-duplicate.

The single non-duplicate is somewhere to the left of mid, which has shifted the pairing pattern to the right of the non-duplicate. For example, if nums = [1, 2, 2, 3, 3], and mid is 1 (nums[1]=2). mid^1 is 0 (nums[0]=1). nums[1] != nums[0]. The single element is 1 (at index 0), which is to the left of mid.

In both these sub-cases, the search space must include mid itself or elements to its left. So, we set h = mid - 1.

How it drives the Binary Search
By repeatedly applying this logic:

If the current mid is part of a "normal" pair, we know the single element is to the right.

If the current mid is not part of a "normal" pair, the single element is either mid itself or to its left.

This effectively shrinks the search space ([l, h]) in each step by half, leading to the O(log N) time complexity typical of binary search algorithms. When the loop terminates (l > h), l will point to the index where the single non-duplicate element resides.

This elegant use of mid^1 combined with binary search is a very efficient and clever solution for this specific problem constraint.
*/
