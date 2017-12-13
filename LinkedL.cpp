#include<iostream>
#include<cstdlib>


using namespace std;

template<class T>
class node {
	
	public:
		T info;
		node<T> *next;
		
	node() {
		info=-1;
		next = NULL;
	}
		
	node(T i, node<T> *addr = NULL) {
		info = i;
		next = addr;
	}
};


template<class T>

class list{
	
	private:
		node<T> *head;
		node<T> *rear;
	
	public:	
		list() {
			rear = NULL;
			head = NULL;
		}
		
		void print();
		void insertAtBeg(T i);
		void insertAtEnd(T i);
		void insertAtPos(T i, int pos);
		
		T deleteFromBeg();
		T deleteFromEnd();
		void deleteOne(T d);
	
};

template<class T>

void list<T>::insertAtBeg(T i) {
	
	head = new node<T>(i, head);
	
	if(rear == NULL) {
		rear = head;
	}
	
}

template<class T>
void list<T>::insertAtEnd(T i) {
			
	if(rear == NULL) {
		rear = head = new node<T>(i);
	}
	
	else {
		rear->next = new node<T>(i);
		rear = rear->next; 
	}

}

template<class T>
void list<T>::insertAtPos(T i, int pos) {
	
	node<T> *pre = head;
	node<T> *cur = pre->next;
	
	if(head->next == NULL) {
		head->next = new node<T>(i);
	}
	
	else {
		for(int j=1; j < pos-1; ++j) {
			pre = cur;
			cur = cur->next;
		}
		
		pre->next = new node<T>(i, cur);		
	}

	
}

template<class T>
T list<T>::deleteFromBeg() {
	if(head == NULL) {
		cout<<"UNDERFLOW!!!!";
		return -1;
	}
	else {
		node<T> *ptr = head;
		T i = ptr->info;
		head = ptr->next;
		
		delete ptr;
			
		return i;

	}

	
}

template<class T>
T list<T>::deleteFromEnd() {
	if(head == NULL) {
		cout<<"UNDERFLOW!!!!";
		
		return -1;
	}
	
	else {
		node<T> *ptr = head;
		while(ptr->next != rear) {
			ptr = ptr->next;
		}
		
		T i = rear->info;
		rear = ptr;
		rear->next = NULL;
	
		delete ptr->next;
	
	return i;	
	}	
}

template<class T>
void list<T>::deleteOne(T d) {
	if(head == NULL) {
		cout<<"UNDERFLOW!!!!";
	}
	
	else if(d == head->info) {
		node<T> *ptr = head;
		head = head->next;
		
		delete ptr;
	}
	
	else {
		node<T> *pre = head;
		node<T> *cur = pre->next;
		
		while(cur != NULL) {
			if(cur->info == d) {
				break;
			}
			pre = cur;
			cur = cur->next;
			
		}
		
		if(cur == NULL) {
			cout<<"\nElement not found!!"<<endl;
		}
		else {
			pre->next = cur->next;
			delete cur;
		}
	}
		
}

template<class T>

void list<T>::print() {
	node<T> *ptr = head;
	
	cout<<"\nYour Linked List: ";
	while(ptr !=NULL){
		cout<<ptr->info<<" ";
		ptr = ptr->next;
		
	}
}


int main()
{
	list<float> l;

	int choice;
	float data;
	int pos;

	do {
	
		
		cout<<"\n\n\n1. Insertion at Beginning";
		cout<<"\n2. Insertion at End";
		cout<<"\n3. Insertion at any position";
		cout<<"\n4. Delete from beginning";
		cout<<"\n5. Delete from end";
		cout<<"\n6. Delete a particluar number";
		cout<<"\n7. Print Linked List";
		cout<<"\n8. EXIT";
		
		cout<<"\n\nEnter your choice:";
		cin>>choice;
		
		switch(choice) {
		
			case 1: cout<<"\nEnter data:";
				cin>>data;
				
				l.insertAtBeg(data);
				l.print();
				break;
				
			case 2: cout<<"\nEnter data:";
				cin>>data;
				
				l.insertAtEnd(data);
				l.print();
				break;
				
			case 3: cout<<"\nEnter data:";
				cin>>data;
				cout<<"Enter Position:";
				cin>>pos;
				l.insertAtPos(data, pos);
				l.print();
				break;
				
				
			case 4: cout<<"\nDeleting: "<<l.deleteFromBeg();
				l.print();
				break;
			
			case 5: cout<<"\nDeleting: "<<l.deleteFromEnd();
				l.print();
				break;

			case 6: cout<<"\nEnter the value you want to delete: ";
				cin>>data;
				l.deleteOne(data);
				l.print();
				break;

			case 7: l.print();
				break;

			case 8: exit(0);
		}
	
	}while(true);
	
	

return 0;
}
