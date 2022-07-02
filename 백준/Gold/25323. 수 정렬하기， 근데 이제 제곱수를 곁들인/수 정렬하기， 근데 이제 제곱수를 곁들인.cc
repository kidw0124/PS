#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

ll n, i, a[500010], b[500010];
bool flag;

ll gcd(ll x, ll y)
{
	if (y == 0)return x;
	return gcd(y, x % y);
}

bool check(ll x, ll y)
{
	ll g = gcd(x, y);
	x /= g;
	y /= g;
	ll sqx = sqrt(x), sqy = sqrt(y);
	return (sqx * sqx == x && sqy * sqy == y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	flag = true;
	for (i = 0; i < n; i++) {
		if (!check(a[i], b[i])) {
			flag = false;
			break;
		}
	}
	if (flag)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}