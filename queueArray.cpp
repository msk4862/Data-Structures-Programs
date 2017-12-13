#include<iostream>
#include<cstdlib>


using namespace std;

template<class T>
class queue
{
              T *q;
              int rear,front;
              int SIZE;
      public:
              
           queue(int s);
           void EnQueue(int x);
           void DeQueue();
           void display();
              
};
 
 template<class T>
queue<T>::queue(int s) {
    rear=-1;
    front=-1;
    
    SIZE = s;
    
    q = new int[s];
}



template<class T>
void queue<T>:: EnQueue(int x) {
	
        if((front==0 && rear==SIZE-1) || (rear == front-1)) {
        	
                       cout <<"\n\nQueue Overflow!!!";
                       return;
            }
               
        //first element
        if(front == -1) {
        	front = 0;
		}
		
		rear = (rear+1) % SIZE; 
		q[rear]=x;
        
		cout<<x<<" inserted successfully!!!";
}


  
template<class T>
void queue<T>:: DeQueue() {
	
    if (front == -1) {
    	
        cout <<"\n\nQueue Underflow!!!";
        return;
    }
             
    cout<<q[front]<<" deleted successfully!!!";
    
    	front = (front + 1) % SIZE;       

}
 
 
 
 template<class T>
  void queue<T>:: display() {
   	
                   if(front==-1) {
                   	
                          cout <<"\n\nQueue is Empty!!!!";
                          return;
                     }
                     
                cout<<endl<<"Your Queue: ";
                if(rear >= front) {
                	 for(int i = front; i <= rear; i++)
                   		cout <<q[i]<<" ";
				}
				else {
					for(int i = front; i < SIZE; i++)
                   		cout <<q[i]<<" ";
                   		
                   	for(int i = 0; i <= rear; i++)
                   		cout <<q[i]<<" ";
				}
                  
    }

 
int main()
{
      int ch;
      
      int d;
      
      queue<int> q(5);
      
      while(1)
        {
              cout <<"\n\n\n1.Enqueue \n2.Dequeue  \n3.Display  \n4.Exit\n\nEnter your choice: ";
              cin >> ch;
              
              switch(ch)
                {
                  case 1:    cout <<"Enter the element: ";
                           	 cin >> d;
                             q.EnQueue(d);
                             break;
                             
                  case 2:  q.DeQueue(); 
				  			 break;
				  			 
                  case 3:  q.display();
				  			break;
				  			
                  case 4: exit(0);
                  }
          }
return 0;
}
