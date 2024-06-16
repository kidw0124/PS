#include <iostream>
using namespace std;


int x, y, r1, x2, y2, r2;
int dist() {
	return (x - x2)*(x - x2) + (y - y2)*(y - y2);
}
int sq(int x) {
	return x * x;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> x >> y >> r1 >> x2 >> y2 >> r2;

		if (r1 == r2 && x == x2 && y == y2)
			cout << -1;
		else if (dist() > sq(r1 + r2))
			cout << 0;
		else if (dist() == sq(r1 + r2))
			cout << 1;
		else if (dist() < sq(r1 + r2)) {
			if (dist() > sq(r2 - r1))
				cout << 2;
			else if (dist() == sq(r2 - r1))
				cout << 1;
			else if (dist() < sq(r2 - r1))
				cout << 0;
		}
		cout << '\n';
	}
}
