#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head=NULL, *ptr, *temp;
int val, pos, count = 0;

void insrtBeg(){

    ptr = new node;

    cout<<"\n->Enter the value to insert: ";
    cin>>val;

    ptr->data=val;

    if(head==NULL){
        ptr->next=NULL;
    }else{
        ptr->next=head;
    }

    head=ptr;
    cout<<"\nInserted "<<val<<" at the BEGINNING.";
    count++;

}

void insrtEnd(){

    ptr=new node;

    cout<<"\n\nEnter the value to be inserted: ";
    cin>>val;

    ptr->data=val;
    ptr->next=NULL;

    temp=head;

    if(head==NULL){
        head=ptr;
    }else if(head->next==NULL){
        head->next=ptr;
    }else{
        do
        {
            temp=temp->next;
        } while (temp->next!=NULL);

        temp->next=ptr;
        
    }
    cout<<"\n\nInserted "<<val<<" at the END.";
    count++;

}

void insrtReq(){
    ptr = new node;

    cout<<"\n\nEnter the position to insert: ";
    cin>>pos;

    cout<<"\n\nEnter the value to be inserted: ";
    cin>>val;
    ptr->data = val;

    temp = head;

    for(int i=1;i<pos-1;i++){
        temp = temp->next;
    }
    
    if(pos>count+1||pos<0){
        cout<<"\n\n**Enter a valied position**";
    }else{
        ptr->next = temp->next;
        temp->next = ptr;

        cout<<"\n\nInserted "<<val<<" at location: "<<pos;
        count++;
    }
    
}

void delBeg(){

    if(count==0){
        cout<<"\n\n**THE LIST IS EMPTY**";
    }else{
        temp = head;

        head =  head->next;

        cout<<"\n\nREMOVED "<<temp->data<<" FROM 1st POSITION";
        count--;
        delete temp;
    }

}

void delEnd(){

    if(count==0){
        cout<<"\n\n**THE LIST IS EMPTY**";
    }else{
        temp = head;
        for(int i=1; i<count-1; i++){
            temp = temp->next;
        }
        
        ptr = temp;
        temp = temp->next;
        ptr->next = NULL;
        cout<<"\n\nREMOVED "<<temp->data<<" FROM THE END";
        count--;
        delete temp;
    }

}

void delReq(){

    cout<<"\n\nEnter the position to delete: ";
    cin>>pos;
    temp = head;

    for(int i=1; i<pos-1; i++){
        temp = temp->next;
    }

    ptr = temp;
    temp = temp->next;
    ptr->next = temp->next;

    cout<<"\n\nREMOVED "<<temp->data<<" FROM POSITION "<<pos;
    count--;
    delete temp;
}

void display(){

    temp=head;
    cout<<"\n\n THE ELEMENTS ARE: "<<temp->data;
    if (count>=2)
    {

        do
        {
            cout<<", ";
            temp=temp->next;
            cout<<temp->data;

        } while (temp->next!=NULL);
    }
}


int main(){

    char choice;

    do{
    cout<<"\n\n\n  *SELECT AN OPERATION*\n  (current length> "<<count<<")\n\n1-> Insert at begining\n2-> Insert at end\n3-> insert at required location\n4-> Delete from begining\n5-> Delete from end\n6-> Delete from required location\n7-> Display the list\n0-> Exit\n\n-> ";
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

    case '0': cout<<"\nExiting program....\n\n";
        break;
    
    default:cout<<"\n\n**Enter a valied choice**";
        break;
    }

    }while (choice!='0');


    return 0;
}