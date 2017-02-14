#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 110;

char A[maxn], B[maxn], C[maxn];
int n, m, where[maxn];
vector<int> x[27];

int check()
{
    for (int i = 0; i < 26; i++)
        x[i].clear();
    for (int i = n; i; i--)
    {
        x[C[i]-'a'].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int k1 = A[i]-'a';
        if (x[k1].size() == 0)
            return 1e9;
        where[i] = x[k1][x[k1].size() - 1];
        x[k1].pop_back();
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (where[i] > where[j])
                ans++;
        }
    }
    return ans;
}

int main()
{
    scanf("%s", A+1);
    scanf("%s", B+1);
    int ans = 1e9;
    n = strlen(A+1);
    m = strlen(B+1);
    if (n == m)
    {
        memcpy(C, B, sizeof(B));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 'a'; j <= 'z'; j++)
            {
               C[i] = j;
               ans = min(ans, check());
            }
            C[i] = B[i];
        }
    }
    else if (n == m + 1)
    {
        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                C[j] = B[j];
            }
            for (int j = i+1; j<=m; j++)
            {
                C[j+1] = B[j];
            }
            for (int j = 'a'; j <= 'z'; j++)
            {
                C[i+1] = j;
                ans = min(ans, check());
            }
        }
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j < i; j++)
            {
                C[j] = B[j];
            }
            for (int j = i+1; j <= m; j++)
            {
                C[j-1] = B[j];
            }
            ans = min(ans, check());
        }
    }
    printf("%d\n", ans);
}
