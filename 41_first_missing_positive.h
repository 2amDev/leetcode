#pragma once

#include <vector>
#include <algorithm>

/*
* 41. First Missing Positive
* Given an unsorted integer array nums, return the smallest missing positive integer.
* You must implement an algorithm that runs in O(n) time and uses constant extra space.
* 
* Constraints:
* 1 <= nums.length <= 105
* -231 <= nums[i] <= 231 - 1
*/

int firstMissingPositive(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  
  int positive = 0;
  int last = 0;

  for (int num : nums)
  {
    /* ignore duplicate repeating numbers */
    if (last == num)
      continue;
    last = num;

    /* if positive & not equal to last encountered missing pos then return */
    if (num > 0)
      if (num != ++positive)
        return positive;
  }
  return ++positive;
}
