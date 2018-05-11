#include <bits/stdc++.h>
using namespace std;
struct Node{
    struct Node* left;
    struct Node* right;
    int data;
};

struct Node* newNode(int key)
{
    struct Node* newN = (struct Node*)malloc(sizeof(struct Node));
    newN->left = NULL;
    newN->right = NULL;
    newN->data = key;
}
int maxwidth(struct Node* root)
{
    if(root == NULL)
       return 0;
    int res =0;
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int count = q.size();
        res = max(count, res);
        while(count--)
        {
            Node* temp = q.front();
            q.pop();
            
            if(temp->left != NULL)
               q.push(temp->left);
            if(temp->right != NULL)
               q.push(temp->right);
        }
    }
    return res;
}
void print(struct Node* root)
{
    if(root == NULL)
       return;
    
    cout<< root->data <<" ";
    print(root->left);
    print(root->right);
    
}
int height(struct Node* root)
{
    if(root == NULL)
       return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(lh > rh)
       return lh+1;
    else{
        return rh+1;
    }
    
}
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    print(root);
    int width = maxwidth(root);
    int hight = height(root);
    cout<< width <<" "<<hight ;
	return 0;
}