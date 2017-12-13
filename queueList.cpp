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
		
	node(T i, node<T> *addr = NULL){
		info = i;
		next = addr;
	}
};


template<class T>

class queue{
	
	private:
		node<T> *head;
		node<T> *rear;
	
	public:	
		queue() {
			rear = NULL;
			head = NULL;
		}
		
		void print();
		T dequeue();
		void enqueue(T i);

	
};

template<class T>
void queue<T>::enqueue(T i) {
	
	
	if(rear == NULL) {
		rear = new node<T>(i);
		head = rear;
	}
	
	else {
		rear->next = new node<T>(i);
		rear = rear->next;		
	}
	
	
}

template<class T>
T queue<T>::dequeue() {
			
	T i;
			
	if(head == NULL) {
		cout<<"\n\nQueue Underflow!!!\n";
		return -1;
	}
	
	else {
		node<T> *t = head;
		head = head->next;
		
		i = t->info;
		
		delete t;
		
		return i;
		
	}

}



template<class T>

void queue<T>::print() {
	
	if(head == NULL) {
		cout<<"\n\nQueue Underflow!!!\n";
		return;
	}
	
	node<T> *t = head;
	
	cout<<"\nYour Queue: ";
	while(t !=NULL){
		cout<<t->info<<" ";
		t = t->next;
		
	}
}


int main()
{
	queue<int> q;

	int choice;
	
	int data;

	do {
	
		
		  cout <<"\n\n\n1.Enqueue \n2.Dequeue  \n3.Display  \n4.Exit\n\nEnter your choice: ";

		cin>>choice;
		
		switch(choice) {
		
			case 1: cout<<"\nEnter data:";
				cin>>data;
				
				q.enqueue(data);
				q.print();
				break;
				
			case 2: data = q.dequeue();
			
				if(data!=-1) {
					cout<<"\nDeleting: "<<data;
				}
			
				break;
				


			case 3: q.print();
				break;

			case 4: exit(0);
		}
	
	}while(true);
	
	

return 0;
}
