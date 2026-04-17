#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 10001
 
int N, M, K, L;
int D[MAXN];
bool V[MAXN];
 
struct Z{
    int x, y;
} A[MAXN], B[MAXN], P[MAXN], Q[MAXN];
 
int get_dist(Z a, Z b, Z c, Z d)
{
    if (a.x > b.x) swap(a, b);
    if (a.y > b.y) swap(a, b);
    if (c.x > d.x) swap(c, d);
    if (c.y > d.y) swap(c, d);
    if (c.x == d.x) swap(a, c), swap(b, d);
    int ret = 2e9;
    if (a.y == b.y){
        // c.y == d.y
        if (!(b.x < c.x || d.x < a.x)) ret = min(ret, abs(a.y-c.y));
    }
    else if (c.x == d.x){
        // a.x == a.x
        if (!(b.y < c.y || d.y < a.y)) ret = min(ret, abs(a.x-c.x));
    }else{
        // a.x == b.x
        // c.y == d.y
        if (c.x <= a.x && a.x <= d.x) ret = min({ret, abs(c.y-a.y), abs(c.y-b.y)});
        if (a.y <= c.y && c.y <= b.y) ret = min({ret, abs(a.x-c.x), abs(b.x-c.x)});
        if (c.x <= a.x && a.x <= d.x &&
            a.y <= c.y && c.y <= b.y) ret = 0;
    }
    if (ret < 2e9) ret = ret*ret;
    for (auto &i: {a, b}) for (auto &j: {c, d}){
        ret = min(ret, (i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y));
    }
    return ret;
}
 
int main()
{
    scanf("%*d%*d%d%d%d%d", &N, &M, &K, &L);
    for (int i=1;i<=N;i++) scanf("%d%d", &A[i].x, &A[i].y);
    for (int i=1;i<=M;i++) scanf("%d%d", &B[i].x, &B[i].y);
    for (int i=1;i<=K;i++) scanf("%d%d%d%d", &P[i].x, &P[i].y, &Q[i].x, &Q[i].y);
    for (int i=0;i<=K;i++) D[i] = 2e9;
    for (int i=1;i<=N;i++) for (int j=1;j<=K;j++){
        int v = get_dist(P[j], Q[j], A[i], A[i%N+1]);
        if (v <= L && D[j] > v) D[j] = v;
    }
     
    for (int i=1;i<=K;i++){
        int t = 0;
        for (int j=1;j<=K;j++) if (!V[j] && D[t] > D[j]) t = j;
        if (!t) break;
        V[t] = 1;
        for (int j=1;j<=K;j++) if (!V[j]){
            int v = get_dist(P[t], Q[t], P[j], Q[j]);
            if (v <= L && D[j] > D[t]+v) D[j] = D[t]+v;
        }
    }
    int ans = 2e9;
    for (int i=1;i<=N;i++) for (int j=1;j<=M;j++){
        int v = get_dist(A[i], A[i%N+1], B[j], B[j%M+1]);
        if (v <= L && ans > v) ans = v;
    }
    for (int i=1;i<=K;i++) if (D[i] < 2e9){
        for (int j=1;j<=M;j++){
            int v = get_dist(P[i], Q[i], B[j], B[j%M+1]);
            if (v <= L && ans > D[i]+v)
                ans = D[i]+v;
        }
    }
    printf("%d\n", ans < 2e9 ? ans : -1);
}
