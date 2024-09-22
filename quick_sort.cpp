#include <iostream>
using namespace std;
int partition(int a[],int left,int right)
{
	int pivot=a[right];
	int i=left-1;
	for(int j=left;j<right;j++)
	{
		if(pivot>a[j])
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	i++;
	swap(a[i],a[right]);
	return i;
}
void quick_sort(int a[],int left,int right)
{
	if(left>right)
	{
		return;
	}
	int pi=partition(a,left,right);
	quick_sort(a,left,pi-1);
	quick_sort(a,pi+1,right);
}
int main()
{
	int n;
	cout<<"Enter the size of array: ";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter element at index "<<i<<" : ";
		cin>>arr[i];
	}
	quick_sort(arr,0,n-1);
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}