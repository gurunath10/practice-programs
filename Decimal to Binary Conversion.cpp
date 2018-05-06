// C++ program to convert a decimal
// number to binary number

#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

// function to convert decimal to binary
void decToBinary(int n)
{
    string str;
    int i=0;
    while(n>0)
    {
        int rem =n%2;
        str.push_back((char)('0'+rem));
        n = n/2;
        i++;
    }
    reverse(str.begin(),str.end());
	// printing binary array in reverse order
	cout << str;
}

// Driver program to test above function
int main()
{
	int n = 17;
	decToBinary(n);
	return 0;
}
