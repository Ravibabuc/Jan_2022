#include <iostream>
#include <vector>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};



ListNode *insert(ListNode* Head, vector<int>& A)
{
    int n =A.size();
    Head= new ListNode();
    Head->val=A[0];
    ListNode  *tmp =NULL;
    Head->next=tmp;
    tmp= new ListNode();
    tmp->val=A[1];
    Head-> next= tmp;
    tmp->next=NULL;
   for(int i =2;i<n;i++)
    {

       ListNode* tmp1= new ListNode();
       tmp1->val=A[i];
       tmp1-> next= NULL;
       tmp->next=tmp1;
       tmp = tmp->next;
    }
    return Head;
}

ListNode* partition(ListNode* A, int B) 
{
    //int cnt=0;
    ListNode *curr=A;
    
    ListNode *ptr1 =NULL;
   // ListNode *Prev =NULL;
    ListNode *ptr2 =NULL;
    
    ListNode *ptr1tail = NULL;
    ListNode *ptr2tail = NULL;
    
    
    if(A == NULL || A->next == NULL)
        return A;
    
    while(curr!= NULL)
    {
        //cout<<"ptr11-->val "<<ptr1->val<<endl;
        cout<<"curr11-->val "<<curr->val<<endl;
        if(curr->val < B)
        {
           
            
           
            //cout<<"ptr1tail-->val "<<ptr1tail->val<<endl;
            cout<<"curr00-->val "<<curr->val<<endl;
            
          if(ptr1tail == NULL ) 
          {
              ptr1tail = curr;
              ptr1 = ptr1tail;
              ptr1tail -> next =NULL;
          }
          else
          {
            ptr1tail->next = curr;
          }
          cout<<"ptr1tail-->val "<<ptr1tail->val<<endl;
        }
        else 
        {
           
          if(ptr2 == NULL ) 
          {
              ptr2tail = curr;
              ptr2 = ptr1tail;
              ptr2tail -> next =NULL;
          }
          else 
          {
            ptr2tail -> next = curr;
          }
            cout<<"ptr22-->val "<<ptr2tail->val<<endl;
            cout<<"curr22-->val "<<curr->val<<endl;
        }
        curr= curr->next;
    }
           cout<<"hello1 1"<<endl;
        ptr2tail-> next= NULL;
           cout<<"hello1 0"<<endl;
        if(ptr1tail == NULL)
            ptr1tail = ptr2;
        else
            ptr1tail ->next =ptr2;

    cout<<"hello1 2"<<endl;
    return ptr1;
}



ListNode* mergeTwoLists(ListNode* A, ListNode* B) 
{
   
    
    ListNode *Newnode =NULL;
   
    
    if(A == NULL  )
        return B;
        
    if(B == NULL  )
        return A;
    
    if(A->val <= B->val)
    {
        Newnode = A;
        A = A->next;
    }
    else
    {
        Newnode = B;
        B = B->next;
    }
    ListNode * mergedTail = Newnode;
    while(A != NULL && B != NULL )
    {
        ListNode *tmp = NULL;

        if(A->val <= B->val)
        {
            tmp= A;
            A = A->next;
        }
        else
        {
            tmp= B;
            B = B->next;
        }
        mergedTail->next = tmp;
        mergedTail = tmp;
    }
    
    if (A != NULL) 
    {
       // cout<<"hello1 "<<endl;
        
       //  cout<<"A-VAL "<<A->val<<endl;

        mergedTail->next = A;
    } 
    else if (B  != NULL) 
    {
         mergedTail->next = B;
        // cout<<"hello2 "<<endl;
    }
    return Newnode;
}


int main()
{
   // vector <int> A ={656 , 148 , 696 , 633 , 755 , 13 , 496 , 397 , 640 , 986 , 563 , 88 , 618 , 942 , 12 , 258 , 509 , 457 , 960 , 202 , 798 , 19 , 675 , 161 , 642 , 962 , 504 , 885 , 102 , 266 , 636 , 337 , 896 , 280 , 330 , 548 , 22 , 69 , 451 , 631 , 394 , 819 , 326 , 743 , 652 , 131 , 445 , 595 , 884 , 561 , 575 , 842 , 579 , 856 , 184 , 223 , 97 , 862 , 922 , 878 , 287 , 371 , 442 , 173 , 16 , 248 , 297 , 286 , 785 , 811 , 440 , 122 , 725 , 879 , 592 , 307 , 715 , 244 , 700 , 28 , 252 , 792 , 135 , 493 , 119 , 649 , 797 , 995 , 462 , 657 , 170}; //{1, 2, 3, 4,5,6};
   
    vector <int> A ={5 , 8 , 20}; //{1, 2, 3, 4,5,6};
   // int B =3;
    ListNode* Head;
    Head=insert(Head, A);
     vector <int> B ={4 , 11 , 15};
     ListNode* Head1= insert(Head1, B);
  
    ListNode *curr =Head;
    cout<<"list started ----------"<<endl;
    while(curr != NULL  )   
   {



       cout<<" Head->next "<<curr->next<<endl;
       cout<<"Head data   "<<curr->val<<endl;
       curr =curr->next;
    }
    cout<<"list end ----------"<<endl;
    int cnt=0;
    Head1 = mergeTwoLists(Head, Head1);
    cout<<" cnt "<<cnt<<endl;
    cout<<"ans ----------------------  "<<endl;
    while(Head1 != NULL)   
    {


       // cout<<" Head->next "<<Head->next<<endl;
       cout<<"->  "<<Head1->val;
        Head1 =Head1->next;
        cnt ++;
        //if(cnt == 5) break;
    }
    cout<<endl;



    return 0;
}
