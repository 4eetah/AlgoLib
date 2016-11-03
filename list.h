#include <utility>
#include <limit.h>

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
    lnode *start, *fast;
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
