#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums) 
{
    int result = 0;
    for(int num : nums)
    {
        result ^= num; // XOR operation
    }
    return result; // The single number will remain after all pairs cancel out
}
int main()
{
    vector<int> nums = {4,1,2,1,2,5,5};
    int result = singleNumber(nums);
    cout<< "The single number is: " << result << endl;
    return 0;
}