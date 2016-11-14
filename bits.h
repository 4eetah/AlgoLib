#include <iostream>
using namespace std;

template <typename T>
void bprint(T n)
{
    int len = 8 * sizeof(T);
    for (int i = len-1; i >= 0; --i)
        cout << (bool)(n & (1 << i));
    cout << endl;
}

template <typename T>
T breverse(T n)
{
    int len = 8 * sizeof(T);
    T res = 0;
    for (int i = len-1, j = 0; i >= (len / 2); --i, ++j)
        res |= (((1 << i) & n) >> (i - j)) | (((1 << j) & n) << (i - j));
    return res;
}
