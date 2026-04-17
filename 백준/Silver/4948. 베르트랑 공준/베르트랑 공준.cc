#include <cstdio>
#include <algorithm>
using namespace std;
bool p[270000];
int s[270000];
int n;
int main() {
    p[0] = p[1] = true;
    for (int i = 2; i <= 270000; i++) {
        if (p[i])continue;
        for (int j = i + i; j <= 270000; j += i) {
            p[j] = true;
        }
    }
    for (int i = 2; i <= 270000; i++) {
        if (!p[i])s[i]++;
        s[i] += s[i - 1];
    }
    scanf("%d", &n);
    while (n) {
        printf("%d\n", s[2 * n] - s[n]);
        scanf("%d", &n);
    }
    return 0;
}