#include <iostream>
using namespace std;
void conquer(int arr[],int si,int mid,int ei)
{
	int merged[ei-si+1];
	int index1=si,index2=mid+1,x=0;
	while(index1 <= mid && index2 <=ei)
	{
		if(arr[index1] <= arr[index2])
			merged[x++] = arr[index1++];
		else
			merged[x++] = arr[index2++];
	}
	while (index1 <= mid)
		merged[x++] = arr[index1++];
	while (index2 <= ei)
		merged[x++] = arr[index2++];
	for (int i = 0,j = si; i < (ei-si+1); i++, j++)
		arr[j] = merged[i];
}
void divide(int arr[],int si,int ei)
{
	if(si >= ei)
		return;
	int mid = si + (ei-si)/2;
	divide(arr,si,mid);
	divide(arr,mid+1,ei);
	conquer(arr,si,mid,ei);
}

int main()
{
	cout<<"Enter Array Size: ";
	int n;
	cin>>n;
	cout<<endl<<"-:Enter Array Elements:-"<<endl;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];

	cout<<"\n-:Orginal Array:-"<<endl;
	for(int i:a)
	cout<<i<<" ";
	cout<<endl;

	divide(a,0,n-1);

	cout<<"\n-:Sorted Array:-"<<endl;
	for(int i:a)
		cout<<i<<" ";
	cout<<endl;
}