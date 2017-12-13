#include<iostream>
#include<string>
#include<stack>
#include<list>

using namespace std;


int main(){



stack<int> total;

cout<<"ENTER THE POSTFIX EXPRESSION: "<<endl;
string exp;
cin>>exp;

char ch;

int num1,num2;

while(!exp.empty()) {
	
ch = exp.at(0);
exp = exp.substr(1);


if(ch !='+' && ch !='-' && ch !='*' && ch !='/'){
	
	int i =  (int)ch - 48;
	
	
	total.push(i);
}

else{

	if(ch == '+'){
	  
		 num2 = total.top();
		total.pop();
		 num1 =total.top();
		 total.pop();
		total.push(num1+num2);
			
	
	}
	
	if(ch == '-'){
		
		  num2 = total.top();
		total.pop();
		 num1 =total.top();
		 total.pop();
		total.push(num1-num2);
		
		
	}
	
	 if(ch == '*'){
	 	
		  num2 = total.top();
		total.pop();
		 num1 =total.top();
		 total.pop();
		total.push(num1*num2);
		
	
	}
	
	if(ch == '/'){
		
		  num2 = total.top();
		total.pop();
		 num1 =total.top();
		 total.pop();
		total.push(num1/num2);
		

	
	}
	
}


}

cout<<"\nResult: ";

while(!total.empty()) {
	cout<<total.top();
	total.pop();
}


return 0;

}
