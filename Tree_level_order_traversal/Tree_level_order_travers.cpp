#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int Data;
    Node *left;
    Node *right;
};

Node* newNode(int data)
{
    Node * newNode= new Node;
    newNode ->left = NULL;
    newNode ->right = NULL;
    newNode -> Data=data;
    return newNode;
}

void Print(Node *root)
{
    //cout<<"hello1 "<<endl;
    if (root ==NULL)
    {
        return ;
    }
             
    cout<<"left "<< root->Data <<endl;
    Print(root-> left);
     
  Print(root->right);
  cout<<"right "<< root->Data <<endl;
}


vector<vector<int>> PrintLevelorder(Node *A)
{
    vector<vector<int>> B;
    int i=0;
    int j=0;
    
   // cout<<"hello1 "<<endl;
    if (A ==NULL)
    {
        return B;
    }
    B.resize(1);
    B[i].resize(1);
    Node *Tree;
  // cout<<"hello2 "<<endl; 
    queue<Node*> Qt;
  // cout<<"hello3 "<<endl; 
    Qt.push(A);
    Qt.push(NULL);
  while(Qt.size()>1)
  { 
     // cout<<"hello4 "<<endl;
      Tree =Qt.front();
     
        Qt.pop();
     if (Tree == NULL)
     {
         Qt.push(NULL);
         
          // cout << "\n";
           i++;
           B.resize(i+1);
           j=0;
     }
    else
    {
        if( Tree-> left != NULL)
         {
              Qt.push(Tree-> left);
         }
        if( Tree-> right != NULL)
        {
          Qt.push(Tree-> right);
          
        }
        // cout<< Tree->Data ;
         //   cout<<" ";
           B[i].resize(j+1);
           B[i][j]= Tree->Data;
           j++;
            
    }
  }
   
     
 return B;
}

int print1(int n)
{
    if (n==0)
        return 1;
    print1(n-1);
        cout<<"n "<<n<<endl;
    print1(n-2);
    return 1;
}

int main ()
{
 // vector < int >A = { 51, 6, 10, 8, 22, 61, 21,45 };
  // vector<int> A  = { 1, 2, 3, 4, 5};
  //int n = A.size ();
 // int C = sumArray (A, n);

//  std::cout << C << std::endl;

    Node *root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(100);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->left = newNode(20);
    root->right->right = newNode(120);
   vector<vector<int>> A;
   A =PrintLevelorder(root);
   cout<<"start "<<endl;
   for(int i =0;i<A.size();i++)
   {
         for(int j =0;j<A[i].size();j++)
           cout<<A[i][j]<<"  ";
        cout<<endl;
   }
  return 0;
}
