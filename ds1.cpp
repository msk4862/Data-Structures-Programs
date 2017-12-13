#include<iostream>

using namespace std;


int main(){

int size ;

cout<<" ENTER THE NUMBER OF ROWS FOR m x m MATRIX "<<endl;
cin>>size;

int len1,len2,len3,len4;
int *arr1,*arr2,*arr3,*arr4;
int matrix[size][size];

cout<<"=================== MENU ==================="<<endl;
cout<<"(1) DIAGONAL MATRIX"<<endl;
cout<<"(2) LOWER TRIANGULAR MATRIX"<<endl;
cout<<"(3) UPPER TRIANGULAR MATRIX"<<endl;
cout<<"(4) SYMMETRIC MATRIX"<<endl;
cout<<endl<<endl;

cout<<" ENTER YOUR CHOICE"<<endl;
int choice;
cin>>choice;

int row,col,elm;
char ch;

switch(choice){

case 1 :  arr1 = new int[size];
      
           cout<<" START ENTERING......."<<endl;
           for(int i=0;i<size;i++)
           {
            cin>>row;
            //cout<<" ";
            cin>>col;
            //cout<<" ";
            cin>>elm;
            while(row!=col){
             cout<<" the element at "<<row<<" "<<col<<" should be zero"<<endl;
             cout<<" enter again....."<<endl;
             cin>>row;
             //cout<<" ";
             cin>>col;
             //cout<<" ";
             cin>>elm;
             }

             int addr = row*0+col;
              arr1[addr] = elm; 
           }

          
           cout<<" THE GIVEN DIAGONAL MATRIX IN 1D ARRAY IS : ";
           for(int i=0;i<size;i++)
           cout<<arr1[i]<<" ";

          
           
           do{
             cout<<"enter row :";
             cin>>row;
             cout<<"enter column :";
             cin>>col;
          
             if(row == col)
              cout<<" required element is : "<<arr1[row]<<"\n";
              else
                         cout<<" required element is :  0"<<"\n";

            cout<<"\n\n want more output ( y/n ):: ";
            cin>>ch;
            }while(ch=='y');

           
           break;


case 2 :   
           
           len2 = size*(size+1)/2;
              arr2 = new int[len2];

           cout<<" START ENTERING......."<<endl;
           for(int i=0;i<len2;i++)
           {
            cin>>row;
            //cout<<" ";
            cin>>col;
           // cout<<" ";
            cin>>elm;
             while(row<col){
              
             cout<<" the element at "<<row<<" "<<col<<" should be zero"<<endl;
             cout<<" enter again....."<<endl;
             cin>>row;
             //cout<<" ";
             cin>>col;
             //cout<<" ";
             cin>>elm;
             }

              int addr = (row*(row+1)/2)+col;
              arr2[addr] = elm; 

            }

           cout<<" THE GIVEN LOWER MATRIX IN 1D ARRAY IS : ";
           for(int i=0;i<len2;i++)
           cout<<arr2[i]<<" ";

           
           do{
             cout<<"enter row :";
             cin>>row;
             cout<<"enter column :";
             cin>>col;
          
             if(row >= col)
              cout<<" required element is : "<<arr2[row*(row+1)/2 + col]<<"\n";
              else
                         cout<<" required element is :  0"<<"\n";

            cout<<"\n\n want more output ( y/n ):: ";
            cin>>ch;
            }while(ch=='y');

           
           break;


case 3 :   
           len3 = size*(size+1)/2; 
           arr3 = new int[len3];

           cout<<" START ENTERING......."<<endl;
           for(int i=0;i<len3;i++)
           {
            cin>>row;
            //cout<<" ";
            cin>>col;
            //cout<<" ";
            cin>>elm;
             while(row>col){
              
             cout<<" the element at "<<row<<" "<<col<<" should be zero"<<endl;
             cout<<" enter again....."<<endl;
             cin>>row;
             //cout<<" ";
             cin>>col;
             //cout<<" ";
             cin>>elm;
             }

              int addr = size*row+col - (row*(row+1))/2;              

               arr3[addr] = elm; 

            }

           cout<<" THE GIVEN UPPER MATRIX IN 1D ARRAY IS : ";
           for(int i=0;i<len3;i++)
           cout<<arr3[i]<<" ";

             
           
           do{
             cout<<"enter row :";
             cin>>row;
             cout<<"enter column :";
             cin>>col;
          
             if(row <= col)
              cout<<" required element is : "<<arr3[row*size + col - row*(row+1)/2 ]<<"\n";
              else
                         cout<<" required element is :  0"<<"\n";

            cout<<"\n\n want more output ( y/n ):: ";
            cin>>ch;
            }while(ch=='y');

           
           break;


case 4 :   len4 = size*(size+1)/2; 
           arr4 = new int[len4];

           cout<<" START ENTERING.......(enter only upper triangular part)"<<endl;
           for(int i=0;i<len4;i++)
           {
            cin>>row;
            //cout<<" ";
            cin>>col;
            //cout<<" ";
            cin>>elm;
          

              int addr = size*row+col - (row*(row+1))/2;              

               arr4[addr] = elm; 

            }

           cout<<" THE GIVEN UPPER MATRIX IN 1D ARRAY IS : ";
           for(int i=0;i<len4;i++)
           cout<<arr4[i]<<" ";

             
           
           do{
             cout<<"enter row :";
             cin>>row;
             cout<<"enter column :";
             cin>>col;
          
             if(row <= col){
              cout<<" required element is : "<<arr4[row*size + col - row*(row+1)/2 ]<<"\n";
              }
              else{
                         cout<<" required element is : "<<arr4[col*size + row - col*(col+1)/2 ]<<"\n";
              }

            cout<<"\n\n want more output ( y/n ):: ";
            cin>>ch;
            }while(ch=='y');

           
           break;




}



return 0;

}

