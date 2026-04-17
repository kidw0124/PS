#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<ll, ll> pll;

ll x, y;
vector<pll> v;

void find_intersection(pll A, pll B, pll C, pll D) // 교점 구하기
{
	double px = (A.X * B.Y - A.Y * B.X) * (C.X - D.X) - (A.X - B.X) * (C.X * D.Y - C.Y * D.X);
	double py = (A.X * B.Y - A.Y * B.X) * (C.Y - D.Y) - (A.Y - B.Y) * (C.X * D.Y - C.Y * D.X);
	double p = (A.X - B.X) * (C.Y - D.Y) - (A.Y - B.Y) * (C.X - D.X);

	if (p == 0) // 평행할 때
	{
		// 교점이 하나일 때
		if (B == C && A <= C) cout << B.X << " " << B.Y << '\n';
		else if (A == D && C <= A) cout << A.X << " " << A.Y << '\n';
	}
	else // 교차할 때
	{
		double x = px / p;
		double y = py / p;

		cout << fixed;
		cout.precision(9);
		cout << x << " " << y;
	}
}

ll CCW(pll A, pll B, pll C) 
{
	ll tmp = A.X * B.Y + B.X * C.Y + C.X * A.Y;
	tmp -= B.X * A.Y + C.X * B.Y + A.X * C.Y;

	if (tmp > 0) return 1; // 반시계
	else if (tmp == 0) return 0; // 일직선
	else if (tmp < 0) return -1; // 시계방향
}

void solve(pll A, pll B, pll C, pll D)
{
	ll ans1 = CCW(A, B, C) * CCW(A, B, D);
	ll ans2 = CCW(C, D, A) * CCW(C, D, B);

	if (ans1 == 0 && ans2 == 0) // 평행 혹은 양 끝점이 접촉해 있을 때
	{
		// pair 대소비교. 첫번째 인자가 같다면 두번째 인자 비교
		if (A > B) swap(A, B);
		if (C > D) swap(C, D);
		
		if (A <= D && B >= C)
		{
			cout << 1 << '\n';
			find_intersection(A, B, C, D);
		}
		else cout << 0 << '\n';
	}
	else 
	{
		// 교차 혹은 한 점이 선분 위에 있을 때(끝점 x)
		if (ans1 <= 0 && ans2 <= 0)
		{
			cout << 1 << '\n';
			find_intersection(v[0], v[1], v[2], v[3]);
		}
		else cout << 0 << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++)
	{
		cin >> x >> y;
		v.push_back({ x,y });
	}

	solve(v[0], v[1], v[2], v[3]);
}