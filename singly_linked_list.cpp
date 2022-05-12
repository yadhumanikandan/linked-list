#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head=NULL, *ptr, *temp;
int val, pos, count; 

void insrtBeg(){

    ptr = new node;

    cout<<"\n->Enter the value to insert ";
    cin>>val;

    ptr->data=val;

    if(head==NULL){
        ptr->next=NULL;
    }else{
        ptr->next=head;
    }

    head=ptr;

}

void insrtEnd(){}

void insrtReq(){}

void delBeg(){}

void delEnd(){}

void delReq(){}

void display(){}


int main(){

    char choice;

    do{
    cout<<"\n  Select an operation\n\n1-> Insert at begining\n2->Insert at end\n3->insert at required location\n4->Delete from begining\n5->Delete from end\n6->Delete from required location\n7->Display the list\n0->Exit\n\n->";
    cin>>choice;

    switch (choice)
    {
    case '1': insrtBeg();
        break;

    case '2': insrtEnd();
        break;

    case '3': insrtReq();
        break;

    case '4': delBeg();
        break;

    case '5': delEnd();
        break;

    case '6': delReq();
        break;

    case '7': display();
        break;

    case '0': cout<<"Exiting program";
        break;
    
    default:cout<<"\n\n**Enter a valied choice**";
        break;
    }

    }while (choice!='0');


    return 0;
}