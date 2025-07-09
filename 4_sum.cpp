#include <iostream>
#include <vector>
# include <algorithm>
using namespace std;
class Solution{
    public:
    vector<vector<int>> fourSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> result;
        if(n < 4) return result; // Not enough elements for quadruplets

        sort(arr.begin(), arr.end()); // Sort the array to handle duplicates and use two pointers

        for(int i = 0; i < n - 3; i++)
        {
            if(i > 0 && arr[i] == arr[i - 1]) continue; // Skip duplicates for first element
            for(int j = i + 1; j < n - 2; j++)
            {
                if(j > i + 1 && arr[j] == arr[j - 1]) continue; // Skip duplicates for second element
                int p = j + 1, q = n - 1;
                while(p < q)
                {
                    long long sum = static_cast<long long>(arr[i]) + arr[j] + arr[p] + arr[q];
                    if(sum < target)
                    {
                        p++;
                    }
                    else if(sum > target)
                    {
                        q--;
                    }
                    else
                    {
                        result.push_back({arr[i], arr[j], arr[p], arr[q]});
                        while(p < q && arr[p] == arr[p + 1]) p++; // Skip duplicates for third element
                        while(p < q && arr[q] == arr[q - 1]) q--; // Skip duplicates for fourth element
                        p++;
                        q--;
                    }
                }
            }
        }
        return result;
    }

};

int main()
{
    vector<int> arr= {-2,-1,-1,1,1,2};
    Solution sol;
    int target = 0;
    vector<vector<int>> result = sol.fourSum(arr, target);
    for(const auto &quadruplet : result)
    {
        cout << "[" << quadruplet[0] << ", " << quadruplet[1] << ", " << quadruplet[2] << ", " << quadruplet[3] << "]" << endl;
    }   
    if(result.empty())
    {
        cout << "No quadruplets found" << endl;
    }
    else
    {
        cout << "Quadruplets found" << endl;
    }   
    cout << "Total quadruplets found: " << result.size() << endl;
    cout << "Target: " << target << endl;   

    return 0;
}