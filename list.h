#include <utility>
#include <limit.h>
#include <set>

template <typename T>
struct lnode {
    T val;
    lnode * next;
    lnode(T v) : val(v), next(NULL) {};
};

template <typename T>
lnode * remove_val(lnode *head, T val)
{
    lnode **pptr;
    for (pptr = &head; *pptr; pptr = &(*pptr)->next)
        if ((*pptr)->val == val) {
            *pptr = (*pptr)->next;
            break;
        }
    return *pptr;
}

/* Remove Nth */
lnode * remove_nth(lnode *head, int n)
{
    lnode **pptr;
    int cnt;
    for (pptr = &head, cnt = 1; *pptr; pptr = &(*pptr)->next, ++n)
        if (cnt == n) {
            *pptr = (*pptr)->next;
            break;
        }
    return *pptr;
}

/* Removes Nth node starting from the end of list */
lnode * remove_nth_end(lnode *head, int n)
{
    lnode *fast;
    lnode **slow = &head;
    int i;
    for (i = 1, fast = head; i < n && fast->next; ++i)
        fast = fast->next;
    while (fast->next) {
        fast = fast->next;
        slow = &(*slow)->next;
    }
    lnode *t = *slow;
    *slow = (*slow)->next;
    delete t;
    return head;
}

/* recursive version of the above */
lnode * rremove_nth_end(lnode *head, int n)
{
    int cnt = 0;
    return godeeper(head, n, cnt);
}
static lnode * godeeper(lnode *head, int n, int *cnt)
{
    if (!head) {
        *cnt = 1;
        return NULL;
    }
    head = godeeper(head->next, n, cnt);
    if (*cnt == n) {
        *cnt = INT_MIN;
        lnode *t = head->next;
        delete head;
        return t;
    }
    *cnt = *cnt + 1;
    return head;
}
/***/

/* Determine if linked list is a palindrome, yeah, it's quite useful */
bool is_palindrome(lnode *head)
{
    lnode *mid, *left, *right;
    mid = middle_pre(head);
    mid = reverse(mid);
    left = head;
    right = mid->next; 
    while (left && right) {
        if (left->val != right->val)
            return false;
        left = left->next;
        right = right->next;
    }
    return true;
}

/* recursive version of the above */
bool ris_palindrome(lnode *head)
{
    lnode *pstart = head, *pend;
    lnode **ppstart = &pstart, **ppend = &pend;
    return ris_palindrome_helper(ppstart, ppend, end);
}
bool ris_palindrome_helper(lnode **ppstart, lnode **ppend, lnode *pend)
{
    if (!pend)
        return true;
    bool ret = ris_palindrome_helper(ppstart, ppend, pend->next);
    if (*ppstart == *ppend)
        return true;
    if (ret && (*ppstart)->val == pend->val) {
        *ppstart = (*ppstart)->val;
        *ppend = pend;
        return true;
    }
    return false;
}
/***/

/* Reverse */
lnode *reverse(lnode *head)
{
    lnode *prev, *next;
    prev = next = NULL;
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

/* Find middle, post [1]->[2]->[3]->[4]
 *                             ^^^      */
lnode *middle_post(lnode *head)
{
    if (!head) return head;
    lnode *slow, *fast;
    slow = fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
/* Find middle, pre [1]->[2]->[3]->[4]
 *                       ^^^            */
lnode *middle_pre(lnode *head)
{
    if (!head) return head;
    lnode *slow, *fast;
    slow = fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/* Find the intersection node of two lists ([3] in the following ex.):
 *      [1]->[2]-\
 *               [3]->[7]->[8]->NULL 
 * [4]->[5]->[6]-/
 * The idea is to swap pointers once each of them reaches the end,
 * so that eventually they lined up
 */
lnode *intersection(lnode* heada, lnode *headb)
{
    lnode *pa = heada, *pb = headb;
    while (pa && pb && pa != pb) {
        pa = pa->next;
        pb = pb->next;
        /* either collided or both reached end of lists(pa == pb == NULL) */
        if (pa == pb) return pa;
        
        if (!pa) pa = headb;
        if (!pb) pb = heada;
    }
    return pa;
}
/* same, but solved by means of using set */
lnode *intersection_set(lnode *heada, lnode *headb)
{
    set<lnode*> s;
    while (heada || headb) {
        if (heada) {
            if (!s.insert(heada).second)
                return heada;
            heada = heada->next;
        }
        if (headb) {
            if (!s.insert(headb).second)
                return headb;
            headb = headb->next;
        }
    }
    return NULL;
}
/***/
