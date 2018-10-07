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
	insertAtBeg(4);
	insertAtBeg(3);
	insertAtBeg(2);
	insertAtBeg(1);
	print();
	cout<<"***************************\n";
	cout<<"Printing in Reverse order ";
	printReverse(head);
	cout<<endl;
	return 0;
}