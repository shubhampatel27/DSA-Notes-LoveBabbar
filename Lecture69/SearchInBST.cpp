#include <bits/stdc++.h>
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    // Write your code here.
    if (root == NULL)
        return false;
    else if (root->data == x)
        return true;

    else if (root->data > x)
        return searchInBST(root->left, x);
    else
        return searchInBST(root->right, x);
}


//  iterative way 


#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    BinaryTreeNode<int> * temp = root;
    while(temp != NULL){
        if(temp->data == x) return true;

        else if (temp->data > x) {
            temp = temp->left;
        } 
        else {
            temp = temp->right;
        }
    }
    return false;
}