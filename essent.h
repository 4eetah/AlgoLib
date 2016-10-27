#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Binary search */
template <typename T>
int binarySearch(const vector<T>& v, T key)
{
    int lo = 0;
    int hi = v.size() - 1;
    while (lo <= hi) {
        int mid = (hi + lo) / 2;
        if (key < v[mid]) hi = mid - 1;
        else if (key > v[mid]) lo = mid + 1;
        else return mid;
    }
    return -1;
}
/* Binary search */

/* Merge sort */
template <typename T>
void merge(vector<T>& v, vector<T>& aux, int lo, int mid, int hi)
{
    for (int i = lo; i <= hi; ++i)
        aux[i] = v[i];
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; ++k) {
        if      (i > mid) v[k] = aux[j++];
        else if (j > hi) v[k] = aux[i++];
        else if (aux[i] > aux[j]) v[k] = aux[j++];
        else v[k] = aux[i++];
    }
}

template <typename T>
void mergeSort(vector<T>& v, vector<T>& aux, int lo, int hi)
{
    if (hi <= lo) return;
    int mid = (lo + hi) / 2;
    mergeSort(v, aux, lo, mid);
    mergeSort(v, aux, mid + 1, hi);
    merge(v, aux, lo, mid, hi);
}

template <typename T>
void mergeSort(vector<T>& v)
{
    vector<T> aux(v.size());
    mergeSort(v, aux, 0, v.size()-1);
}
/* Merge sort */

/* Quick sort */
template <typename T>
int partition(vector<T>& v, int lo, int hi)
{
    int i = lo, j = hi + 1;
    T tmp, piv = v[lo];
    while (1) {
        while (piv > v[++i])
            if (i == hi) break;
        while (piv < v[--j])
            if (j == lo) break;
        if (i >= j) break;
        tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
    tmp = v[lo]; // piv
    v[lo] = v[j];
    v[j] = tmp;
    return j;
}

template <typename T>
void quickSort(vector<T>& v, int lo, int hi)
{
    if (hi <= lo) return;
    int j = partition(v, lo, hi);
    quickSort(v, lo, j);
    quickSort(v, j+1, hi);
}

template <typename T>
void quickSort(vector<T>& v)
{
    random_shuffle(v.begin(), v.end());
    quickSort(v, 0, v.size()-1);
}
/* Quick sort */

/* indexed "remove duplicates" from sorted array */
template <typename T>
int iunique(vector<T>& v)
{
    int i = !v.empty();
    for (T n : v)
        if (n != v[i-1]) v[i++] = n;
    return i;
}
