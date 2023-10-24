#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    ll sum = a + b + (ll)c;
    for (int i = 3; i <= 6; i++) {
        int t = 0;
        int m = sum / i;
        if (sum % i != 0)
            continue;
        if (a % m != 0 || b % m != 0 || c % m != 0)
            continue;
        t += (a / m - 1) + (b / m - 1) + (c / m - 1);
        if (t <= 3) {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}