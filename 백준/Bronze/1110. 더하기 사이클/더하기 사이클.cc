#include <stdio.h>
int main() {
	int n, m, c = 0;
	scanf("%d", &n); m = n;
	do { c++, m = (m % 10) * 10 + (m / 10 + m % 10) % 10; } while (n != m);
	printf("%d", c);
	return 0;
}