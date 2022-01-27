/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/* 
Range Minimum Query
Unsolved
character backgroundcharacter
Stuck somewhere?
Ask for help from a TA & get it resolved
Get help from TA

Problem Description

Given an integer array A of size N.

You have to perform two types of query, in each query you are given three integers x,y,z.

If x = 0, then update A[y] = z.
If x = 1, then output the minimum element in the array A between index y and z inclusive.

Queries are denoted by a 2-D array B of size M x 3 where B[i][0] denotes x, B[i][1] denotes y, B[i][2] denotes z.



Problem Constraints

1 <= N, M <= 105

1 <= A[i] <= 109

If x = 0, 1<= y <= N and 1 <= z <= 109

If x = 1, 1<= y <= z <= N



Input Format

First argument is an integer array A of size N.

Second argument is a 2-D array B of size M x 3 denoting queries.



Output Format

Return an integer array denoting the output of each query where value of x is 1.


Example Input

Input 1:

 A = [1, 4, 1]
 B = [ 
        [1, 1, 3]
        [0, 1, 5]
        [1, 1, 2] 
     ]

Input 2:

 A = [5, 4, 5, 7]
 B = [ 
        [1, 2, 4]
        [0, 1, 2]
        [1, 1, 4]
     ]



Example Output

Output 1:

 [1, 4]

Output 2:

 [4, 2]



Example Explanation

Explanation 1:

 For 1st query, the minimum element from range (1, 3) is 1.
 For 2nd query, update A[1] = 5, now A = [5, 4, 1].
 For 3rd query, the minimum element from range (1, 2) is 4.

Explanation 2:

 For 1st query, the minimum element from range (2, 4) is 4.
 For 2nd query, update A[1] = 2, now A = [2, 4, 5, 7].
 For 3rd query, the minimum element from range (1, 4) is 2.*/
 
  
 
 
vector<int > Tree;




void construct_segment_tree(vector<int>& segtree,
                           vector<int> &a, int n)
{
    // assign values to leaves of the segment tree
    for (int i = 0; i < n; i++)
        segtree[n + i] = a[i];   
 
    /* assign values to internal nodes
      to compute minimum in a given range */
    for (int i = n - 1; i >= 1; i--)
        segtree[i] = min(segtree[2 * i],
                         segtree[2 * i + 1]);
}





void update(vector<int>& segtree, int pos, int value,
                                               int n)
{
    // change the index to leaf node first
    pos += n;
 
    // update the value at the leaf node
    // at the exact index
    segtree[pos] = value;
 
    while (pos > 1) {
 
        // move up one level at a time in the tree
        pos >>= 1;
 
        // update the values in the nodes in
        // the next higher level
        segtree[pos] = min(segtree[2 * pos],
                           segtree[2 * pos + 1]);
    }
}




int range_query(vector<int>& segtree, int left, int
                                      right, int n)
{
    /*  Basically the left and right indices will move
        towards right and left respectively and with
        every each next higher level and compute the
        minimum at each height. */
    // change the index to leaf node first
    
   // cout<<"lift and right "<<left<<"  "<<right<<endl;
    left += n;
    right += n;
 
    // initialize minimum to a very high value
    int mi = (int)1e9;
 
    while (left < right) {
 
        // if left index in odd
        if (left & 1) {
            mi = min(mi, segtree[left]);
 
            // make left index even
            left++;
        }
 
        // if right index in odd
        if (right & 1) {
 
            // make right index even
            right--;
 
            mi = min(mi, segtree[right]);
        }
 
        // move to the next higher level
        left /= 2;
        right /= 2;
    }
    
   // cout<<"query ="<<mi<<endl;
    return mi;
}

vector<int> solve(vector<int> &A, vector<vector<int> > &B) 
{
    vector<int> C;
    int si =A.size();
    Tree.resize(si*2);
    //build(1, 0, si-1, A);
    construct_segment_tree(Tree,A, si);
    
    

    
    
    
    
    int ans;
    
    int n =B.size();
    for (int i =0;i<n;i++)
    {
       if (B[i][0] == 0)
       {
           update(Tree, B[i][1], B[i][2], si-1 );
    
       }
    
       if (B[i][0] == 1)
       {
         // cout<<"query "<<endl;
         ans =range_query(Tree, B[i][1]-1, B[i][2], si );
     //    cout<<"query ans ="<<ans<<endl;
         C.push_back(ans);
       }
    }
    
   
   //  for (int i =0;i< Tree.size();i++)
    //      cout<<"ans ="<<Tree[i]<<endl;
   
    return C;
    
}


int main()
{
    
    vector<int> A ={18, 10, 1, 20, 25, 4, 9, 13, 15, 6, 21, 7};

     vector<vector<int> > B ={{1, 8, 12},
  {0, 4, 7},
  {1, 1, 3},
  {1, 5, 11},
  {1, 3, 9},
  {1, 7, 12},
  {1, 7, 10},
  {0, 12, 20}};
     vector<int> C =solve(A, B);
   
   cout<<"final ans =============="<<endl;
    for (int i =0;i< C.size();i++)
          cout<<"ans ="<<C[i]<<endl;
    return 0;
}
