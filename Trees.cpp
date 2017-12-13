#include<iostream>
using namespace std;

template<class t>
class node
{
 public:
       t data;
       node *left,*right;
       
		node(int i) {
			
				data = i;
		}
};

template<class t>
class  trees
{
public:
       node<t> *root;
      
              trees()
              {
                     root=NULL;
              }
              
//        node<t> *insert(node<t> *n, t i);
        void insert(t i);
        void inOrder(node<t> *n);
        void preOrder(node<t> *n);
        void postOrder(node<t> *n);
        
        int deletionByCopy(t i);
        void deleteLeaf(node<t> *p, node<t> *n);
        void deleteOneChild(node<t> *p, node<t> *n);
        void deleteTwoChild(node<t> *p, node<t> *n);
        
        int deletionByMerging(t i);
        void deleteTwoChildByMerge(node<t> *p, node<t> *n);


        
};

template<class t>
void trees<t>:: insert(t i) {
	
	node<t> *ptr = new node<t>(i);
	
	node<t> *temp = root;
	node<t> *prev = root;

	
    while(temp)
    {
        prev = temp;
        if (temp->data < ptr->data)
            temp = temp->right;
        else
            temp = temp->left;
    }
    
    //First node
    if (prev==NULL)
        root = ptr;
        
    else
    {
        if (prev->data < ptr->data)
            prev->right = ptr; 
        else
            prev->left = ptr;
    }	 
}		


		
template<class t>
void trees<t> :: inOrder(node<t> *n) {
	
	if(n == NULL) {
		return;
	}
	else {
		inOrder(n->left);
		
		cout<<n->data<<endl;
		
		inOrder(n->right);
	}
}

template<class t>
void trees<t> :: preOrder(node<t> *n) {
	
	if(n == NULL) {
		return;
	}
	else {
		
		cout<<n->data<<endl;

		preOrder(n->left);
		
		preOrder(n->right);
	}
}

template<class t>
void trees<t> :: postOrder(node<t> *n) {
	
	if(n == NULL) {
		return;
	}
	else {
		postOrder(n->left);
		
		postOrder(n->right);
		
		cout<<n->data<<endl;
	}
}


template<class t>
int trees<t> :: deletionByCopy(t i) {

	node<t> *n = root;
	node<t> *p = root;
	
	while (n != NULL) {
		
		if(i == n->data) {
			
			
			//Leaf Node
			if(n->left == NULL && n->right == NULL) {
				deleteLeaf(p, n);
			}
			
			//One Child Node
			else if((n->left != NULL && n->right == NULL) || (n->left == NULL && n->right != NULL)) {

				deleteOneChild(p, n);
			}
			
			//Two Child Nodes
			else {

				deleteTwoChild(p, n);
			}
			
			//Deletion Successfull
			return 1;
		}
		
		else if(i < n->data) {
			p = n;
			n = n->left;
		}
		else {
			p = n;
			n = n->right;
		}
	}
	
//node not found
return -1;
	
}


template<class t>
int trees<t> :: deletionByMerging(t i) {

	node<t> *n = root;
	node<t> *p = root;
	
	while (n != NULL) {
		
		if(i == n->data) {
			
			
			//Leaf Node
			if(n->left == NULL && n->right == NULL) {
				deleteLeaf(p, n);
			}
			
			//One Child Node
			else if((n->left != NULL && n->right == NULL) || (n->left == NULL && n->right != NULL)) {

				deleteOneChild(p, n);
			}
			
			//Two Child Nodes
			else {

				deleteTwoChildByMerge(p, n);
			}
			
			//Deletion Successfull
			return 1;
		}
		
		else if(i < n->data) {
			p = n;
			n = n->left;
		}
		else {
			p = n;
			n = n->right;
		}
	}
	
//node not found
return -1;
	
}

template<class t>
void trees<t> :: deleteLeaf(node<t> *p, node<t> *n) {

	if(n == p->left) {
		p->left = NULL;
	}
	else {
		p->right = NULL;
	}
	
	delete n;
	 
}


template<class t>
void trees<t> :: deleteOneChild(node<t> *p, node<t> *n) {

	node<t> *c;

	if(n->left != NULL && n->right == NULL) {
		c = n->left;
	}
	else {
		c = n->right;
	}
	
	
	if(n == p->left) {
		p->left = c;
	}
	else {
		p->right = c;
	}
		
	delete n;
	 
}



template<class t>
void trees<t> :: deleteTwoChild(node<t> *p, node<t> *n) {

//Using Successor
	node<t> *s = n->right;
								cout<<"Inside - 21"<<endl;

	while(s->left != NULL ) {
		
								cout<<"Inside - 22"<<endl;

		p = s;
		s = s->left;
	}

								cout<<"Inside - 31"<<endl;

	n->data = s->data;

//Successor is a leaf node
	if(s->left == NULL && s->right == NULL) {
		
								cout<<"Inside - 23"<<endl;

		deleteLeaf(p, s);
	}
	
//Successor have one child node	
	else {
		
										cout<<"Inside - 4"<<endl;

		deleteOneChild(p, s);
	}
		 
}



template<class t>
void trees<t> :: deleteTwoChildByMerge(node<t> *p, node<t> *n) {

//Using Successor
	node<t> *s = n->right;
	node<t> *c = n->right;


	while(s->left != NULL ) {
		
		s = s->left;
	}

	s->left = n->left;

	if(n == p->left) {
		p->left = c;
	}
	else {
		p->right = c;
	}
		
	delete n;
		 
}

int main()
{
	trees<int> t;

	int choice;
	int data;
	int f;

	do {
	
		
		cout<<"\n\n\n1. Insertion";
		cout<<"\n2. In-Order traversal";
		cout<<"\n3. Pre-Order traversal";
		cout<<"\n4. Post-Order traversal";
		cout<<"\n5. Deletion by copying";
		cout<<"\n6. Deletion by merging";
		cout<<"\n7. EXIT";
		
		cout<<"\n\nEnter your choice:";
		cin>>choice;
		
		switch(choice) {
		
			case 1: cout<<"\nEnter data:";
				cin>>data;
				
				t.insert(data);
				cout<<"Successfully added "<<data<<"!!!";
				break;
				
			case 2:	cout<<"In-Order traversal: "<<endl;
			
					t.inOrder(t.root);
					
					break;
				
			case 3: cout<<"Pre-Order traversal: "<<endl;
			
					t.preOrder(t.root);
				break;
				
				
			case 4: cout<<"Post-Order traversal: "<<endl;
			
					t.postOrder(t.root);
				break;
			
			case 5: cout<<"\nEnter the node you want to delete:";
					cin>>data;
					f = t.deletionByCopy(data);
					
					if(f == 1) {
						cout<<data<<" Deleted Successfully!!!\n";	
					}
					else {
						cout<<data<<" not found!!!\n";	
					}
				break;

			case 6: cout<<"\nEnter the node you want to delete:";
					cin>>data;
					f = t.deletionByMerging(data);
					
					if(f == 1) {
						cout<<data<<" Deleted Successfully!!!\n";	
					}
					else {
						cout<<data<<" not found!!!\n";	
					} 
				break;

			case 7: exit(0);
				break;

			case 8: 
		}
	
	}while(true);
	
	

return 0;
}


             
