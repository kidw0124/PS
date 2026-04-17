#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>

using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pii>;

struct unit {
	pii pos;
	int team;
	int stamina;
};

const vector<int> dx = { 0,-1,0,1 };
const vector<int> dy = { -1,0,1,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, H, W;
	cin >> N >> H >> W;

	vector<vector<int>> F(H + 2, vector<int>(W + 2, N + 1));

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> F[i][j];
		}
	}

	vector<int> LT(N);
	for (auto& Li : LT) {
		cin >> Li;
		if (Li == -1) Li = 99;
	}
	LT.push_back(99);

	vector<vector<int>> field(H + 2, vector<int>(W + 2, 99));

	for (int i = 0; i <= H + 1; i++) {
		for (int j = 0; j <= W + 1; j++) {
			field[i][j] = LT[F[i][j] - 1];
		}
	}

	int M;
	cin >> M;
	vector<unit> U(M);
	for (auto& Ui : U) {
		cin >> Ui.stamina;
		cin >> Ui.team;
		cin >> Ui.pos.first;
		cin >> Ui.pos.second;
		Ui.team += 1;
		Ui.pos.first += 1;
		Ui.pos.second += 1;
	}

	vector<vector<int>> cellcheck(H + 2, vector<int>(W + 2, 0));
	for (auto Ui : U) {
		cellcheck[Ui.pos.first][Ui.pos.second] = Ui.team;
	}

	int K;
	cin >> K;

	vector<vector<int>> recent(H + 2, vector<int>(W + 2, -1));

	vector<piii> orders(K);
	for (auto& Oi : orders) cin >> Oi.first >> Oi.second.first >> Oi.second.second;

	for (int q = 0; q < K; q++) {
		int Un;
		pii dest;

		Un = orders[q].first;
		dest = orders[q].second;

		Un -= 1;
		dest.first += 1;
		dest.second += 1;

		if (cellcheck[dest.first][dest.second] != 0) continue;

		pii src = U[Un].pos;

		int stamina_limit = U[Un].stamina;

		priority_queue < piii, vector<piii>, greater<piii>> Q;
		Q.push({ 0,src });
		recent[src.first][src.second] = q;

		int success = 0;

		while (!Q.empty()) {
			int cur_dis = Q.top().first;
			pii cur = Q.top().second;
			Q.pop();

			if (abs(cur.first - src.first) > 20 || abs(cur.second - src.second) > 20) continue;
			
			if (cur_dis > stamina_limit) break;
			if (cellcheck[cur.first][cur.second] == 3 - U[Un].team) continue;
			if (cur == dest) {
				success = 1;
				break;
			}
			

			int combat = 0;
			for (int dir = 0; dir < 4; dir++) {
				if (cellcheck[cur.first + dx[dir]][cur.second + dy[dir]] == 3 - U[Un].team) {
					combat = 1;
				}
			}
			if (combat && cur_dis != 0) continue;

			for (int dir = 0; dir < 4; dir++) {
				if (cur_dis + field[cur.first + dx[dir]][cur.second + dy[dir]]
			> stamina_limit) continue;
				if (recent[cur.first + dx[dir]][cur.second + dy[dir]] == q) continue;
				recent[cur.first + dx[dir]][cur.second + dy[dir]] = q;
				Q.push({
					cur_dis + field[cur.first + dx[dir]][cur.second + dy[dir]],
					{cur.first + dx[dir],cur.second + dy[dir]} });
			}

		}

		if (success) {
			cellcheck[src.first][src.second] = 0;
			cellcheck[dest.first][dest.second] = U[Un].team;
			U[Un].pos = dest;
		}

	}
	for (int i = 0; i < U.size(); i++) {
		cout << U[i].pos.first - 1 << ' ' << U[i].pos.second - 1 << '\n';
	}

}