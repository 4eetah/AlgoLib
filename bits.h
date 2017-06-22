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
    for (int i = 0; i < len; ++i) {
        res = (res << 1) ^ (n & 1);
        n = n >> 1;
    }
    return res;
}

uint32_t merge_reverse32(uint32_t n)
{
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}
