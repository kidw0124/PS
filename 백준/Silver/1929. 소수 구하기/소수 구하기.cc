#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int M, N;
    cin >> M >> N;
    vector<bool> isPrime(N + 1, true); // 소수 리스트
    bool chk = false;
 
    // 에라토스테네스의 체 이용하여 N까지의 소수 구하기
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            // 소수의 N배수들은 모두 소수가 아님
            for (int j = 2 * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
 
    for(int i = M; i <= N; i++)
        if(isPrime[i])
            cout << i << '\n';
 
    return 0;
}
