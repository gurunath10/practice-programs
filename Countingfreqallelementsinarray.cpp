#include <bits/stdc++.h>
using namespace std;
void freqApp(int arr[], int n)
{
    int i =0;
    while(n>i)
    {
       if(arr[i]<=0)
       {
           cout <<"Value of i::"<<" "<< i <<endl;
           i++;
           continue;
       }
       int elemindex = arr[i] -1;
       cout << "elemindex" << elemindex <<endl;
       if(arr[elemindex] >0)
       {
           arr[i] = arr[elemindex];
           cout <<"arr index with i"<<" "<< arr[i] <<endl;
           arr[elemindex] = -1;
       }else{
           
           arr[elemindex]--;
           arr[i] =0;
           i++;
       }
    }
    for(int i =0; i<n; i++)
    {
        cout<< i+1 <<"-->" << arr[i] <<endl;
    }
}
int main() {
    int n;
	cin >>n;
	int arr[n];
	for(int i=0; i < n; i++)
	{
	   
	   cin >> arr[i];
	}
	freqApp(arr , n);
	return 0;
}