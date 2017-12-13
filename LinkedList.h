#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

template<class T>

class node {
	
	public:
		T info;
		node<T> *next;
		
	node(){
		info=-1;
		next = NULL;
	}
		
	node(T i, node<T> *addr = NULL){
		info = i;
		next = addr;
	}
};


template<class T>

class list{
	
	private:
		node<T> *head, *rear;
	
	public:	
		list() {
			rear = NULL;
			head = NULL;
		}
		
		void print();
		void insertAtEnd(T i);
		void insertAtPos(T i, T pos);
		void insertAtBeg(T i);
		
		int deleteFromBeg();
		int deleteFromEnd();
		void deleteOne(T d);
	
};


#endif
