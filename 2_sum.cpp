#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> Findtwosum(vector<int> arr, int target)
{
    vector<int> result;
    unordered_map<int,int> lastseen;
    for(int i=0;i<arr.size();i++)
    {
        int first= arr[i];
        int second = target - arr[i];
        if(lastseen.find(second) != lastseen.end())
        {
            result.push_back(first);
            result.push_back(second);

        }
        lastseen[arr[i]] =i;
    }
    return result;
}

/*
vector<int> Findtwosum(vector<int> arr, int target)
{
    vector<int> result;
    unordered_map<int,int> lastseen;
    for(int i=0;i<arr.size();i++)
    {
        int complement = target - arr[i];
        if(lastseen.count(complement))
        {
            result.push_back(complement);
            result.push_back(arr[i]);
        }
        lastseen[arr[i]] = i; // Store the index of the current element
    }
    return result;
}
*/
int main()
{
    vector<int> arr={2,3,4,5,6,7,8,10};
    int target = 7;
    vector<int> result=Findtwosum(arr,target);
    for(int num: result)
    {
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}