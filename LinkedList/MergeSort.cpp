#include"bits_stdcpp.h"
using namespace std;
struct Node{
    struct Node*next;
    int val;
};
void spiltList(Node*head,Node**a,Node**b);
Node*merge(Node*a,Node*b);
void mergeSort(Node**head_ref){
    Node*head=*head_ref;
    Node*a,*b;
    if(head==NULL || head->next==NULL){
        return;
    }
    spiltList(head,&a,&b);
    mergeSort(&a);
    mergeSort(&b);
   (*head_ref)=merge(a,b);
}
Node*merge(Node*first,Node*second){
    Node*res=NULL;
    if(first==NULL)
     return second;
     else if(second==NULL){
        return first;
     }
     if(first->val<=second->val){
        res=first;
        res->next=merge(first->next,second);
     }else{
        res=second;
        res->next=merge(first,second->next);
     }
     return res;
}

void spiltList(Node*head,Node**first,Node**second){
    Node*curr=head;
    Node*fast=curr->next,*slow=curr;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }
    *first=head;
    *second=slow->next;
    slow->next=NULL;
}
void insert(Node**head_ref,int value){
    Node* new_node=new Node();
    new_node->val=value;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}
void print(Node*head){
    Node*curr=head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
int main(){
    Node* List=NULL;
    insert(&List,10);
    insert(&List,4);
    insert(&List,2);
    insert(&List,6);
    insert(&List,1);
    print(List);
    mergeSort(&List);
    cout<<"Sorted List"<<endl;
    print(List);
    return 0;
}