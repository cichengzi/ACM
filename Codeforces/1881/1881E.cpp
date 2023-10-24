#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
const int INF = 0x3f3f3f3f;
int a[MAXN], dp[MAXN];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        dp[i] = INF;
    }

    dp[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        dp[i] = min(dp[i], dp[i + 1] + 1);
        if (i + a[i] <= n) {
            dp[i] = min(dp[i], dp[a[i] + i + 1]);
        }
    }

    printf("%d\n", dp[1]);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}