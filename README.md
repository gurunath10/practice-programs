#include <iostream>
#include <stdlib.h>
using namespace std;
//template<class T>
struct node{
  int data;
  struct node* next;
  node():data{0},next{nullptr}
  {
      
  }
};
class List{
      
    public:
      List():len{0},head{nullptr},tail{nullptr}
      {
          cout<<"default construct call"<<endl;
          
      }
      
      List(int n):len{n},head{nullptr},tail{nullptr}
      {
          cout<<"construct call"<<endl;
      }
      void insert(int data)
     {
            
            struct node* current = new node;
            struct node* temp = new node;
            current->data = data;
            current->next = NULL;
            if(head == NULL)
            {
             head = current;
             tail = current;
             current = NULL;
            }else{
                temp = head;
                if(head->data <= data)
                {
                    while(temp->next != NULL && temp->next->data <data)
                    {
                        temp = temp->next;
                    }
                    current->next = temp->next;
                    temp->next = current; 
                    //tail->next = current;
                    tail = current;
                    cout<<"push end"<<endl;
                }else{
                    cout<<"pushfront again"<<endl;
                    pushfront(data);
                }
            }
      }
      void pushfront(int key)
      {
          struct node* newNode = new node;
          newNode->data = key;
          newNode->next = head;
          head = newNode;
          len++;
      }
      void pushend(int key)
      {
          struct node* newNode = new node;
          newNode->data = key;
          newNode->next  = NULL;
          struct node* current = head;
          while(current->next != NULL)
          {
              current = current->next;
          }
          current->next = newNode;
          tail = newNode;
          len++;
      }
      void print()
      {
          struct node* current = head;
          cout<<"print method gets called"<<endl;
          while(current != NULL)
          {
               cout<< current->data <<" ";
               current = current->next;
          }
      }
    private:
      node* head;
      node* tail;
      int len;
};
int main() {
    
    List lst;
    lst.insert(8);
    lst.insert(1);
    lst.insert(3);
    lst.insert(2);
    lst.insert(4);
    lst.insert(0);
    lst.insert(5);
    lst.pushend(6);
    lst.print();
	return 0;
}
