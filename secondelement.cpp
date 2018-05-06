#include<iostream>
using namespace std;
void secondmaxelement(int arr[], int n)
{
  int max = arr[0];
  int secondmax = 0;
  for(int i =0; i<n; i++)
  {
     if(arr[i] > max)
	 {
	   secondmax = max;
	   max = arr[i];
	 }
	 else if(arr[i] > secondmax && arr[i] ! = max)
	 {
	    secondmax = arr[i]
	 }
  }
  cout<< secondmax ;
}
int main()
{
  std::vector<int>
  int arr[] = {4, 5, 1, 7, 1, 6};
  secondmaxelement(arr, 6);
 return 0;
}