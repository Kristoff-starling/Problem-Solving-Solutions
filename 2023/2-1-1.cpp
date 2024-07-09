#include <bits/stdc++.h>

const int MAXN = 2e5 + 10;

int n;
int a[MAXN], b[MAXN];

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
            b[pt++] = a[pt1++];
        else
            b[pt++] = a[pt2++];
    }
    while (pt1 <= mid)
        b[pt++] = a[pt1++];
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
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    puts("");
    return 0;
}