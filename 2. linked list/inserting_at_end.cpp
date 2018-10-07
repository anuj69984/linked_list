#include <iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};

struct node* head;

void insertAtBeg(int x){
	node* temp=new node;
	temp->data=x;
	temp->next=head;
	head=temp;
}

void insertAtEnd(int x){
	if (head == NULL)
	{
		insertAtBeg(x);
	}
	else{
		node* temp=head;
		while(temp->next !=NULL){
			temp=temp->next;
		}
		node* temp1=new node;
		temp1->data=x;
		temp1->next=NULL;
		temp->next=temp1;
	}
}

void print(){
	node* temp=head;
	cout<<"List is : ";
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void printRecursive(struct node* p){
	if (p == NULL) return;
	cout<<p->data<<" ";
	printRecursive(p->next);
	cout<<endl;
}

void printReverse(struct node* p){
	if(p == NULL) return;
	printReverse(p->next);
	cout<<p->data<<" ";
}
int main(int argc, char const *argv[])
{
	head=NULL;
	int x;
	cout<<"Enter the number to be inserted at end : ";
	cin>>x;
	insertAtBeg(4);
	insertAtBeg(3);
	insertAtBeg(2);
	insertAtBeg(1);
	cout<<"Before inserting "<<x<<" at end ";
	print();
	cout<<"After inserting "<<x<<" at end ";
	insertAtEnd(x);
	printRecursive(head);

	cout<<"***************************";
	cout<<"Printing in Reverse order. ";
	printReverse(head);
	return 0;
}