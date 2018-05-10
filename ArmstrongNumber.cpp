#include <iostream>
using namespace std;
int power(int rem, unsigned int digit)
{
    if(digit == 0)
    {
        return 1;
    }
    if( digit%2 ==0)
    {
        return power(rem, digit/2)*power(rem, digit/2);
    }
    
    return rem* power(rem, digit/2)*power(rem, digit/2);
}
int order(int n)
{ 
    int count =0;
    while(n !=0)
    {
        count++;
        n = n/10;
    }
    return count;
}
bool isArmstrong(int n)
{
    unsigned int digit = order(n);
    int rem =0;
    int sum =0;
    int temp =n;
    while(n)
    {
        rem = n%10;
        
        cout<< rem <<" "<< digit <<endl;
        sum += power(rem, digit);
        n = n/10;
        cout<< sum <<endl;
        cout<< n <<endl;
    }
    return (sum == temp);
}
int main() {
	int n;
	cin>> n;
	cout<< n <<"is ArmstrongNumber:: "<< isArmstrong(n);
	return 0;
}