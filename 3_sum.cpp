#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {
        int n= arr.size();
        vector<vector<int>> result;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && arr[i] == arr[i-1]) continue; // skip duplicates for first element
            int j = i+1, k = n-1;
            while(j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if(sum < 0)
                {
                    j++;
                }
                else if(sum > 0)
                {
                    k--;
                }
                else
                {
                    result.push_back({arr[i], arr[j], arr[k]});
                    while(j < k && arr[j] == arr[j+1]) j++; // skip duplicates for second element
                    while(j < k && arr[k] == arr[k-1]) k--; // skip duplicates for third element
                    j++;
                    k--;
                }
            }
        }
        {

        }
        return result;
    }
};

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    vector<vector<int>> result = sol.threeSum(arr);
    for(const auto &triplet : result)
    {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    if(result.empty())
    {
        cout << "No triplets found" << endl;
    }
    else
    {
        cout << "Triplets found" << endl;
    }
    cout << "Total triplets found: " << result.size() << endl;
    return 0;
}