#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = n-1;
        while(r < m && c >= 0)
        {
            if(target == matrix[r][c])
                return true;
            else if(target < matrix[r][c])
            {
                c--;
            }
            else{
                r++;
            }
        }
        return false;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60},
        {60, 61, 62, 63}
    };
    int target = 3;
    bool found = sol.searchMatrix(matrix, target);
    cout << (found ? "Target found!" : "Target not found!") << endl;
    return 0;
}