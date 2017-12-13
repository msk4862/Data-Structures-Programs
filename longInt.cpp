#include<iostream>
#include<string>
#include<stack>
#include<list>

//#include "stackLib.cpp"

using namespace std;


int main(){

stack<int> n1;
stack<int> n2;
stack<int> result;

int carry=0;
int temp=0;

int n=0;

cout<<"Enter the two large numbers to be added one by one:\n";
cout<<"\nEnter the first number digit by digit (-1 to terminate):\n";
  for(int i = 0; n != -1; i++)
  {
	   cin>>n;
	   if(n!=-1)
	   n1.push(n);
  }
  
    n=0;
    
  cout<<"\nEnter the second number digit by digit (-1 to terminate):\n";
  for(int i = 0; n != -1; i++)
  {
	   cin>>n;
	   if(n!=-1)
	   n2.push(n);
  }


while(!n1.empty() && !n2.empty())
  {
  	
   temp += n1.top() + n2.top();
    n1.pop();
    n2.pop();
    
   result.push(temp%10);
   
	temp/=10;	//If carry is present	
   
  }  
  
  
	if(!n1.empty()) {
		
   while(!n1.empty()) {
   	
	    result.push(temp+n1.top());
	    n1.pop();
	    temp=0;
   
   }
  }
    

  if(!n2.empty()) {

   while(!n2.empty())
   {
	    result.push(temp+n2.top());
	    n2.pop();
	    temp=0;
   }
}
    
if(temp!=0)
   result.push(temp);      
  
  
  

cout<<"\n\nSUM: ";

while(!result.empty()) {
	cout<<result.top();
	result.pop();
}


return 0;

}

