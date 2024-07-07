#include <bits/stdc++.h>

const int MOD = 998244353;

inline int add(int x) { if (x >= MOD) x -= MOD; return x; }
inline void Add(int &x, int y) { x = add(x + y); }

int n, m, X, Y, k, N;
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 }, dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// https://kristoff-starling.github.io/courses/problemsolving/coding/matmul/
class Matrix
{
private:
    int b[250][250];
public:
    Matrix ()
    {
        N = n * m;
        memset(b, 0, sizeof(b));
    }
    void init_I()
    {
        for (int i = 1; i <= N; i++)
            b[i][i] = 1;
    }
    int* operator [] (int r)
    {
        return b[r];
    }
    Matrix operator * (Matrix other)
    {
        Matrix res;
        for (int i = 1; i <= N; i++)
            for (int k = 1; k <= N; k++)
                for (int j = 1; j <= N; j++)
                    Add(res.b[i][j], 1ll * b[i][k] * other.b[k][j] % MOD);
        return res; 
    }
};

Matrix quick_pow(Matrix x, int y)
{
    Matrix res;
    res.init_I();
    while (y)
    {
        if (y & 1)
            res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}

Matrix trans = Matrix();
inline int to_id(int x, int y) { return (x - 1) * m + y; }

int main ()
{
    scanf("%d%d%d%d%d", &n, &m, &X, &Y, &k);
    N = n * m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int dir = 0; dir < 8; dir++)
            {
                int xx = i + dx[dir], yy = j + dy[dir];
                if (1 <= xx && xx <= n && 1 <= yy && yy <= m)
                    trans[to_id(i, j)][to_id(xx, yy)] = 1;
            }
    trans = quick_pow(trans, k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%d ", trans[to_id(i, j)][to_id(X, Y)]);
        puts("");
    }
    return 0;
}