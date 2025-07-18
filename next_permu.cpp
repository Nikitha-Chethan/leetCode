#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    void nextpermutation(vector<int> &A)
    {
        //find the pivot
        int pivot = -1,n = A.size();
        for(int i=n-2; i>=0; i--)
        {
            if(A[i] < A[i+1])
            {
                pivot = i;
                break;
            }
        } 
        if(pivot == -1)
        {
            reverse(A.begin(),A.end());
            return ;
        }
        //2nd step
        for(int i=n-1 ;i>pivot ;i--)
        {
            if(A[i] > A[pivot]) {
                swap(A[i],A[pivot]);
                break;
            }
        }

        //3rd step
       int i = pivot+1, j=n-1;
       while(i <= j)
       {
        swap(A[i++],A[j--]);
       }
    }
};

int main()
{
    Solution sol;
    vector<int> arr= {1,2,3};
    for(int num: arr)
    {
        cout<<num<<" ";
    }
    cout<<endl;
    sol.nextpermutation(arr);
    for(int num: arr)
    {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}