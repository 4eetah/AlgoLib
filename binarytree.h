#include <stack>
#include <queue>
#include <vector>

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

/* miscellaneous procedures */
int count(btnode *root)
{
    if (!root) return 0;
    return count(root->left) + count(root->right) + 1;
}

int height(btnode *root)
{
    if (!root) return -1;
    int u = height(root->left);
    int v = height(root->right);
    return u > v ? u + 1 : v + 1;
}

/* return container of tree's levels */
static void levels_helper(btnode *root, vector<vector<int>>& res, int lvl)
{
    if (!root) return;
    if (res.size() == lvl) res.push_back({root->val});
    else res[lvl].push_back(root->val);
    dfs(root->left, res, lvl + 1);
    dfs(root->right, res, lvl + 1);
}

vector<vector<int>> levels(btnode *root)
{
    if (!root) return vector<vector<int>>();
    vector<vector<int>> res;
    dfs(root, res, 0);
    return res;
}
/***/
