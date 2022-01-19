#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int max_val(int a, int b)
{
    cout<<"a "<<a<<endl;
    cout<<"b "<<b<<endl; 
    return a> b ?a:b;
}

int maxvalvue (vector < int >&A, int n)
{
  if (n == 1)
    return A[0];
    
  //{ 51, 6, 10, 8, 22, 61, 21,45 }; 
    // cout<<"n "<<n<<endl;
    //cout<<"A[n-1] "<<A[n-1 ]<<endl;

  return max_val (A[n-1], maxvalvue (A, n - 1));
}

int sumArray(vector<int> A, int n)
{
    if(n==1)
        return A[0];
    return A[n-1] + sumArray(A, n-1);
}

int merge(vector<int> A, int low, int high)
{
    int i =low;
    cout<<"+++++++++++++++++Start+++++++++++++++++"<<endl;
   // cout<<" low "<<low<<endl;
   // cout<<" high "<<high<<endl;
    while(i< high)
    {
        cout<<" A[i] "<<A[i]<<endl;
        i++;
    }
    cout<<"+++++++++++++++++End+++++++++++++++++"<<endl;
}

vector <int> mergeSort(vector <int> &A,int low, int high)
{
    int mid = (low +high)/2;
    if (low < high )
    {
        cout<<"low "<<low<<endl;
        cout<<"mid "<<mid<<endl;
        cout<<"high "<<high<<endl;


        cout<<"+++++++++++++++++mergeSort+++++++++++++++++"<<endl;
        mergeSort(A, low , mid);
        cout<<"+++++++++++++++++mergeSortend+++++++++++++++++"<<endl;
        mergeSort(A, mid+1 , high);
        cout<<"+++++++++++++++++mergeSortend222+++++++++++++++++"<<endl;
        merge(A, low, high);
    }
    return A;
}

int main ()
{
 // vector < int >A = { 51, 6, 10, 8, 22, 61, 21,45 };
    vector<int> A  = { 1, 2, 3, 4, 5};
  int n = A.size ();
  int C = sumArray (A, n);

  std::cout << C << std::endl;

  return 0;
}
