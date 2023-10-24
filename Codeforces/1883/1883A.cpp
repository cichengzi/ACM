#include<bits/stdc++.h>
using namespace std;

char s[5];

void solve() {
    scanf("%s", s);
    int ans = 0, pre = 1;
    for (int i = 0; i < 4; i++) {
        if (s[i] == '0') {
            ans += (10 - pre);
            pre = 10;
        } else {
            ans += abs(s[i] - '0' - pre);
            pre = s[i] - '0';
            if (pre == 0)
                pre = 10;
        }
        ans++;
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