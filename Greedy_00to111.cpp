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
You are given a string A consisting of 1's and 0's. Now the task is to make the string consisting of only 1's. 
But you are allowed to perform only the following operation:
Take exactly B consecutive elements of string and change 1 to 0 and 0 to 1.

Each operation takes 1 unit time so you have to determine the minimum time required to make the string of 1's only. If not possible return -1.

00010110
11111111
3

Problem Constraints

2 ≤ length of A ≤ 105
2 ≤ B ≤ (length of A)


Input Format

First argument is a string A consisting if 1's and 0's.
Second argument is an integer B which represents the number of consecutive elements which can be changed.


Output Format

Return an integer which is the minimum time to make the string of 1's only or -1 if not possible.


Example Input

Input 1:

 A = "00010110"
 B = 3
 
 

Input 2:

 A = "011"
 B = 3



Example Output

Output 1:

 3

Output 2:

 -1



Example Explanation

Explanation 1:

 You can get 1 by first changing the leftmost 3 elements, getting to 11110110, then the rightmost 3, getting to 11110001, 
 and finally the 3 left out 0's to 11111111; In 3 unit time.

Explanation 2:

It's not possible to convert the string into string of all 1's.
*/
 
 
 void invert_values(string A, int B)
 {
     for (int i =0;i< B ; i++)
     {
         cout<<"A[i inver"<<A[i]<<endl;
        if(A[i] == '0') 
        {
            A[i] ='1';
        }
        else {
            A[i] ='0';
        }
     }
     
     for (int i =0;i< B ; i++)
     {
         cout<<"A[i inver2  "<<A[i]<<endl;

     }
 }
 //|| i < A.length()

int solve(string A, int B) 
{
    int n =A.length();
    int Zcnt=0;
    int Ocnt=0;
    
    if (B== 0 ) return -1;
    if (B== n)
    {
        for(int i =0;i<n;i++)
        {
            if(A[i]=='0') Zcnt ++;
            else Ocnt ++;
            if(Zcnt>0 && Ocnt>0) return -1;
        }
        if(Zcnt==n) return 1;
        if(Ocnt==n) return 0;
    }
    
    int cnt =0;
    for(int i =0;i<n;i++)
    {
        // cout<<"A"<<A<<endl;

        if(A[i] == '0')
        {
             cout<<"i "<<i<<endl;
            for (int j =i;j< i+B ; j++)
             {
                // cout<<"A[i inver"<<A[i]<<endl;
                
                 if(A[j] == '0' && i+B >n) return -1;
                 
                 
                if(A[j] == '0') 
                {
                    A[j] ='1';
                }
                else {
                    A[j] ='0';
                }
                
               // if (j+B > n) return -1;
            }
            cnt ++;
        }
    }
        
    cout<<"string print"<<endl;
    for(int i =0;i< n;i++)
    {
        cout<<A[i];
   }
   cout<<endl;
    cout<<"string print end"<<endl;
        
        return cnt;
        
}



int main()
{
   // string A="1110001101011111100101010010000101111011000111111011011111111110010000100101001100100011100011110111000000001111001111100000111100001101100001100011000000100110111111110010000000011101110110101000101001010001100010110000000110001111011001111101101101100001000000110011000011111011001000101011010001100001110010010011011110100110011001011111110110011011111100011110111000110010100111100011101100110011000110111101010101110011001111111100010100101101101110011110011111111001000100010100010111100101100010101001111111111111010111111111000110011110000010011111100000011100110001001";

 string A="00010110";
    int B=3;
    int C =solve(A, B);
    cout<<"ans ="<<C<<endl;

    return 0;
}
