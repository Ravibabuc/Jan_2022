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
    
    ListNode *ptr=A;
    ListNode *Prev =NULL;
    ListNode *ptr2;
    
    if(A == NULL || A->next == NULL)
        return A;
    
    while(curr!= NULL)
    {
        cout<<"ptr11-->val "<<ptr->val<<endl;
            cout<<"curr11-->val "<<curr->val<<endl;
        if(ptr->val >= B && curr->val < B)
        {
            
            cout<<" while looop      ---------"<<endl;
            cout<<"ptr-->val "<<ptr->val<<endl;
           cout<<"curr-->val "<<curr->val<<endl;
            
           
          cout<<"ptr2-->val "<<ptr2->val<<endl;
            
            cout<<"ptr2->next-->val "<<ptr2->next->val<<endl;
            
            if(Prev== NULL)
            {
                
                Prev= ptr2->next;
                ptr2 ->next= ptr2->next->next;
                Prev -> next = ptr;
                A =Prev;
            }
            else
            {
                Prev->next = ptr2->next ;
                ptr2 ->next= ptr2->next->next;
                Prev -> next->next = ptr;
                 Prev = Prev->next;
            }
            
            cout<<"Prev000-->val "<<Prev->val<<endl;
             cout<<"Prev000->next-->val "<<Prev->next->val<<endl;
            cout<<"ptr000-->val "<<ptr->val<<endl;
            cout<<"ptr-next->val "<<ptr->next->val<<endl;
            
           
            cout<<"hello 22"<<endl;
          
           //cnt ++;
           // if (cnt ==8)
          // return Prev;
          cout<<" while looop      --------- end"<<endl;
        }
        else if(ptr->val < B)
        {
            Prev =ptr;
            ptr = ptr->next;
        }
        
       // cout<<"hell1 "<<endl;
        if( curr != NULL)
        {
            ptr2 =curr;
            curr= curr->next;
        }
       // cnt ++;
      //  if (cnt ==8) break;
    }
    return A;
}





int main()
{
    vector <int> A ={656 , 148 , 696 , 633 , 755 , 13 , 496 , 397 , 640 , 986 , 563 , 88 , 618 , 942 , 12 , 258 , 509 , 457 , 960 , 202 , 798 , 19 , 675 , 161 , 642 , 962 , 504 , 885 , 102 , 266 , 636 , 337 , 896 , 280 , 330 , 548 , 22 , 69 , 451 , 631 , 394 , 819 , 326 , 743 , 652 , 131 , 445 , 595 , 884 , 561 , 575 , 842 , 579 , 856 , 184 , 223 , 97 , 862 , 922 , 878 , 287 , 371 , 442 , 173 , 16 , 248 , 297 , 286 , 785 , 811 , 440 , 122 , 725 , 879 , 592 , 307 , 715 , 244 , 700 , 28 , 252 , 792 , 135 , 493 , 119 , 649 , 797 , 995 , 462 , 657 , 170}; //{1, 2, 3, 4,5,6};
    int B =94;
    ListNode* Head;
    Head=insert(Head, A);

  
    ListNode *curr =Head;
    cout<<"list started ----------"<<endl;
    while(curr != NULL )   
   {



       cout<<" Head->next "<<curr->next<<endl;
       cout<<"Head data   "<<curr->val<<endl;
       curr =curr->next;
    }
    cout<<"list end ----------"<<endl;
    int cnt=0;
    Head = partition(Head, B);
    cout<<" cnt "<<cnt<<endl;
    cout<<"ans ----------------------  "<<endl;
    while(Head != NULL)   
    {


       // cout<<" Head->next "<<Head->next<<endl;
       cout<<"->  "<<Head->val;
        Head =Head->next;
        cnt ++;
       // if(cnt == 7) break;
    }
    cout<<endl;



    return 0;
}
