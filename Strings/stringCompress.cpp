#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 0) return 0;

        int idx = 0;
        for(int i=0;i<n;i++)
        {
            char ch = chars[i];
            int count = 0;
            while(i<n && chars[i] == ch)
            {
                count++;
                i++;
            }
            if(count == 1)
            {
                chars[idx++] = ch; // If count is 1, just add the character
            }
            else
            {
                chars[idx++] = ch; // Add the character
                string countStr = to_string(count); // Convert count to string
                for(char c : countStr) {
                    chars[idx++] = c; // Add each digit of the count
                }
            }   
            i--; // Adjust i since the outer loop will increment it
        }
        chars.resize(idx); // Resize the vector to the new length
        return idx; // Return the new length of the compressed array
    }
};

int main()
{
    Solution sol;
    vector<char> chars = {'a','a','b','b','c','c','c'};
    int result = sol.compress(chars);
    cout << "Compressed length: " << result << endl;
    cout << "Compressed characters: ";
    for (int i = 0; i < result; i++) {
        cout << chars[i] << " ";
    }   
    return 0;
}