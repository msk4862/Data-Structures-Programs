#include<iostream>

using namespace std;


int powerCal(int base, int pow) {

	if(pow == 0) 
		return 1;
	else {

		return base*(powerCal(base, pow-1));
	}
}

int main()
{

	
	int b, r;

	cout<<"Enter base: ";
	cin>>b;
	
	cout<<"\nEnter power: ";
	cin>>r;
	

	cout<<"RESULT: "<<powerCal(b, r)<<endl;

return 0;

}

