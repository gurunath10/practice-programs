#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MAX_SIZE 15
template<typename T>
class Vector{
    public:
       Vector():sz{0},capacity{MAX_SIZE},elem{nullptr}
       {
           cout<< "Constructor called"<<endl;
       }
       Vector(const T& s):sz{s},capacity{MAX_SIZE},elem{new T[s]}
       {
           cout<< "Constructor param int called"<<endl;
       }
       Vector(initializer_list<T>lst):sz{lst.size()},capacity{MAX_SIZE},elem{new T[sz]}
       {
           cout<< "initializer_list Constructor called"<<endl;
           copy(lst.begin(),lst.end(),elem);
       }
       Vector(const Vector<T>& arg):sz{arg.sz},capacity{MAX_SIZE},elem{new T[arg.sz]}
       {
           cout<< "Copy Constructor called"<<endl;
          // copy(arg,arg+arg.sz,elem);
          for(int i=0;i<sz;i++)
          {
              elem[i] = arg.elem[i];
          }
           
       }
       Vector& operator=(const Vector<T>& arg)
       {
           cout<< "Assignment called"<<endl;
           T* bp = new T[arg.sz];
           //copy(arg.elem, arg.elem+arg.sz,elem);
           sz = arg.sz;
           for(int i=0;i<sz;i++)
           {
              bp[i] = arg.elem[i];
           }
           delete[] elem;
           elem = bp;
           capacity = MAX_SIZE;
           bp = nullptr;
           return* this;
       }
       Vector(Vector<T>&& arg):sz{arg.sz},elem{arg.elem}
       {
           cout<< "Move called"<<endl;
           arg.sz =0;
           arg.elem =nullptr;
       }
       Vector& operator=(Vector<T>&& arg){
           delete[] elem;
           elem =arg.elem;
           sz = arg.sz;
           arg.sz = 0;
           arg.elem =nullptr;
           cout<< "Move Assignment called"<<endl;
           return*this;
       }
       T& operator[](const T& n)
       {
           return elem[n];
       }
       void push_back(const T& s)
       {
           if(sz == capacity)
           {
               capacity = capacity+MAX_SIZE;
           }
           elem[sz] = s;
           sz++;
       }
       T* begin()
       {
           return elem;
       }
       T* end()
       {
           return elem+sz;
       }
       void pop_back()
       {
           elem[sz-1];
           --sz;
       }
       ~Vector()
       {
           delete[] elem;
       }
       int size()
       {
           return sz;
       }
      private:
      T* elem;
      int sz;
      int capacity;
};
int main() {
	Vector<int>vec{1, 2, 3, 4};
	vec.push_back(5);
	vec.pop_back();
	Vector<int>v = vec;
	Vector<char>v1{'A','B','C'};
	Vector<char>v2;
 	v2 =v1;
	cout<< vec[2] <<endl;
	cout<< vec.size() <<endl;
	cout<< v[3] <<endl;
	cout<< v1[0] <<endl;
	cout<< v2[2] <<endl;
	return 0;
	
}

