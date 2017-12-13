#include<iostream>
using namespace std;

template<class t>
class node
{
 public:
       t data;
       node *prev,*next;
       
		node(int i, node* adr=NULL, node* pre = NULL) {
			
				data = i;
				next = adr;
				prev = pre;
		}
};

template<class t>
class  dlist
{
       int n;
       node<t> *head, *tail;
      
       public:
              dlist()
              {
                     head=NULL;
                     tail=NULL;
              }
             
              //create function
              void create()
              {
                     node<t> *current,*temp;
                     char ch;
                     //fflush(stdin);
                    
                     first=new node<t>;
                     cout<<"Enter data for first node:\n";
                     cin>>first->data;
                     current=first;
                     first->next=NULL;
                     first->prev=NULL;
                     last=first;
      
      
                     do
                     {
                                cout<<"Want to enter more data:\n";
                                cin>>ch;
                                if(ch=='y')
                                {
                                           n=count();
                                           this->insert(n+1);
                                }
                     }while(ch=='y');
              }
             
              //display function
              void display()
              {
                   node<t> *t;
                   
                   current=head;
                   
                   cout<<"Linked list:\n";
                   while(current!=NULL)
                   {
                           cout<<t->data<<" <-> ";
                           t=t->next;
                   }
                   cout<<"\n";
              }
             
              //reverse function
              /*void reverse()
              {

                   //fflush(stdin);
                   node<t> *t;
                   t = tail;
                   cout<<"The data after reversing the linked list:\n";
                   for(int i=1;i<=n;i++)
                   {
                           cout<<current->data<<" -> ";
                           current=current->prev;
                   }
              }*/
             
              //count function
              int count()
              {
                   int c = 0;
                   node<t> *t;
                   tail = head;
                   while(t!=NULL)
                   {
                        c++;
                        t = t->next;
                   }
                   return c;
              }  
             
             
              //insert function
             void insert(int n1)
             {
                  int b=count();
                  
                  if(n1<=b+1)
                  {
                            node<t> *cur,*forw,*temp;
                            
                            current=head;
                            
                            temp=new node<t>;
                            
                            cout<<"Enter data:\n";
                            cin>>temp->data;
                            
                            temp->next=temp->prev=NULL;
                            if(n1==1)
                            {
                                    temp->next=first;
                                    first->prev=temp;
                                    first=temp;
                            }
                            else if(n1<=b)
                            {
                                    for(int i=1;i<n-1;i++)
                                    current=current->next;
                                   
                                    forward=current->next;
                                    temp->next=forward;
                                    current->next=temp;
                                    temp->prev=current;
                                    forward->prev=temp;
                            }
                            else
                            {
                                    last->next=temp;
                                    temp->prev=last;
                                    last=temp;
                            }
                  }
                  else
                  cout<<"Can't be inserted\n";
             }
            
             //search function
             void search()
             {
                  int flag=0;
                  cout<<"Enter data to be searched:\n";
                  cin>>n;
                  node<t> *current,*previ,*temp;
                  int b=count();
                  current=first;
                  for(int i=1;i<=b;i++)
                  {
                          if(current->data==n)
                          {
                                              flag=1;
                                              break;
                          }
                          current=current->next;
                  }
                 
                  if(flag!=0)
                  {
                             previ=current->prev;
                             int c;
                             cout<<"Data found:\nEnter what you wannna do:\n 1.delete data\n 2.replace it\n 3.do nothing\n";
                             cin>>c;
                             switch(c)
                             {
                                      case 1:temp=current;
                                             if(current->next!=NULL)
                                             {
                                                                    current=current->next;
                                                                    previ->next=current;
                                                                    current->prev=previ;
                                             }
                                             else
                                             {
                                                                    previ->next=NULL;
                                                                    current->prev=NULL;
                                             }
                                             delete(temp);
                                             cout<<"Data deleted:\n";
                                             this->display();
                                             break;
                                      case 2:cout<<"Enter new data:\n";
                                             cin>>current->data;
                                             cout<<"data replaced:\n";
                                             this->display();
                                             break;
                                      case 3:break;
                                      default:cout<<"wrong choice:\n";
                             }
                  }
                  else
                  cout<<"Data not found:\n";
             }   
                 
                
};       

             
      
