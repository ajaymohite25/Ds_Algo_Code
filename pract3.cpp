#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Return the root of the modified BST after deleting the node with value X

void successor(Node *z, int k)
{
    Node *x = z->left;
    Node *y = NULL;

    if (x->left == NULL && x->right == NULL)
    {
        z->data = x->data;
        z->left == NULL;

        delete x;
    }
    else
    {
        while (x->right != NULL)
        {
            y = x;
            x = x->right;
        }

        z->data = x->data;
        y->right = x->left;

        delete x;
    }
}

void predassor(Node *z, int k)
{
    Node *x = z->right;
    Node *y = NULL;

    if (x->left == NULL && x->right == NULL)
    {
        z->data = x->data;
        z->right = NULL;

        delete x;
    }
    else
    {
        while (x->left != NULL)
        {
            y = x;
            x = x->left;
        }

        z->data = x->data;
        y->left = x->right;

        delete x;
    }
}

void del(int elemt, Node *p, Node *q)
{
    if (p == NULL)
        return;
    if (p->data > elemt)
        del(elemt, p->left, p);
    else if (p->data < elemt)
        del(elemt, p->right, p);
    else if (p->data == elemt)
    {
        if (p->left != NULL)
        {
            Node *r = p->left;
            Node *t = r;
            Node *z = r;
            while (r->right != NULL)
            {
                t = r;
                r = r->right;
            }
            p->data = r->data;
            if (z->right == NULL)
                p->left = NULL;
            t->right = r->left;
            delete r;
        }
        else if (p->right != NULL)
        {
            Node *l = p->right;
            Node *t = l;
            Node *z = l;
            while (l->left != NULL)
            {
                t = l;
                l = l->left;
            }
            p->data = l->data;
            if (z->left == NULL)
                p->right = NULL;
            t->left = l->right;
            delete l;
        }
        else if (p->left == NULL and p->right == NULL)
        {
            if (q->data > elemt)
            {
                q->left = NULL;
                delete p;
            }
            else
            {
                q->right = NULL;
                delete p;
            }
        }
    }
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (root->left == NULL && root->right == NULL)
    {
        if (key == root->data)
        {
            delete root;

            return NULL;
        }
        else
            return root;
    }

    del(key, root, NULL);

    return root;
}

int main()
{

    struct Node *root, *second, *temp;

    root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    // del(1, root, NULL);
    deleteNode(root, 1);
    cout << root->data;
    // cout << root->left->data;
    cout << root->right->data;
    return 0;
}