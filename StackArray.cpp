#include<iostream>
#include<cstdlib>

using namespace std;

template <class T>

class Array {

	protected:
		T data;
		int top;
		T *stack;
		int capacity;

	public:
		Array(int size) {
			capacity = size;
			stack = new T[size];
			top=-1;
		}

		void push(T a);

		void pop();

		void show();
	
		void clear();
};

template <class T>
void Array <T> ::push(T a) {
	if(top == capacity) 
		cout<<"\nOVERFLOW!!!!\n";
	else {
		stack[++top] = a;
	}

}
	
template <class T>
void Array <T> ::pop() {


	if(top == -1) 
		cout<<"\nUNDERFLOW!!!!\n";
	else {
		cout<<"Popped number is: "<<stack[top]<<endl;
		top--;	
	}


}


template <class T>
void Array <T> ::show() {


	if(top == -1) 
		cout<<"\nUNDERFLOW!!!!\n";
	else {
		cout<<endl;
		for(int i = top; i >= 0; --i)
		cout<<stack[i]<<" ";

		cout<<endl;

	}
}


template <class T>
void Array <T> ::clear() {
	top = -1;

	cout<<"Your Stack is cleared\n";

}


int main()
{
	Array<int> s(5);
	int data;

	int choice;


	do {
	
		
		cout<<"\n\n1. PUSH";
		cout<<"\n2. POP";
		cout<<"\n3. Clear the Stack";
		cout<<"\n4. Show Stack";
		cout<<"\n5. EXIT";
		
		cout<<"\n\nEnter your choice:";
		cin>>choice;
		
		switch(choice) {
		
			case 1: cout<<"\nEnter data:";
				cin>>data;
				
				s.push(data);

				break;
				
			case 2: s.pop();

				break;
				
			case 3: s.clear();
				break;
				
				
			case 4: s.show();
				break;
			
			case 5: exit(0);

		}
	
	}while(true);

	return 0;

}			
		
