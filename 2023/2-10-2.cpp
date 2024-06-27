#include <bits/stdc++.h>

int n;
std::priority_queue<int> q1, q2;

int main ()
{
    scanf("%d", &n);
    int x;
    // 第一个数特殊处理
    scanf("%d", &x);
    q1.push(x);
    printf("%d\n", x);
    // 2~n
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &x);
        if (x <= q1.top())
            q1.push(x);
        else
            // 往堆中插入相反数可以实现小根堆
            // 你也可以使用 <int, vector<int>, greater<int> > 类型，但效率较低
            q2.push(-x);
        // 保持两个堆大小的平衡
        while (q1.size() > (i + 1) / 2)
        {
            q2.push(-q1.top());
            q1.pop();
        }
        while (q2.size() > i / 2)
        {
            q1.push(-q2.top());
            q2.pop();
        }
        if (i & 1)
            printf("%d\n", q1.top());
        else
            printf("%d\n", (q1.top() - q2.top()) / 2);
    }
    return 0;
}