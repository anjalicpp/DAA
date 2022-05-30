Program-2
Program to find wheather a given key element is present in the  array or not and also total number of comparisons .
Problem Statement:Given an already sorted array of positive integers ,design an algorithm and implement it using a program to find whether 
given key element in the array or not . Also ,find total number of comparisons for each input case .(Time Complexity:O(logn),where n is size of input).
  
Algorithm:
Read key
search(a[0].......a[n])
{
  c=0   //no of comparisons
    mid=(l+r)/2;
  while(l<r)
  {  if a[mid]==key   //key if found in middle index
    Print "Present"
    Print c
    Return 
    else if element at mid index is less than key 
    l=(mid+1)/2  // for searching in upper half
    mid=(l+r)/2
    else if element at mid is greater than key
     r=mid-1  //for searching in lower half 
    mid=(l+r)/2    
 
  }

   Print "Not Possible";
   Print c 
}

Complexity analysis:
Time complexity:
Worst Case:T(n)=O(logn)
Best Case:T(n)=O(logn)
Average Case:T(n)=O(logn)

Space Complexity:
Worst case=Best case=Average case=O(1)

SOURCE CODE:

#include<iostream>
using namespace std;

void search(int a[],int l,int r,int key)
{
int c=0;
int mid=(l+r)/2;
while(l<=r)
{c++;
  if(a[mid]==key)
  {cout<<"Present:No of comparisons:"<<c<<endl;
    return;}
 else if(a[mid]>key)
{
r=mid-1;
mid=(l+r)/2;
}
else { l=mid+1;
       mid=(l+r)/2 }
}
cout<<"Not Present :No .of comparisons"<<c<<endl;
}

int main()
{
int t,n,k;
cout<<"Enter the no of test cases";cin>>t;
while(t>0)
{
int c=0;
cout<<"Enter the size of array ";cin>>n;
int a[n];
cout<<"Enter the array:";
for(int i=0;i<n;i++)
cin>>a[i];
cout<<"Enter key to be searched:";cin>>k;
search(a,0,n-1,k);
t--;
}
}
