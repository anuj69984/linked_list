#include <iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};

struct node* head;

int length(){
	node* temp=head;
	int size=0;
	while(temp !=NULL){
		size++;
		temp=temp->next;
	}
	return size;  
}

int countRecursive(node* temp){
	if (temp==NULL)
	{
		return 0;
	}
	return (1+countRecursive(temp->next));
}

void deleteNode(int n){
	node* temp=head;

	if (head == NULL)
	{
		cout<<"List is Empty."<<endl;
		return;
		
	}
	if (n==1)
	{
		head=temp->next;
		delete(temp);		
		
	}

	else if (n>length())
	{
		cout<<"Invalid position !"<<endl;
		return;
	}
	else{
	
		for (int i = 1; i < n-1; ++i)
		{
			temp=temp->next;
		}
		node* temp2=temp;
		temp=temp->next;
		node* temp1=temp->next;
		temp2->next=temp1;
		delete(temp);
	}

}

void deleteAllNode(){
	if (length()==0)
	{
		cout<<"List is Empty !"<<endl;
		return;
	}
	node* temp=head;
	while(temp!=NULL){
		head=temp->next;
		delete(temp);
		temp=head;
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

void insertAtBeg(int x){
	node* temp=new node;
	temp->data=x;
	temp->next=head;
	head=temp;
}

void reverseIterative(){
	node* current=head;
	node*temp;
	node* prev=NULL;
	while(current != NULL){
		temp=current->next;
		current->next=prev;
		prev=current;
		current=temp;
	}
	head=prev;
}

int main(int argc, char const *argv[])
{
	head=NULL;
	int n;
	cout<<"Enter the position at which you want to delete : ";
	cin>>n;
	insertAtBeg(5);
	insertAtBeg(4);
	insertAtBeg(3);
	insertAtBeg(2);
	insertAtBeg(1);
	int size=length();
	cout<<"number of elements in List is : "<<size<<endl;
	cout<<"Before deleting, the ";
	print();
	cout<<"**************************************\n";
	cout<<"After Reversing, the ";
	reverseIterative();
	print();

	cout<<"**************************************\n";
	deleteNode(n);
	cout<<"After deleting, the ";
	print();
	size=length();
	cout<<"number of elements in List is : "<<size<<endl;

	cout<<"**************************************\n";
	cout<<"After deleting all the nodes, the ";
	deleteAllNode();
	print();
	return 0;
}