#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 7;
int a[MAXN];
pair<double, int> p[MAXN];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    ll ans = 0;
    a[0] = 1;

    for (int i = 0; i <= n; i++) {
        double base = log2(a[i]);
        p[i] = {1.0 * a[i] / pow(2, (int) base), (int) base};
    }

    for (int i = 1; i <= n; i++) {
        double k = log2(p[i - 1].first / p[i].first) + p[i - 1].second - p[i].second;
        if (fabs(k - (int)k) > 1e-12) {
            k = k + 1;
        }
        if (k < 0) {
            k = 0;
        }
        p[i] = {p[i].first, p[i].second + (int)k};
        ans += (ll)k;
    }

    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}