#include <stdio.h>
#include <algorithm>
int n, m, r = 1e9, a[100001];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1, j = 0; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
		for (; a[i] - a[j] >= m; j++) r = std::min(r, i - j);
	}
	printf("%d", r == 1e9 ? 0 : r);
	return 0;
}