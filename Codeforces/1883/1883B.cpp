#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
char s[MAXN];
int c[26];

void solve() {
    int n, k;
    for (int i = 0; i < 26; i++) {
        c[i] = 0;
    }
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        c[s[i] - 'a']++;
    }

    int num = 0;
    for (int i = 0; i < 26; i++) {
        num += (c[i] / 2 * 2);
    }
    if (n - k == 1) {
        printf("Yes\n");
    }
    else if (num >= n - k - 1) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}