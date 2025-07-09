#include<iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution{
    public:
    int maxSubarray(vector<int> &nums)
    {
        int currSum=0, maxSum=INT_MIN;
        for(int val: nums)
        {
            currSum += val;
            maxSum = max(currSum,maxSum);
            if(currSum < 0)
            {
                currSum = 0; // Reset current sum if it goes negative
            }
        }
        return maxSum;
    }
};
int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    int result = sol.maxSubarray(nums);
    cout<<result<<endl;
    return 0;
}