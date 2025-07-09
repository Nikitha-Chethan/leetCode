#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num: nums)
        {
            if(seen.find(num) != seen.end())
                return num;
            seen.insert(num);
        }
        return -1;
    }
};
*/
class Solution{
    public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        // Phase 1: Finding the intersection point
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        // Phase 2: Finding the entrance to the cycle
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow; // or fast, both are the same at this point
    }
};
int main()
{
    Solution sol;
    vector<int> arr={1,2,2,4,3};
    int res= sol.findDuplicate(arr);
    cout<<res<<endl;
}