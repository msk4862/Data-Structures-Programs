#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct memory_frame{
    int page_no;
};

struct page_table{
    int frame_no;
};

int main()
{
    srand(time(0));
    int m_size, p_size;
    cout<<"\nEnter the size of Main Memory : ";
    cin>>m_size;
    cout<<"\nEnter the size of Page        : ";
    cin>>p_size;

    int total_pg= m_size/p_size ;


    page_table my_table[total_pg];        // allocating page table


    memory_frame my_frame[total_pg];		// Dividing Main memory to Frames

    int arr[total_pg]={0};
    int r,random;
    for(int i=0; i<total_pg ;i++)
    {
        random = rand()%total_pg;

        r=random;
        if(arr[r] == 1)
        {
            i--;
            continue;
        }

        arr[r]=1;

        my_frame[i].page_no  = r;
        my_table[r].frame_no = i;
    }

    cout<<"============ Main Memory ==============="<<endl;
    cout<<"\n\tPage No'\tFrame No'\n";
    for(int r=0; r<total_pg ;r++)
    {
        cout<<"\t"<<r<<"\t\t"<<my_table[r].frame_no<<endl;
    }

    int pg_no,offset;
    cout<<"Enter the Logical address  "<<endl;
    cout<<"Enter the  Page No : ";
	cin>>pg_no;
    cout<<"Enter the Offset   : ";
	cin>>offset;

    if(pg_no >= total_pg || offset > p_size)
    {
        cout<<"Invalid Input"<<endl;
        return 1;
    }

    int physical_add = ( my_table[pg_no].frame_no * p_size ) + offset ;
    cout<<"The Physical Address is : "<<endl;
	cout<<physical_add;
    cout<<"\n\n";
    return 0;
}
