#include<iostream>
#include<cstdlib>

using namespace std;


template <class T>
class node {

public:

	T info;
	node<T> *next;

	node(T i, node<T> *adr=NULL) {
		info = i;
		next = adr;
	}
};


template <class T>
class Stack {

	node<T> *top;
public:

	Stack() {
		top=NULL;
	}	

	void push();
	int pop();
	void show();
	void clear();
};

template <class T>
void Stack<T> :: push() {
	
    T value;

    cout<<"\nEnter a number to insert: ";
    cin>>value;

    	if(top==NULL) {
	    top=new node<T>(value);
	}
	else {
	    top=new node<T>(value, top);
	}

    cout<<"\nNew item is inserted to the stack!!!";
	
}

template <class T>
int Stack<T> :: pop() {
	if(top == NULL) {
		cout<<"UNDERFLOW!!!!";
		return -1;
	}

	else {

		T i;
		i = top->info;

		node<T> *ptr = top;
		top = top->next;
		
		delete ptr;

		return i;
	}
}


template <class T>
void Stack<T> :: show() {

	if(top == NULL) {
		cout<<"\nStack is Empty!!!\n";
	}

	else {
		node<T> *temp = top;

		while(temp != NULL) {
			cout<<temp->info<<" ";
			temp = temp->next;
		}
	}
}

template <class T>
void Stack<T> :: clear() {
	top = NULL;
	
	cout<<"\nYour Stack is cleared!!\n";
}

		
int main() {

	Stack<int> s;

	int choice;
	int info;

	do {
		cout<<"\n\t\tSTACK USING LINKED LIST\n\n";
		cout<<"1:PUSH\n2:POP\n3:DISPLAY STACK\n4:CLEAR\n5:EXIT";
		cout<<"\nEnter your choice(1-5): ";
		cin>>choice;

		switch(choice) {
			case 1: s.push();
				break;

			case 2: info =s.pop();
				cout<<"\nElement popped is: "<<info<<endl;
				break;

			case 3: cout<<endl;
				s.show();
				cout<<endl;
				break;

			case 4: s.clear();
				break;
		
			case 5: exit(0);

		}
	}while(true);

return 0;

}


	
	
