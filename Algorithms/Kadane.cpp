/*
Given an array of integers, the task is to
find the maximum subarray sum possible of all the non-empty subarrays.
Input: [-3, -4, 5, -1, 2, -4, 6, -1]
Output: 8
Explanation: Subarray [5, -1, 2, -4, 6] is the max sum contiguous subarray with sum 8.
Approach::******************
Kadane’s Algorithm is an iterative dynamic programming algorithm.
It calculates the maximum sum subarray ending at a particular position by
using the maximum sum subarray ending at the previous position.
Follow the below steps to solve the problem.
Steps:::***************
Define two-variable currSum which stores maximum sum ending here and maxSum which stores maximum sum so far.
Initialize currSum with 0 and maxSum with INT_MIN.
Now, iterate over the array and add the value of the current element to currSum and check
If currSum is greater than maxSum, update maxSum equals to currSum.
If currSum is less than zero, make currSum equal to zero.
Finally, print the value of maxSum.
*/

#include "bits_stdcpp.h"
using namespace std;
int maximumSubarraySum(vector<int> arr)
{
    int n = arr.size();
    int maxSum = INT_MIN;
    int sum_of_subarray = 0;
    for (int i = 0; i < n; i++)
    {
        sum_of_subarray += arr[i];
        if (maxSum < sum_of_subarray)
            maxSum = sum_of_subarray;
        if (sum_of_subarray < 0)
            sum_of_subarray = 0;
    }

    return maxSum;
}

int main()
{
    ios_base::sync_with_stdio(false); // Avoids synchronization
    cin.tie(NULL);                    // Avoids flushing
    vector<int> array = {1, 3, 8, -2, 6, -8, 5};
    ;
    cout << "Maximun sum of subarray of given array is :";
    cout << maximumSubarraySum(array) << '\n';
    return 0;
}
// Time complexity: O(N)
//Space complexity: O(1)
/*
Similar Problem:
Maximum difference of 0's and 1's in a binary string,
Maximum Sum Circular array,
Smallest sum contiguous subarray,
Largest sum increasing contiguous subarray,
Maximum Product Subarray,
Largest sum contiguous subarray with only non-negative elements.
Largest sum contiguous subarray with unique elements.
Maximum Alternating Sum Subarray,
Maximum Sum Rectangle In A 2D Matrix.

*/