#include <iostream>
using namespace std;
class treenode
{
public:
    int data;
    int height;
    treenode *lch = NULL;
    treenode *rch = NULL;
};
class avltree
{
public:
    treenode *root = NULL;
    void treecreate(int, treenode *, treenode *);
    void display(treenode *);
    void del(int, treenode *p, treenode *q);
    int heightt(treenode *);
    int balancefactor(treenode *);
    treenode *ll(treenode *);
    treenode *rr(treenode *);
    treenode *lr(treenode *);
    treenode *rl(treenode *);
};
int avltree::heightt(treenode *tr)
{
    int hl, hr;

    hl = tr && tr->lch ? tr->lch->height : 0;
    hr = tr && tr->rch ? tr->rch->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}
int avltree::balancefactor(treenode *tr)
{
    int hl, hr;

    hl = tr && tr->lch ? tr->lch->height : 0;
    hr = tr && tr->rch ? tr->rch->height : 0;
    return hl - hr;
}
treenode *avltree::ll(treenode *p)
{
    treenode *pl = p->lch;
    treenode *plr = pl->rch;
    pl->rch = p;
    p->lch = plr;
    p->height = heightt(p);
    pl->height = heightt(pl);
    if (p == root)
        root = pl;
    return pl;
}
treenode *avltree::rr(treenode *p)
{
    treenode *pr = p->rch;
    treenode *prl = pr->lch;
    pr->lch = p;
    p->rch = prl;
    p->height = heightt(p);
    pr->height = heightt(pr);
    if (p == root)
        root = pr;
    return pr;
}
treenode *avltree::lr(treenode *p)
{
    treenode *pl = p->lch;
    treenode *x = rr(pl);
    p->lch = x;
    treenode *y = ll(p);
    return y;
}
treenode *avltree::rl(treenode *p)
{
    treenode *pr = p->rch;
    treenode *x = ll(pr);
    p->rch = x;
    treenode *y = rr(p);
    return y;
}
void avltree::treecreate(int dt, treenode *p, treenode *q)
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
        root->height = 1;
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
            lchild->height = 1;
            return;
        }
        else if (q->data < dt)
        {
            treenode *rchild = new treenode;
            rchild->data = dt;
            rchild->lch = rchild->rch = NULL;
            q->rch = rchild;
            rchild->height = 1;
            return;
        }
    }
    p->height = heightt(p);
    if (balancefactor(p) == 2 && balancefactor(p->lch) == 1)
    {
        treenode *lll = ll(p);
        if (q != NULL)
        {
            if (q->data > lll->data)
                q->lch = lll;
            else if (q->data < lll->data)
                q->rch = lll;
        }
    }
    if (balancefactor(p) == -2 && balancefactor(p->rch) == -1)
    {
        treenode *rrr = rr(p);
        if (q != NULL)
        {
            if (q->data > rrr->data)
                q->lch = rrr;
            else if (q->data < rrr->data)
                q->rch = rrr;
        }
    }
    if (balancefactor(p) == 2 && balancefactor(p->lch) == -1)
    {
        treenode *lrr = lr(p);
        if (q != NULL)
        {
            if (q->data > lrr->data)
                q->lch = lrr;
            else if (q->data < lrr->data)
                q->rch = lrr;
        }
    }
    if (balancefactor(p) == -2 && balancefactor(p->rch) == 1)
    {
        treenode *rlr = rl(p);
        if (q != NULL)
        {
            if (q->data > rlr->data)
                q->lch = rlr;
            else if (q->data < rlr->data)
                q->rch = rlr;
        }
    }
}
void avltree::display(treenode *temp)
{
    if (temp != NULL)
    {
        display(temp->lch);
        cout << temp->data << " ";
        display(temp->rch);
    }
}
void avltree::del(int elemt, treenode *p, treenode *q)
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
        return;
    }
    p->height = heightt(p);
    if (balancefactor(p) == 2 && balancefactor(p->lch) == 1)
    {
        treenode *lll = ll(p);
        if (q != NULL)
        {
            if (q->data > lll->data)
                q->lch = lll;
            else if (q->data < lll->data)
                q->rch = lll;
        }
    }
    else if (balancefactor(p) == -2 && balancefactor(p->rch) == -1)
    {
        treenode *rrr = rr(p);
        if (q != NULL)
        {
            if (q->data > rrr->data)
                q->lch = rrr;
            else if (q->data < rrr->data)
                q->rch = rrr;
        }
    }
    else if (balancefactor(p) == 2 && balancefactor(p->lch) == -1)
    {
        treenode *lrr = lr(p);
        if (q != NULL)
        {
            if (q->data > lrr->data)
                q->lch = lrr;
            else if (q->data < lrr->data)
                q->rch = lrr;
        }
    }
    else if (balancefactor(p) == -2 && balancefactor(p->rch) == 1)
    {
        treenode *rlr = rl(p);
        if (q != NULL)
        {
            if (q->data > rlr->data)
                q->lch = rlr;
            else if (q->data < rlr->data)
                q->rch = rlr;
        }
    }
    else if (balancefactor(p) == 2 && balancefactor(p->lch) == 0) //llrotation
    {
        treenode *lll = ll(p);
        if (q != NULL)
        {
            if (q->data > lll->data)
                q->lch = lll;
            else if (q->data < lll->data)
                q->rch = lll;
        }
    }
    else if (balancefactor(p) == -2 && balancefactor(p->rch) == 0) //rrotation
    {
        treenode *rrr = rr(p);
        if (q != NULL)
        {
            if (q->data > rrr->data)
                q->lch = rrr;
            else if (q->data < rrr->data)
                q->rch = rrr;
        }
    }
}
int main()
{
    int dt, no;
    avltree tr1;
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
    cout << endl;
    tr1.del(40, tr1.root, NULL);
    // cout<<endl;
    // cout<<tr1.root->lch->lch->lch->data<<" ";
    cout << tr1.root->lch->lch->data << " ";
    // cout<<tr1.root->lch->lch->rch->data<<" ";
    cout << tr1.root->lch->data << " ";
    cout << tr1.root->lch->rch->lch->data << " ";
    cout << tr1.root->lch->rch->data << " ";
    cout << tr1.root->data << " ";
    cout << tr1.root->rch->data << " ";
    cout << tr1.root->rch->rch->data;

    cout << endl;
    tr1.display(tr1.root);
}