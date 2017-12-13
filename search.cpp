#include<iostream>

using namespace std;

int main()
{

int lSearch(int a[], int s, int e);
int bSearch(int a[], int s, int e, int first, int last);


char ch;
int n,e, choice, pos;
cout<<"Enter size of the array:";
cin>>n;

int a[n];


cout<<"\nEnter array: ";
for(int i=0;i<n;++i){

	cin>>a[i];
}


do {cout<<"Enter element you want to search:\n";
cin>>e;


cout<<"1. Search using linear search\n";
cout<<"2. Search using binary search\n";

cin>>choice;

if(choice==1) {
	pos = lSearch(a, n, e);

}
else {
	pos = bSearch(a, n, e, 0, n);
}

if(pos!=-1) {
	cout<<"Element found at "<<pos+1<<endl;
}
else {
	cout<<"Element not found!!!"<<endl;
}

cout<<"Want to enter more(y/n):";
cin>>ch;
}while(ch=='y');

return 0;
}



int lSearch(int a[], int s, int e)
{

int pos=-1;

for(int i=0;i<s;++i){
	if(a[i] == e) {
		pos=i;
	}
}
return pos;
}



int bSearch(int a[], int s, int e, int first, int last)
{

int mid;

/*for(int i=0;i<s-1;++i){
	for(int j=i+1;j<s;++j){
		if(a[i] > a[j]) {
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
}*/

mid=(first+last)/2;



	if(a[mid] > e) {
		bSearch(a, s, e, first, mid-1);
	}

	else if(a[mid] < e) {
		bSearch(a, s, e, mid+1, last);
	}

	else if(a[mid]==e){
    return mid;
	}

	else
	return -1;


}













