#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <functional>
#include <iostream>
#include <tuple>
#include <string>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ll, ll, ll, ll> tl4;
typedef stack<ll> sl;
typedef queue<ll> ql;
typedef priority_queue<ll> pql;
int d[10010][10010];
set<int> s;
int n, m;
int go(int l, int r) {
    if (l >= r) return 0;
    int&ret = d[l][r];
    if (ret != -1) return ret;
    ret = 1e9;
    bool ok = true;
    for (int i = l; i <= r; i++) {
        if (s.count(i)) {
            ok = false;
            int temp = (r-l) + go(l, i - 1) + go(i + 1, r);
            ret = min(ret, temp);
        }
    }
    if (ok) ret = 0;
    return ret;
}
int main() {
    memset(d, -1, sizeof(d));
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x; scanf(" %d", &x); s.insert(x);
    }
    printf("%d\n", go(1, n));
}
