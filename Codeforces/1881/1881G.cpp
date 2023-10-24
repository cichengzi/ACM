#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
typedef long long ll;
int c[MAXN];
char s[MAXN];

int lowbit(int x) {
    return x & (-x);
}

void add(int pos, int n, int val) {
    for (int i = pos; i <= n; i += lowbit(i)) {
        c[i] = (c[i] + val + 26) % 26;
    }
}

int ask(int pos) {
    int ans = 0;
    for (int i = pos; i >= 1; i -= lowbit(i)) {
        ans = (ans + c[i] + 26) % 26;
    }
    return ans;
}

void solve() {
    int n, m, opt, l, r, x;
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    set<int> s1, s2;

    for (int i = 1; i <= n; i++) c[i] = 0;

    for (int i = 1; i <= n; i++) {
        add(i, n, s[i] - 'a');
        add(i + 1, n, 26 - (s[i] - 'a'));
        if (i + 1 <= n && s[i] == s[i + 1]) {
            s1.insert(i);
        }
        if (i + 2 <= n && s[i] == s[i + 2]) {
            s2.insert(i);
        }
    }

    while (m--) {
        scanf("%d", &opt);
        if (opt == 1) {
            scanf("%d%d%d", &l, &r, &x);

            if (l - 1 >= 1 && ask(l - 1) == ask(l)) s1.erase(l - 1);
            if (l - 1 >= 1 && l + 1 <= n && ask(l - 1) == ask(l + 1)) s2.erase(l - 1);
            if (l + 2 <= n && ask(l + 2) == ask(l)) s2.erase(l);
            if (l - 2 >= 1 && ask(l - 2) == ask(l)) s2.erase(l - 2);


            if (r + 1 <= n && ask(r) == ask(r + 1)) s1.erase(r);
            if (r + 1 <= n && r - 1 >= 1 && ask(r + 1) == ask(r - 1)) s2.erase(r - 1);
            if (r + 2 <= n && ask(r) == ask(r + 2)) s2.erase(r);

            add(l, n, x);
            add(r + 1, n, -x);

            if (l - 1 >= 1 && ask(l - 1) == ask(l)) s1.insert(l - 1);
            if (l - 1 >= 1 && l + 1 <= n && ask(l - 1) == ask(l + 1)) s2.insert(l - 1);
            if (l + 2 <= n && ask(l + 2) == ask(l)) s2.insert(l);
            if (l - 2 >= 1 && ask(l - 2) == ask(l)) s2.insert(l - 2);

            if (r + 1 <= n && ask(r) == ask(r + 1)) s1.insert(r);
            if (r + 1 <= n && r - 1 >= 1 && ask(r + 1) == ask(r - 1)) s2.insert(r - 1);
            if (r + 2 <= n && ask(r) == ask(r + 2)) s2.insert(r);

        }
        else {
            scanf("%d%d", &l, &r);
            auto iter1 = s1.lower_bound(l);

            bool flag = false;
            if (iter1 != s1.end() && *iter1 < r) {
                flag = true;
            }

            auto iter2 = s2.lower_bound(l);
            if (iter2 != s2.end() && *iter2 < r - 1) {
                flag = true;
            }

            if (!flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}