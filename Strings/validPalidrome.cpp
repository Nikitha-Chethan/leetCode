#include <iostream>
#include <cstring>
using namespace std;

class Solution{
    public:
    bool isAlphaNumeric(char c)
    {
        // Check if the character is alphanumeric (a-z, A-Z, 0-9)
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    bool isPalindrome(string s)
    {
        int st = 0, end = s.length()-1;
        while(st < end)
        {
            // Skip non-alphanumeric characters
            if(!isAlphaNumeric(s[st]))
            {
                st++;
                continue;
            }
            if(!isAlphaNumeric(s[end]))
            {
                end--;
                continue;
            }
            // Compare characters in a case-insensitive manner
            if(tolower(s[st]) != tolower(s[end]))
            {
                return false; // If characters don't match, it's not a palindrome
            }
            st++;
            end--;
        }
        return true; // If all characters match, it's a palindrome
    }
};
int main()
{
    string st = " A man, a plan, a canal: Panama ";
    Solution sol;
    sol.isPalindrome(st) ? cout << "True" : cout << "False";    
    cout << endl;
    return 0;
}