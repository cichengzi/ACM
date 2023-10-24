#include<bits/stdc++.h>
using namespace std;

vector<int> left_bound, right_bound;

void solve() {
    char opt[2];
    int l, r, q;
    scanf("%d", &q);
    while (q--) {
        scanf("%s%d%d", opt, &l, &r);
        if (opt[0] == '+') {
            left_bound.insert(lower_bound(left_bound.begin(), left_bound.end(), l), l);
            right_bound.insert(lower_bound(right_bound.begin(), right_bound.end(), r), r);
        }
        else {
            left_bound.erase(lower_bound(left_bound.begin(), left_bound.end(), l));
            right_bound.erase(lower_bound(right_bound.begin(), right_bound.end(), r));
        }
        if (left_bound.size() > 0 && right_bound.size() > 0 && left_bound.back() > right_bound.front()) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
}

int main() {
    solve();
    return 0;
}