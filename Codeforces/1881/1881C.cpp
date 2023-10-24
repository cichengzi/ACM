#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 7;

char s[MAXN][MAXN];
bool v[MAXN][MAXN];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < n; j++)
            v[i][j] = false;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j]) continue;

            set<pair<int, int>> pos;
            int x1 = i, y1 = j;
            int x2 = y1, y2 = n - 1 - x1;
            int x3 = y2, y3 = n - 1 - x2;
            int x4 = y3, y4 = n - 1 - x3;
            v[x1][y1] = v[x2][y2] = v[x3][y3] = v[x4][y4] = true;
            int max_val = max((int)s[x1][y1], (int)s[x2][y2]);
            max_val = max((int)s[x3][y3], max_val);
            max_val = max((int)s[x4][y4], max_val);

            pos.insert({x1, y1});
            pos.insert({x2, y2});
            pos.insert({x3, y3});
            pos.insert({x4, y4});

           // printf("max_val: {%c}\n", max_val);
            for (pair<int, int> p: pos) {
                ans += max_val - s[p.first][p.second];
               // printf("{%d, %d} {%c}\n", p.first, p.second, s[p.first][p.second]);
            }

           // printf("==============================\n");
        }
    }

    printf("%d\n", ans);

    //printf("+++++++++++++++++++++\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}