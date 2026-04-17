#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

priority_queue<int> pq;

int main() {
	int n, t, p, tt, c = 0, miv = 0, cc = 0;
	scanf("%d %d %d", &n, &t, &p);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tt);
		sum += tt;
		c++;
		pq.push(tt);

		while (sum > t - (ll)p * i && c) {
			if (t - (ll)p * i < 0) { sum = c = 0; break; }
			c--;
			sum -= pq.top();
			pq.pop();
		}

		miv = max(miv, c);
	}

	printf("%d", miv);
}
