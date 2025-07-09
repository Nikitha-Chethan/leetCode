#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class solution{
    public:
    vector<int> FindDupli_Missing(vector<vector<int>>& grid)
    {
        vector<int> result;
        unordered_set<int> seen;
        int n = grid.size();
        int a,b;
        int expSum=0, actSum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                actSum += grid[i][j];
                if(seen.find(grid[i][j]) != seen.end())
                {
                    a = grid[i][j];//duplicate found
                    result.push_back(a);
                }
                seen.insert(grid[i][j]);
            }
        }
        expSum = (n*n)*(n*n+1)/2;
        b= expSum + a - actSum;
        result.push_back(b);
        return result;
    }
};
int main()
{
    solution sol;
    vector<vector<int>> grid = {
        {9, 1, 7},
        {8, 9, 2},
        {3, 4, 6}
    };
    vector<int> result = sol.FindDupli_Missing(grid);
    for(int num: result)
    {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
