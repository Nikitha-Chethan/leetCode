#include<iostream>
#include<vector>
#include <climits>
using namespace std;
class Solution {
    public:
    double myPow(double x, int n) {
        long binForm = n;
        if (n == 0) return 1.0; // Base case: x^0 = 1
        if (x == 0) return 0.0; // Base case: 0^n = 0 for n > 0
        if (x == 1 || x == -1) return (n % 2 == 0) ? 1.0 : x; // Handle cases for 1 and -1
        if (x < 0 && n % 2 == 0) return 1.0; // Even power of negative number is positive
        if (x < 0 && n % 2 == 1) return x; // Odd power of negative number retains sign
        if (n == INT_MIN) { // Handle edge case for INT_MIN
            x *= x; // Square x to avoid overflow
            binForm = -(long)n / 2; // Use half of n to avoid overflow
        } else {
            binForm = n; // Use n directly for other cases
        }

        if (n < 0) {
            x = 1 / x; // If n is negative, take reciprocal of x
            binForm = -binForm; // Make n positive
        }
        double result = 1.00000;
        while (binForm > 0) {
            if (binForm % 2 == 1) { // If n is odd
                result *= x; // Multiply result by x
            }
            x *= x; // Square x
            binForm /= 2; // Divide n by 2
        }
        cout<<result<<endl;
        return result;
    }
};

int main()
{
    Solution sol;
    double x = 2.00000;
    int n = 10;
    double result = sol.myPow(x, n);
    cout << "Result: " << result << endl;
    return 0;
}
