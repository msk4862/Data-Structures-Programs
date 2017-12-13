#include<iostream>
#include<cstdlib>

using namespace std;

//Used in Merge Sort
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


//Used in Quick Sort

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];    
    int i = (low + 1);
	
	int t;  
 
    for (int j = low + 1; j < high; j++)
    {
       
        if (arr[j] < pivot)
        {
			  
            t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
             
            i++;  

        }
    }
    
    t = arr[i-1];
    arr[i-1] = arr[low];
    arr[low] = t;
    
    return (i - 1);
}
	

//Bubble Sort
template <class T>
void Bsort(T a[], int s) {

T temp;

	for(int i=0; i < s-1; ++i) {
		for(int j=i+1; j < s; ++j) {
		
			if(a[i] > a[j]) {
			
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			
		}
	}
	
	cout<<"Sorted array: ";
	for(int i=0;i<s;++i) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


//Selection Sort
void Ssort(int a[], int s) {

	int temp, min=a[0], minI, f=0;;
	
	for(int i=0; i < s-1; ++i) {
		min=a[i];
		f=0;
		for(int j=i+1; j < s; ++j) {
			if (min > a[j]) {
				min = a[j];
				minI = j;
				f=1;
			}
		}
		
		if(f==1) {
		temp = a[i];
		a[i] = min;
		a[minI] = temp;
		}
		

	}
	
	cout<<"Sorted array: ";
	for(int i=0;i<s;++i) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
}
	

//Insertion Sort

void Isort(int a[], int s) {

	int temp;
	int key;
	int keyI;
	
	for(int i=1; i < s; ++i) {
		key = a[i];
		keyI = i;
		
		while(keyI > 0 && a[keyI-1] > key) {
			temp = a[keyI-1];
			a[keyI-1] = key;
			a[keyI] = temp;
		
		keyI--;
		}
	}
	
	cout<<"Sorted array: ";
	for(int i=0;i<s;++i) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
}


//Merge Sort
void Msort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
 
        Msort(arr, l, m);
        Msort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
    
}

//Quick Sort
void Qsort(int arr[], int low, int high)
{
    if (low < high)
    {
     
        int pi = partition(arr, low, high);
 
       
        Qsort(arr, low, pi - 1);
        Qsort(arr, pi + 1, high);
    }
}





int main() 
{
	/*void Bsort(T* , int );
	
	void Ssort(int* , int );
	
	void Isort(int* , int );
	
	void Msort(int*, int, int);
	
	void Qsort(int*, int, int);*/
	
	int n, choice;
	char ch;
	
	cout<<"Enter size of the array:";
	cin>>n;
	
	int a[n];
	
	cout<<"Enter the array:\n";
	
	for(int i=0;i<n;++i) {
		cin>>a[i];
	}
	
	do {
	cout<<"\n1. Sort using Bubble sort";
	cout<<"\n2. Sort using Insertion sort";
	cout<<"\n3. Sort using Selection Sort";
	cout<<"\n4. Sort using Merge sort";
	cout<<"\n5. Sort using Quick sort";
	cout<<"\n6.EXIT";
	cout<<"\n\nEnter your choice: ";
	cin>>choice;
	
	
		switch(choice) {
	
			case 1: Bsort<int>(a, n);
				break;
			
			case 2: Isort(a, n);
				break;
					
			case 3: Ssort(a, n);
				break;
			
			case 4: Msort(a, 0, n);
			
					cout<<"Sorted array: ";
    	
					for(int i=0;i<n;++i) {
						cout<<a[i]<<" ";
					}
					cout<<endl;
				break;
				
			case 5:  Qsort(a, 0, n);
			
					cout<<"Sorted array: ";
    	
					for(int i=0;i<n;++i) {
						cout<<a[i]<<" ";
					}
					cout<<endl;
				break;
				
			case 6: exit(0);
			
			default:cout<<"WRONG CHOICE!!!";
			
		}
	
	}while(true);
	
	
	return 0;
	
	
	
}




			
	

	
