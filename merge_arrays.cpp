#include<iostream>
#include <vector>
using namespace std;

void merge(vector<int> &A,int m,vector<int> &B,int n)
{
    int i = m - 1; // Last index of A's initial elements
    int j = n - 1; // Last index of B
    int idx = m + n - 1; // Last index of merged array

    while (i >= 0 && j >= 0) {
        if (A[i] > B[j]) {
            A[idx--] = A[i--];
        } else {
            A[idx--] = B[j--];
        }
    }

    while (j >= 0) {
        A[idx--] = B[j--];
    }
}

int main()
{
    vector<int> A = {1, 3, 5, 7, 0, 0, 0, 0}; // Initial elements followed by zeros
    vector<int> B = {2, 4, 6, 8}; // Elements to be merged  
    int m = 4; // Number of initial elements in A
    int n = 4; // Number of elements in B   
    merge(A,m,B,n);
    cout << "Merged array: ";
    for (int i = 0; i < m + n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
     

    return 0;
}