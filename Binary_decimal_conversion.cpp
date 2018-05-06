// C++ program to convert binary to decimal
#include<iostream>
using namespace std;

// Function to convert binary to decimal
int binaryToDecimal(int n)
{
    int remaindar;
    int decimla_num =0, base =1;
	while(n !=0)
	{
	    remaindar = n%10;
	    n = n/10;
	    decimla_num= decimla_num + remaindar*base;
	    base= base*2;
	}
	return decimla_num;
}

// Driver program to test above function
int main()
{
	int num = 1010;
	
	cout<<binaryToDecimal(num)<<endl;
}
