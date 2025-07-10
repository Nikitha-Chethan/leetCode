#include<iostream>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution{
    public:
    string reverseWords(string s)
    {
        int n = s.length();
        string result = "";
        reverse(s.begin(), s.end());// Reverse the entire string first

        for(int i=0 ;i<n; i++)
        {
            string word = "";
            // Extract each word
            while(i < n && s[i] != ' ') 
            {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end()); // Reverse the extracted word
            if(!word.empty()) // Check if the word is not empty
            {
                if(!result.empty()) // If result is not empty, add a space before adding the next word
                {
                    result += " ";
                }
                result += word; // Add the reversed word to the result
            }   
        }
        return result; // Return the final result with words reversed

    }
};

int main()
{
    Solution sol;
    string s = "the sky is blue";
    string result = sol.reverseWords(s);
    cout << "Reversed words: " << result << endl;
    return 0;
}