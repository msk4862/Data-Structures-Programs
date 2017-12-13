#include<iostream>
#include<cstdlib>

using namespace std;


struct node {
	int data;
	struct node *next;
}*head, *rear;

int main()
{
	//void create(int d);
	
	head = NULL;
	rear=NULL;
	
	void Insert(int d);
	void Insert_End(int d);
	void Print();
	//struct node *head = NULL:
	
	int choice;
	
	int data, pos;
	do {
		/*cout<<"\nEnter data:";
		cin>>data;
		Insert(data);
		
		cout<<"\nWant to enter more:";
		cin>>choice;*/
		
		cout<<"\n1. Insertion at Beginning";
		cout<<"\n2. Insertion at End";
		cout<<"\n3. Insertion at any position";
		cout<<"\n4. Print Linked List"
		cout<<"\n5. EXIT";
		
		cout<<"\n\nEnter your choice:";
		cin>>choice;
		
		switch(choice) {
		
			case 1: cout<<"\nEnter data:";
				cin>>data;
				
				Insert(data);
				Print();
				break;
				
			case 2: cout<<"\nEnter data:";
				cin>>data;
				
				Insert_End(data);
				Print();
				break;
				
			case 3: cout<<"\nEnter data:";
				cin>>data;
				cout<<"Enter Position:";
				cin>>pos;
				
				
			case 4: Print();
				break;
			
			case 5: exit(0);
		}
	
	}while(true);
	

	
return 0;
}
	


void Insert(int d) {
	
	
	node *ptr = new node;
	
	ptr->data = d;
	
	if(head == NULL) {
		ptr->next = NULL;
		rear = ptr;
	}
	else 
		ptr->next = head;
	
	head = ptr;
	
}

void Insert_End(int d) {

	node *ptr = new node;
	
	ptr->data = d;
	ptr->next = NULL;
	
	if(rear == NULL) {
		rear = ptr;
		head = ptr;
	}
	else {
		rear->next = ptr;
		rear = ptr;
	}
}

void Insert_Pos(int d, int pos) {

	

void Print() {

	cout<<"Your Linked List is: ";
	
	if(head == NULL) {
		cout<<"UNDERFLOW!!!!";
	}
	
	else {
		node *ptr= new node;
		ptr = head;
	
		while(ptr->next != NULL) {
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
	
		cout<<ptr->data;
	}
	cout<<endl;
	
	
}




