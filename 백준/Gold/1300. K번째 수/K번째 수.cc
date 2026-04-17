#include <stdio.h>
#include <algorithm>

int n, k;

int binary_search(int left, int right)
{
    if(left > right) return left;

    int mid = (left + right) / 2;
    int cnt = 0;

    for(int i = 1; i <= n; i++) cnt += n > mid / i ? mid / i : n;

    if(cnt < k) return binary_search(mid + 1, right);
    else return binary_search(left, mid - 1);
}

int main()
{
    scanf("%d %d", &n, &k);

    printf("%d", binary_search(1, k));

    return 0;
}
