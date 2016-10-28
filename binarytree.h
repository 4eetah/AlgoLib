#include <stack>
#include <queue>

template <typename T>
struct btnode {
    T val;
    btnode *left, *right;
    btnode(T v) : val(v), left(NULL), right(NULL) {}
};

/* recursive traversals */
void ltraverse(btnode *node, void (*visit)(btnode*))
{
    if (!node) return;
    (*visit)(node);
    ltraverse(node->left, visit);
    ltraverse(node->right, visit);
}

void ctraverse(btnode *node, void (*visit)(btnode*))
{
    if (!node) return;
    ctraverse(node->left, visit);
    (*visit)(node);
    ctraverse(node->right, visit);
}

void rtraverse(btnode *node, void (*visit)(btnode*))
{
    if (!node) return;
    rtraverse(node->left, visit);
    rtraverse(node->right, visit);
    (*visit)(node);
}

/* iterative traversals */
void litraverse(btnode *root, void (*visit)(btnode*))
{
    stack<node*> s; s.push(root);
    btnode *n;
    while (!s.empty()) {
        (*visit)(n = s.top()); n.pop();
        if (n->right) s.push(n->right);
        if (n->left) s.push(n->left);
    }
}

void citraverse(btnode *root, void (*visit)(btnode*))
{
    stack<node*> s; s.push(root);
    btnode *n;
    while (!s.empty()) {
        if (n->right) s.push(n->right);
        (*visit)(n = s.top()); n.pop();
        if (n->left) s.push(n->left);
    }
}

void ritraverse(btnode *root, void (*visit)(btnode*))
{
    stack<node*> s; s.push(root);
    btnode *n;
    while (!s.empty()) {
        if (n->right) s.push(n->right);
        if (n->left) s.push(n->left);
        (*visit)(n = s.top()); n.pop();
    }
}

void btraverse(btnode *root, void (*visit)(btnode*))
{
    queue<node*> q; q.push(root);
    btnode *n;
    while (!q.empty()) {
        (*visit)(n = q.front()); q.pop();
        if (n->right) q.push(n->right);
        if (n->left) q.push(n->left);
    }
}
