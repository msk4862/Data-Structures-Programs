#include<iostream>

using namespace std;

int main()
{
	int power(int b, int r);
	
	int b, r;

	cout<<"Enter base: ";
	cin>>b;
	
	cout<<"\nEnter power: ";
	cin>>r;
	
	cout<<"RESULT: "<<power(b, r)<<endl;

return 0;

}

int power(int b, int r) 
{
	if(r == 0) 
		return 1;
	else {
		//b *= b;
		return b*(power(b, r-1));
	}

}

	
