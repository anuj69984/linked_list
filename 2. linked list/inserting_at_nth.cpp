// handle the case when entered position is greater than the linked list size.

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

void insert(int x, int n){

	if (head == NULL)
	{
		insertAtBeg(x);
	}
	else{
		node* temp=head;
		for (int i = 1; i <n-1; ++i)
		{
			temp=temp->next;
		}
		node* temp2=temp->next;
		node* temp1=new node;
		temp1->data=x;
		temp->next=temp1;	
		temp1->next=temp2;
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

int main(int argc, char const *argv[])
{
	head=NULL;
	int n,x;
	cout<<"At which position do you want to insert ? : ";
	cin>>n;
	cout<<"Enter the number : ";
	cin>>x;
	insertAtBeg(4);
	insertAtBeg(3);
	insertAtBeg(2);
	insertAtBeg(1);
	cout<<"Before inserting "<<x<<" ";
	print();
	cout<<"After inserting "<<x<<" at "<<n<<"th position ";
	insert(x,n);
	print();
	return 0;
}