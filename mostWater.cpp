#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int mostWater(vector<int> &height)
    {
        int maxWater = 0;
        int lp = 0, rp = height.size() -1;
        while(lp < rp)
        {
            int w = rp - lp;
            int h = min(height[lp], height[rp]);
            int currWater = w * h;
            maxWater = max(maxWater, currWater);
            height[lp] < height[rp] ? lp++ : rp--; // Move the pointer of the shorter line

        }
        return maxWater;   
    }
};

int main()
{
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int result = sol.mostWater(height);
    cout << "Maximum water that can be contained: " << result << endl;
    return 0;
}