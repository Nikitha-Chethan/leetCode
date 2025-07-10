#include <iostream>
#include <string>

using namespace std;

class Solution{
    public:
    string removeOccurences(string s, string part)
    {
        while(s.length() > 0 && s.find(part) < s.length())
        {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main()
{
    string s = "daabcbaabcbc";
    Solution sol;
    string part = "abc";
    string result = sol.removeOccurences(s, part);
    cout << "Input: " << s << endl;
    cout << "Result: " << result << endl;
    if(result.empty())
    {
        cout << "Empty string after removal." << endl;
    }
    else
    {
        cout << "Final string: " << result << endl;
    }
    return 0;
}