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
	deleteNode(n);

	print();
	
	cout<<"**************************************\n";
	
	cout<<"After deleting, the ";
	print();
	size=length();
	cout<<"number of elements in List is : "<<size<<endl;

	
	return 0;
}