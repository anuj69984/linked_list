#include <iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};
struct node* head;

void insert(int x){
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

int main(int argc, char const *argv[])
{
	int n,x;
	cout<<"How many numbers do you want to enter ? : ";
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cout<<"Enter the number : ";
		cin>>x;
		insert(x);
		print();
	}
	return 0;
}