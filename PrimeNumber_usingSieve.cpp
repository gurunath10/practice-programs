#include <iostream>
#include<vector>
using namespace std;
vector<int> prime(int A)
{
    vector<int>vec(A, 1);
	vector<int>vec1;
    vec[0] = 0;
    vec[1] = 0;
    if(!vec.empty())
    {
        for(int i=2; i<A;i++)
        {
            if(vec[i] ==1)
            {
                for(int j=2; i*j<A; j++)
                {
                    vec[i*j] =0;
                }
            }
        }
        for(int i =0; i<A; i++)
        {
            if(vec[i] == 1)
            {
              vec1.push_back(i);
            }
        }
    }    
 return vec1;
}
int main() {
	vector<int>res;
	res = prime(11);
    for(int i =0; i<res.size(); i++)
    {
        cout<< res[i] <<" ";
    }
	return 0;
}