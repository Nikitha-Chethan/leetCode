#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        // Calculate prefix products
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        
        // Calculate suffix products and multiply with prefix products
        int suffixProduct = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffixProduct *= nums[i + 1];
            result[i] *= suffixProduct;
        }
        
        return result;
    }    
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    // Example usage of the Solution class
    // You can add methods to the Solution class and call them here
    cout << "This is a placeholder for productExceptSelf functionality." << endl;
    vector<int> result = sol.productExceptSelf(nums);
    cout << "Product except self: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    

    return 0;
}