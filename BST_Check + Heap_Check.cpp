#include <iostream>
#include "std_lib_facilities.h"

// Takes a pointer to the BTNode class object, runs recursively, determines if the tree is a BST, a heap, or neither, returning 1, 2, or 3 respectively.
// We assume that the input tree is complete, so we don't have to ensure the leaves are as far left as possible.
// Assume that the input pointer points to the root of the tree that we want to examine

class BTNode {
    public:
        int info;
    BTNode* left;
    BTNode* right;
    BTNode(int el, BTNode* l = NULL, BTNode* r = NULL) {
        info = el; left = l; right = r;
    }
};

bool BSTcheck(BTNode* p)
{
    if (p != NULL)
    {
        if (p->left == NULL && p->right == NULL)
        {
            return true;
        }
        if (p->left != NULL && p->right != NULL)
        {
            if (p->left->info < p->info && p->right->info > p->info && (p->right->left == NULL || p->right->left->info > p->info)) // Cond for a BST node is satisfied
            {
                if (BSTcheck(p->left) && BSTcheck(p->right)) // Checks if same conditions are met for all descendants of BST Node, returns true if so 
                {
                    return true;
                }
            }
            else {return false;} // Info on left was greater than parent node, or info on right was lesser than parent node. Cond(s) not satisfied
        }
        else if (p->left != NULL) // Believe these cases apply only when the tree is not complete, but they do work 
        {
            if (p->left->info < p->info)
            {
                return BSTcheck(p->left);
            }
        }
        else if (p->right != NULL)
        {
            if (p->right->info > p->info)
            {
                return BSTcheck(p->right);
            }
        }
    }
    else {return false;}
}

bool Heapcheck(BTNode *p) // Check that every child value is lesser than the parent value (Assumes we account for just "max" heaps, as those are demonstrated in the lectures)
{
    if (p != NULL)
    {
        if (p->left != NULL)
        {
            if (p->left->info < p->info)
            {
                return Heapcheck(p->left);
            }
            else {return false;}
        }
        if (p->right != NULL)
        {
            if (p->right->info < p->info)
            {
                return Heapcheck(p->right);
            }
            else {return false;}
        }
        if (p->left == NULL && p->right == NULL)
        {
            return true;
        }
    }
    else {return false;}
}

int isBSTorHeap(BTNode *p)
{
    if (BSTcheck(p))
    {
        cout << "Entered node was the root of a BST." << endl;
        return 1;
    }
    if (Heapcheck(p))
    {
        cout << "Entered node was the root of a Heap." << endl;
        return 2;
    }
    if (!BSTcheck(p) && !Heapcheck(p))
    {
        cout << "Entered node wasn't the root of a BST nor a Heap." << endl;
        return 3;
    }
}
