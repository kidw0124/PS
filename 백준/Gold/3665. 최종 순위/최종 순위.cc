#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int t, n, m, a[501][501], in[501], x, y, b[500], r[500];
int main() {
    scanf("%d", &t);
    while (t--) {
        int f = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(in, 0, sizeof(in));
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                a[b[j]][b[i]] = 1;
                in[b[i]]++;
            }
        }
        scanf("%d", &m);
        while (m--) {
            scanf("%d%d", &x, &y);
            if (a[x][y]) {
                in[y]--;
                in[x]++;
            }
            else {
                in[y]++;
                in[x]--;
            }
            swap(a[x][y], a[y][x]);
        }
        queue<int> qu;
        for (int i = 1; i <= n; i++) {
            if (!in[i])
                qu.push(i);
        }
        for (int i = 0; i < n; i++) {
            if (qu.empty()) {
                f = 1;
                break;
            }
            else if (qu.size() > 1) {
                f = 2;
                break;
            }
            int here = qu.front();
            r[i] = here;
            qu.pop();
            for (int j = 1; j <= n; j++) {
                if (a[here][j]) {
                    in[j]--;
                    if (!in[j])
                        qu.push(j);
                }
            }
        }
        if (f == 1)
            printf("IMPOSSIBLE\n");
        else if (f == 2)
            printf("?\n");
        else {
            for (int i = 0; i < n; i++)
                printf("%d ", r[i]);
            printf("\n");
        }
    }
    return 0;
}
