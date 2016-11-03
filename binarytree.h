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
template <typename T>
static void levels_helper(btnode *root, vector<vector<T>>& res, int lvl)
{
    if (!root) return;
    if (res.size() == lvl) res.push_back({root->val});
    else res[lvl].push_back(root->val);
    levels_helper(root->left, res, lvl + 1);
    levels_helper(root->right, res, lvl + 1);
}

template <typename T>
vector<vector<T>> levels(btnode *root)
{
    vector<vector<T>> res;
    if (!root) return res;
    levels_helper(root, res, 0);
    return res;
}
/***/

/* return container of tree's paths */
template <typename T>
static void paths_helper(btnode *root, vector<vector<T>>& res, vector<T>& cur)
{
    cur.push_back(root->val);
    if (!(root->left || root->right)) {
        res.push_back(cur);
        cur.pop();
        return;
    }
    if (root->left) paths_helper(root->left, res, cur);
    if (root->ritght) paths_helper(root->right, res, cur);
    cur.pop();
}

template <typename T>
vector<vector<T>> paths(btnode *root)
{
    vector<vector<T>> res;
    if (!root) return res;
    paths_helper(root, res, cur);
    return res;
}
/***/

/* determine if the tree has a root-to-leaf path with specified sum */
template <typename T>
static bool godeeper(btnode *root, T sum, T cur)
{
    if (!root) return false;
    if (!(root->left || root->right))
        return (cur + root->val) == sum;
    return godeeper(root->left, sum, cur + root->val) ||
           godeeper(root->right, sum, cur + root->val);
}

bool haspathsum(btnode *root, T sum)
{
    return godeeper(root, sum, 0);
}
/***/
