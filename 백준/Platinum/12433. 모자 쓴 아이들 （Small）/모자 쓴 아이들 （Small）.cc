#include <stdio.h>
#include <string.h>
#include <assert.h>
 
int dp[2001][2001];
 
void foo()
{
        for (int i = 0; i <= 2000; ++i) {
                for (int j = 0; j <= i; ++j) {
                        if (j > i / 2) {
                                dp[i][j] = dp[i][i - j];
                        } else if (j == 0) {
                                dp[i][j] = 1;
                        } else {
                                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                                if (dp[i][j] >= 32749)
                                        dp[i][j] -= 32749;
                        }
                }
        }
}
 
int bar(int i, int j)
{
        if (i < 0 || i > 2000) {
                fprintf(stderr, "ERR_bar: %d\n", i);
        }
        if (j >= 0 && j <= i)
                return dp[i][j];
        return 0;
}
 
int main(void)
{
        foo();
        int T_;
        scanf("%d", &T_);
        for (int i_ = 1; i_ <= T_; ++i_) {
                int B, W, k, i;
                scanf("%d %d %d %d", &B, &W, &k, &i);
                assert(k <= B + W);
                if (i > k) {
                        fprintf(stderr, "ERR_INPUT: %d %d\n", i, k);
                }
                const int kk = (B + W) - k;
                int ans = bar(k - i, B - i + 1) // i는 흰색
                        + bar(k - i, W - i + 1); // i는 검은색
                if (ans > 32749)
                        ans -= 32749;
                if (ans) {
                        int mul = 0;
                        for (int m = i - 1 - kk; m <= i - 1; ++m) {
                                mul += bar(i - 1, m);
                        }
                        mul %= 32749;
                        for (int m = 1; m <= i - 1; ++m) {
                                int x = 0;
                                for (int p = 0; p <= kk; ++p) {
                                        x += bar(m - 1, p);
                                }
                                x %= 32749;
                                mul -= bar(i - m - 1, kk - m + 1) * x;
                                mul %= 32749;
                        }
                        //fprintf(stderr, "mul: %d\n", mul);
                        ans *= mul;
                        ans %= 32749;
                }
                printf("Case #%d: %d\n", i_, ans);
        }
        return 0;
}
