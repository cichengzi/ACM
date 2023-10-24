#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
const int INF = 0x3f3f3f3f;
vector<int> g[MAXN];
bool marked[MAXN];
int dp[MAXN];

void dfs(int u, int dist) {
    if (dp[u] < dist)
        return;
    dp[u] = dist;

    for (int v: g[u]) {
        dfs(v, dist + 1);
    }
}

void solve() {
    int n, k, u, v;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        marked[i] = false;
        dp[i] = INF;
        g[i].clear();
    }

    for (int i = 0; i < k; i++) {
        scanf("%d", &u);
        marked[u] = true;
    }

    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dp[1] = 0;
    dfs(1, 0);

    dp[0] = 0;
    int source = 0;
    for (int i = 1; i <= n; i++) {
        if (marked[i] && dp[i] >= dp[source])
            source = i;
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = INF;
    }

    dp[source] = 0;
    dfs(source, 0);

    int max_dist = 0;
    for (int i = 1; i <= n; i++) {
        if (marked[i] && dp[i] > max_dist) {
            max_dist = dp[i];
        }
    }

    printf("%d\n", (max_dist + 1) / 2);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}