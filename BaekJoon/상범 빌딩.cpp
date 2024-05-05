#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

class pos {
public:
	int z = 0;
	int x = 0;
	int y = 0;
};

int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { 0,0,1,0,-1,0 };
int dz[6] = { 1,0,0,0,0,-1 };

int L, R, C; // 층 행 열
string map[32][32];
int vis[32][32][32];
int ans;
pos st, ed;

bool OOB(pos s) {
	return s.x < 0 || s.x >= R || s.y < 0 || s.y >= C || s.z< 0 || s.z >= L ;
}

int bfs(pos s) {
	queue<pos> Q;
	Q.push(s);
	while (!Q.empty()) {
		pos cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nz = cur.z + dz[dir];
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (OOB({nz,nx,ny}) || vis[nz][nx][ny]) continue;
			if (map[nz][nx][ny] == '#') continue;
			if (map[nz][nx][ny] == 'E') return vis[cur.z][cur.x][cur.y];
			Q.push({ nz,nx,ny });
			vis[nz][nx][ny] = vis[cur.z][cur.x][cur.y] + 1;
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (1) {
		cin >> L >> R >> C;
		if (!L && !R && !C) break;
		for (int i = 0; i < L; i++)
			for (int j = 0; j < R; j++) 
				cin >> map[i][j];
		
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					if (map[i][j][k] == 'S') st = { i,j,k };
					if (map[i][j][k] == 'E') ed = { i,j,k };
				}
			}
		}

		vis[st.z][st.x][st.y] = 1;
		ans = bfs(st);
		if (!ans) cout << "Trapped!" << "\n";
		else cout << "Escaped in " << ans << " minute(s)." << "\n";

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					vis[i][j][k] = 0;
				}
			}
		}
	}

	return 0;
}
