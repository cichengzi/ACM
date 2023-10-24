#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int a[MAXN];

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = k;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, (k - a[i] % k) % k);
    }
    if (k == 4) {
        int num_two = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] % 2 == 0) {
                num_two++;
            }
        }
        num_two = min(num_two, 2);
        ans = min(ans, 2 - num_two);
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}