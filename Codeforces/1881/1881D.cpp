#include<bits/stdc++.h>
using namespace std;
const int MAXP = 1e6 + 7;
const int MAXN = 1e4 + 7;
bool prime[MAXP];
int p[MAXP];
int num_primes = 0;

int a[MAXN];
int c[MAXP];

void init_prime() {
    memset(prime, true, sizeof(prime));
    p[0] = p[1] = false;
    for (int i = 2; i < MAXP; i++) {
        if (!prime[i])
            continue;
        p[num_primes++] = i;
        for (int j = 2 * i; j < MAXP; j += i) {
            prime[j] = false;
        }
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    set<int> prime_set;
    for (int i = 0; i < n; i++) {
        for (int j = 0; p[j] <= a[i]; j++) {
            while (a[i] % p[j] == 0) {
                c[p[j]]++;
                a[i] /= p[j];
                prime_set.insert(p[j]);
            }
        }
    }

    bool flag = true;
    for (int p_val: prime_set) {
        //printf("%d\n", p_val);
        if (c[p_val] % n != 0) {
            flag = false;
        }
        c[p_val] = 0;
    }

    if (flag) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }

    //printf("====================\n");
}

int main() {
    init_prime();

    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}