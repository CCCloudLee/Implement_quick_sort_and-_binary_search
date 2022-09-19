#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

void Linear_Sort(int [], int);
int Binary_Search(int [], int, int, int);

int main()
{
      srand(time(NULL));
      int arraysize=20;
      int i, data[arraysize], value;
      for(i=0;i<arraysize;i++)
      {
            data[i]=rand()%2000+1;
            //cout<<setw(4)<<data[i]<<" ";
      }
      //cout<<endl;
      Linear_Sort(data,arraysize);
      cout<<"Array: ";
      for(i=0;i<arraysize;i++)
            cout<<setw(4)<<data[i]<<" ";
      cout<<endl;
      cout<<"Input a number from 1 to 2000:";
      cin>>value;
      int OutCome=Binary_Search(data, value, 0, arraysize-1);
      if(OutCome==-1)
            cout<<"Not Found."<<endl;
      else
            cout<<value<<" is founded at "<<OutCome<<"."<<endl;

      system("pause");
      return 0;
}

void Linear_Sort(int a[], int size)
{
      for(int next=1;next<size;next++)
      {
            int insert=a[next], moveItem=next;
            while((moveItem>0)&&(a[moveItem-1]>insert))
            {
                  a[moveItem]=a[moveItem-1];
                  moveItem--;
            }
            a[moveItem]=insert;
      }
}

int Binary_Search(int a[], int value, int left, int right)
{
      if(left>right)
            return -1;
      int mid=(left+right)/2;
      if(a[mid]==value)
            return mid;
     if(value<a[mid])
            return Binary_Search(a, value, left, mid-1);
     else
            return Binary_Search(a, value, mid+1, right);
}
