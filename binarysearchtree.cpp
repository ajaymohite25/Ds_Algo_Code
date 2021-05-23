#include <iostream>
using namespace std;
class treenode
{
public:
    int data;
    treenode *lch = NULL;
    treenode *rch = NULL;
};
class binarysearchtree
{
public:
    treenode *root = NULL;
    void treecreate(int, treenode *, treenode *);
    void display(treenode *);
    void del(int, treenode *p, treenode *q);
};
void binarysearchtree::treecreate(int dt, treenode *p, treenode *q)
{
    if (p != NULL)
    {
        if (p->data > dt)
            treecreate(dt, p->lch, p);
        else if (p->data < dt)
            treecreate(dt, p->rch, p);
        // else
        // {
        //     cout << "duplication not allowed" << endl;
        //     cin >> dt;
        //     treecreate(dt, root, NULL);
        // }
    }
    if (root == NULL)
    {
        root = new treenode;
        root->data = dt;
        root->lch = root->rch = NULL;
        return;
    }
    else if (p == NULL)
    {
        if (q->data > dt)
        {
            treenode *lchild = new treenode;
            lchild->data = dt;
            lchild->lch = lchild->rch = NULL;
            q->lch = lchild;
        }
        else if (q->data < dt)
        {
            treenode *rchild = new treenode;
            rchild->data = dt;
            rchild->lch = rchild->rch = NULL;
            q->rch = rchild;
        }
    }
}
void binarysearchtree::del(int elemt, treenode *p, treenode *q)
{

    if (p->data > elemt)
        del(elemt, p->lch, p);
    else if (p->data < elemt)
        del(elemt, p->rch, p);
    else if (p->data == elemt)
    {
        if (p->lch != NULL)
        {
            treenode *r = p->lch;
            treenode *t = r;
            treenode *z = r;
            while (r->rch != NULL)
            {
                t = r;
                r = r->rch;
            }
            p->data = r->data;
            if (z->rch == NULL)
                p->lch = NULL;
            t->rch = r->lch;
            delete r;
        }
        else if (p->rch != NULL)
        {
            treenode *l = p->rch;
            treenode *t = l;
            treenode *z = l;
            while (l->lch != NULL)
            {
                t = l;
                l = l->lch;
            }
            p->data = l->data;
            if (z->lch == NULL)
                p->rch = NULL;
            t->lch = l->rch;
            delete l;
        }
        else if (p->lch == NULL and p->rch == NULL)
        {
            if (q->data > elemt)
            {
                q->lch = NULL;
                delete p;
            }
            else
            {
                q->rch = NULL;
                delete p;
            }
        }
    }
}
void binarysearchtree::display(treenode *temp)
{
    if (temp != NULL)
    {
        display(temp->lch);
        cout << temp->data << " ";
        display(temp->rch);
    }
}
int main()
{
    int dt, no;
    binarysearchtree tr1;
    cout << "enter no. of nodes" << endl;
    cin >> no;
    int arr[no];
    for (int i = 0; i < no; i++)
        cin >> arr[i];
    for (int i = 0; i < no; i++)
    {
        tr1.treecreate(arr[i], tr1.root, NULL);
    }
    tr1.display(tr1.root);
    tr1.del(15,tr1.root,NULL);
    cout<<endl;
    tr1.display(tr1.root);
}
