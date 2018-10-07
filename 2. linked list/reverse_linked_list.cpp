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

void reverseRecursive(struct node* p){
	 if(p->next==NULL){
	 	head=p;
	 	return;
	 }
	 reverseRecursive(p->next);
	 node* q=p->next;
	 q->next=p;
	 p->next=NULL;
}

int main(int argc, char const *argv[])
{
	head=NULL;
	insertAtBeg(5);
	insertAtBeg(4);
	insertAtBeg(3);
	insertAtBeg(2);
	insertAtBeg(1);
	int size=length();
	cout<<"number of elements in List is : "<<size<<endl;
	
	cout<<"**************************************\n";
	cout<<"After Reversing, the ";
	reverseIterative();
	print();

	cout<<"**************************************\n";
	cout<<"After Reversing, the ";
	reverseRecursive(head);
	print();

	return 0;
}