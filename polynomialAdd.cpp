#include<iostream>

using namespace std;


class node{

public:
int coeff;
int pow;
node *next;

};

class polynomial{

public:
node *head, *tail;

polynomial(){
  head = tail = 0;

}

void getPolynomial(){

 char choice;

do{


  
node *temp = new node;

 if(head == 0){
 cout<<"enter the coefficient \n";
 cin>>temp->coeff;

 cout<<"enter the power \n";
 cin>>temp->pow;

  temp->next = 0;

  head = tail = temp;

  }

  else{

   cout<<"enter the coefficient \n";
 cin>>temp->coeff;

 cout<<"enter the power \n";
 cin>>temp->pow;
   
  if(temp->pow > head->pow){
 
   temp->next = head;
   head = temp;

   }

   else{

    node *current = new node;

    for(current = head; current->next != 0 && current->next->pow > temp->pow ;current = current->next);

    temp->next  =current->next;

    current->next = temp;
   
    if(current == tail)
    tail = temp;

   }

}

cout<<"do you wish to continue( y/n )\n";

cin>>choice;

}while(choice == 'y'); 


}

void showPolynomial(){

node *temp = new node;

temp = head;

if(head != 0){

 while(temp->next != 0)
 {

  cout<< temp->coeff<<"X^"<<temp->pow<<" + ";
  temp = temp->next;

 }

  cout<<" + "<< temp->coeff<<"X^"<<temp->pow<<" ";

}

 }

void addPolynomial(node *a,node *b){


while(a && b){

node *temp = new node;

if(a->pow > b->pow){

temp->pow = a->pow;
temp->coeff = a->coeff;

a = a->next;
}

else if(a->pow < b->pow){

temp->pow = b->pow;
temp->coeff = b->coeff;

b = b->next;
}

else{

temp->pow = a->pow;
temp->coeff = a->coeff + b->coeff;

a = a->next;
b = b->next;

}

if(head == 0){
head = tail = temp;
}

else {

tail->next = temp;
tail = temp;
}

temp->next = 0;

}

if(a){


cout<<"\nInside1";

node *temp = new node; ;

while(a){

temp->pow = a->pow;
temp->coeff = a->coeff;
a = a->next;

if(head == 0){
head = tail = temp;
}

else{

tail->next = temp;
tail = temp;
}

temp->next = 0;
}

}

if(b){
	
	cout<<"\nInside2";


node *temp ;

while(b){
temp = new node;

temp->pow = b->pow;
temp->coeff = b->coeff;
b = b->next;


if(head == 0){
head = tail = temp;
}

else{

tail->next = temp;
tail = temp;
}

temp->next = 0;

}

}

}

};


int main(){


polynomial poly1, poly2,poly_result;

cout<<" POLYNOMIAL 1 .................\n";
poly1.getPolynomial();

cout<<" \n\nPOLYNOMIAL 2 .................\n";
poly2.getPolynomial();

cout<<" \n\nPOLYNOMIAL 1 .................\n";
cout<<" P1(X) = ";
poly1.showPolynomial();

cout<<" \n\nPOLYNOMIAL 2 .................\n";
cout<<" P2(X) = ";
poly2.showPolynomial();

poly_result.addPolynomial(poly1.head,poly2.head);

cout<<" \n\nRESULTANT POLYNOMIAL  .................\n";
cout<<" P(X) = ";
poly_result.showPolynomial();

return 0;

}
























 
