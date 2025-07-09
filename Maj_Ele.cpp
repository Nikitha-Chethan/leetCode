#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 
class Solution{
    public:
    int majorityElement(vector<int>& nums) 
    {
        int freq;
        int n= nums.size();
        for(int num: nums)
        {
            freq=0;
            for(int ele: nums)
            {
                if(ele == num)
                    freq++;
                if(freq > n/2)
                return num;
            }
        }
    }
};
*/
/*
class Solution{
    public:
    int majorityElement(vector<int>& nums) 
    {
        int freq, ans=nums[0];
        int n= nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i] == nums[i-1])
                freq++;
            else
            {
                freq =1;
                ans = nums[i];
            }
            if(freq > n/2)
                return ans;
            
        }
    }
};
*/
class Solution{
    public:
    int majorityElement(vector<int>&nums )
    {
        int freq=0, ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(freq == 0)
            {
                ans = nums[i];
            }
            if(nums[i] == ans)
            {
                freq++;
            }
            else
            {
                freq--;
            }
        }
        int count =0;
        for(int num: nums)
        {
            if(num == ans)
            {
                count++;
            }
        }
        if(count > nums.size()/2)
        {
            return ans;
        }
        else
        {
            return -1; // No majority element found
        }
     
    }

};
int main()
{
    Solution sol;
    vector<int> arr={2,2,1,1,1};
    int result= sol.majorityElement(arr);
    cout<<result<<endl;
    return 0;
}