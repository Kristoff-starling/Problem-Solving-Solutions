#include <bits/stdc++.h>

const int MOD = 998244353;

int add(int x) { if (x >= MOD) x -= MOD; return x; }
void Add(int &x, int y) { x = add(x + y); }

// https://kristoff-starling.github.io/courses/problemsolving/coding/matmul/
class Matrix
{
private:
    int b[5][5], N;
public:
    Matrix ()
    {
        N = 2;
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
        if (y & 1) res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}

int main ()
{
    int n;
    scanf("%d", &n);
    Matrix trans = Matrix();
    trans[1][1] = 0; trans[1][2] = 1; trans[2][1] = 1; trans[2][2] = 1;
    trans = quick_pow(trans, n);
    printf("%d\n", trans[1][2]);
    return 0;
}