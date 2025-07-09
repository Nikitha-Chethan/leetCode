#include <iostream>
#include <vector>

using namespace std;
class Solution{
    public:
    int trap(vector<int> &height)
    {
        int n= height.size();
        int result = 0;
        int l = 0, r = n-1;
        int lmax = 0, rmax = 0;
        while(l < r)
        {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if(lmax < rmax)
            {
                result += lmax - height[l];
                l++;
            }
            else{
                result += rmax - height[r];
                r--;
            }
        
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = sol.trap(height);
    cout << "Trapped rainwater: " << result << endl;
    return 0;   
}