#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node * left, *right;
};

int getheight(struct node * root)
{
    if (root==NULL)
        return 0;
    int lh=getheight(root->left);
    int rh=getheight(root->right);
    return (lh>rh?lh:rh)+1;
}

struct node * create(int data)
{
    struct node * newnode=malloc(sizeof(struct node));
    newnode->info=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct node * insert(struct node * root, int data)
{
    if (root==NULL)
        return create(data);
    
    if (root->info>data)
        root->left = insert(root->left, data);
    
    else 
        root->right=insert(root->right, data);
    
    return root;
}

struct node * findInOrderSucessor(struct node * root)
{
    struct node * current=root;
    while (current->left!=NULL)
        current=current->left;
    return current;
}

struct node * delete(struct node * root, int key)
{
    if (root==NULL)
        return NULL;
    else if (root->info>key)
        root->left=delete(root->left,key);
    else if(root->info<key)
        root->right=delete(root->right, key);
    
    else
    {
        if (root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left==NULL)
        {
            struct node * temp=root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL)
        {
            struct node * temp=root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node * temp = findInOrderSucessor(root->right);
            root->info=temp->info;
            root->right=delete(root->right, temp->info);
        }
    }
    return root;
}

int countLeaf(struct node * root)
{
    if (root==NULL)
        return 0;
    else if (root->left==NULL && root->right==NULL)
        return  1;
    return countLeaf(root->left)+countLeaf(root->right);
}


