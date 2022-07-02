#include<iostream>
using namespace std;
typedef long long ll;

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	ll value = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	if (value > 0)return 1;
	if (value == 0)return 0;
	return -1;
}

bool cross(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy)
{
	if ((ax == cx && ay == cy) || (ax == dx && ay == dy) || (bx == cx && by == cy) || (bx == dx && by == dy)) return true;
	else if ((by - ay) * (cx - ax) == (cy - ay) * (bx - ax) && (by - ay) * (dx - ax) == (dy - ay) * (bx - ax)) {
		if (ax != bx) return ((ax - cx) * (cx - bx) >= 0) || ((ax - dx) * (dx - bx) >= 0) || ((cx - ax) * (ax - dx) >= 0) || ((cx - bx) * (bx - dx) >= 0);
		else return ((ay - cy) * (cy - by) >= 0) || ((ay - dy) * (dy - by) >= 0) || ((cy - ay) * (ay - dy) >= 0) || ((cy - by) * (by - dy) >= 0);
	}
	else return (ccw(ax, ay, bx, by, cx, cy) * ccw(ax, ay, bx, by, dx, dy) <= 0 && ccw(cx, cy, dx, dy, ax, ay) * ccw(cx, cy, dx, dy, bx, by) <= 0);
}

struct point
{
	ll sx, sy, ex, ey, w;
}a[2510];

ll n, i, j, res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i].sx >> a[i].sy >> a[i].ex >> a[i].ey >> a[i].w;
		res += a[i].w;
	}
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (cross(a[i].sx, a[i].sy, a[i].ex, a[i].ey, a[j].sx, a[j].sy, a[j].ex, a[j].ey)) {
				res += (a[i].w > a[j].w ? a[j].w : a[i].w);
			}
		}
	}
	cout << res;
	return 0;
}