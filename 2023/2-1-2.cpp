#include <bits/stdc++.h>

const int MAXN = 2e5 + 10;

int n;
int a[MAXN], b[MAXN];
long long ans = 0;

void merge_sort(int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int pt1 = l, pt2 = mid + 1, pt = l;
    while (pt1 <= mid && pt2 <= r)
    {
        if (a[pt1] < a[pt2])
        { 
            // 左边的元素进入序列，此时 b 中所有的右半边的数都可以和 a[pt1] 形成逆序对
            b[pt++] = a[pt1++];
            ans += pt2 - mid - 1;
        }
        else
        {
            // 右边的元素进入序列
            b[pt++] = a[pt2++];
        }
    }
    while (pt1 <= mid)
    {
        b[pt++] = a[pt1++];
        ans += pt2 - mid - 1;
    }
    while (pt2 <= r)
        b[pt++] = a[pt2++];
    for (int i = l; i <= r; i++)
        a[i] = b[i];
}

int main ()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i); 
    merge_sort(1, n);
    printf("%lld\n", ans);
    return 0;
}