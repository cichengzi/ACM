#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    int l = lcm(n, m);
    string x, s;
    cin >> x;
    cin >> s;
    int ans = 0;
    while (n <= l && x.find(s) == -1) {
        x += x;
        ans++;
        n *= 2;
    }
    if (x.find(s) != -1)
        printf("%d\n", ans);
    else
        printf("-1\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}