#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using lint = long long;
struct P {
	lint x, y;
	P() {}
	P(lint x, lint y) : x(x), y(y) {}
	bool operator < (const P&rhs) const {
		if (x != rhs.x) return x < rhs.x;
		return y < rhs.y;
	}
	P operator -(const P&rhs) const {
		return { x - rhs.x, y - rhs.y };
	}
	lint cross(const P&rhs) const {
		return x * rhs.y - y * rhs.x;
	}
};
using pp = pair<P, P>;

vector<P> arr, brr, black, white;
vector<pp> bseg, wseg;
int tc, N, M;
lint mx;

void init() {
	arr.clear(); brr.clear();
	black.clear(); white.clear();
	bseg.clear(); wseg.clear();
}

inline lint dist(P a, P b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

lint ccw(P&a, P&b, P&c) {
	lint ret = (b - a).cross(c - b);
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	return 0;
}

bool segmentIntersects(P a, P b, P c, P d) {
	lint ab = 1LL * ccw(a, b, c) * ccw(a, b, d);
	lint cd = 1LL * ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		return !(b < c || d < a);
	}
	return ab <= 0 && cd <= 0;
}

vector<P> getConvex(int x) {
	vector<P> lower, upper;
	sort(arr.begin(), arr.end());
	for (int i = 0; i<arr.size(); i++) {
		while (lower.size() >= 2 && ccw(lower[lower.size() - 2], lower[lower.size() - 1], arr[i]) <= 0)
			lower.pop_back();
		lower.push_back(arr[i]);
	}
	for (int i = arr.size() - 1; i >= 0; i--) {
		while (upper.size() >= 2 && ccw(upper[upper.size() - 2], upper[upper.size() - 1], arr[i]) <= 0)
			upper.pop_back();
		upper.push_back(arr[i]);
	}
	lower.pop_back(); upper.pop_back();
	lower.insert(lower.end(), upper.begin(), upper.end());
	if (x) {
		for (int i = 0; i < lower.size(); i++)
			bseg.push_back({ lower[i], lower[(i + 1) % lower.size()] });
		if (lower.size() == 2) bseg.pop_back();
	}
	else {
		for(int i = 0; i<lower.size(); i++)
			wseg.push_back({ lower[i], lower[(i + 1) % lower.size()] });
		if (lower.size() == 2) wseg.pop_back();
	}
	return lower;
}

void input() {
	cin >> N >> M;
	arr.clear();
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i].x >> arr[i].y;
	black = getConvex(1);
	brr = arr;
	arr.clear();
	arr.resize(M);
	for(int i = 0; i<M; i++)
		cin >> arr[i].x >> arr[i].y;
	white = getConvex(0);
}

bool solve() {
	for (int i = 0; i < bseg.size(); i++)
		for (int j = 0; j < wseg.size(); j++)
			if (segmentIntersects(bseg[i].first, bseg[i].second, wseg[j].first, wseg[j].second))
				return false;
	P x;
	int cnt;
	if (wseg.size()) {
		x = P(brr[0].x - 1, 0);
		cnt = 0;
		for (int j = 0; j < wseg.size(); j++)
			if (segmentIntersects(brr[0], x, wseg[j].first, wseg[j].second)) cnt++;
		if (cnt % 2) return false;
	}
	if (bseg.size()) {
		x = P(arr[0].x - 1, 0);
		cnt = 0;
		for (int i = 0; i < bseg.size(); i++)
			if (segmentIntersects(arr[0], x, bseg[i].first, bseg[i].second)) cnt++;
		if (cnt % 2) return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		init();
		input();
		if (solve()) cout << "YES\n";
		else cout << "NO\n";
	}
	
}