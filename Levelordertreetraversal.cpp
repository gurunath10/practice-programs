#include <iostream>
//#include <cmath>
#include <climits>
//#include<bits/stdc++.h>
using namespace std;

struct node{
   int data;
   struct node* left;
   struct node* right;
};
void printleveorderone(struct node* root, int level)
{
    if(root == NULL)
       return;
    if(level == 1)
    {
        cout<<root->data<<" ";
    }else if(level>1){
        printleveorderone(root->left, level-1);
        printleveorderone(root->right, level-1);
    }
}
int height(struct node* root)
{
    if(root == NULL)
    {
        return 0;
    }else{
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh>rh)
      return(lh+1);
    else
      return(rh+1);
    }
}
void printleveorder(struct node* root)
{
    int h = height(root);
    for(int i=1;i<=h;i++)
    {
        printleveorderone(root, i);
    }
}

struct node* newNode(int data)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return (newnode);   
}
int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printleveorder(root);
	return 0;
}