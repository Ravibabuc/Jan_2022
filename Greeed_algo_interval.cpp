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

There are N jobs to be done but you can do only one job at a time.
Given an array A denoting the start time of the jobs and an array B denoting the finish time of the jobs.
Your aim is to select jobs in such a way so that you can finish maximum number of jobs. Return the maximum number of jobs you can finish.
Problem Constraints
1 <= N <= 105
1 <= A[i] < B[i] <= 109
Input Format
First argument is an integer array A of size N denoting the start time of the jobs.
Second argument is an integer array B of size N denoting the finish time of the jobs.
Output Format
Return an integer denoting the maximum number of jobs you can finish.
Example Input
Input 1:
 A = [1, 5, 7, 1]
 B = [7, 8, 8, 8]
Input 2:
 A = [3, 2, 6]
 B = [9, 8, 9]
Example Output
Output 1:
 2
Output 2:
 1
Example Explanation
Explanation 1:
 We can finish the job in the period of time: (1, 7) and (7, 8).
Explanation 2:
 Since all three jobs collide with each other. We can do only 1 job.*/
 
 struct Activity
 {
     int start;
     int end;
 };
 
bool compareInterval(Activity i1, Activity i2)
{
    return (i1.end < i2.end);
}

int solve(vector<int> &A, vector<int> &B) 
{
    int n=A.size();
    vector<Activity> C;
    int cnt =0;
    C.resize(n);
    for (int i =0;i<n;i ++)
    {
        C[i].start=A[i];
        C[i].end=B[i];
    }
    sort(C.begin(), C.end(), compareInterval);
    
    int i =0;
     for (int j =1;j<n;j ++)
    {
      // cout<<"startime "<< C[j].start<<"endtime " << C[j].end<<endl;
       
       if(C[j].start>= C[i].end)
       {
           i =j;
           cnt ++;
       }
        
    }
    
    return cnt +1;
}

int main()
{
    vector<int> A ={1, 5, 7, 1};
    vector<int> B ={7, 8, 8, 8};
    int C =solve(A, B);
    cout<<"ans ="<<C<<endl;

    return 0;
}
