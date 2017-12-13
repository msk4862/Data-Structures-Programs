#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main() 
{

string reverse(string res, string str);


	string str;

	cout<<"Enter string: ";
	getline(cin, str);

	
	cout<<"RESULT: "<<reverse("", str)<<endl;

return 0;
  
}

string reverse(string res, string str) {
string t;
	if(str.length() == 0) 
		return res;

	else {
		t = str.substr(str.length()-1);
		str = str.substr(0, str.length()-1);
		res.append(t);

	return reverse(res, str);

	}
}
		
		 
		
	
