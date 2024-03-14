#include <bits/stdc++.h>
using namespace std;

int n;
int T[22][22];
vector<int> v;
vector<int> stu[555];
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};
int score[5] = {0, 1, 10, 100, 1000};
int ans;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int input1;
    int input2;
    for (int i = 0; i < n * n; i++) {
        cin >> input1;
        v.push_back(input1);
        for (int j = 0; j < 4; j++) {
            cin >> input2;
            stu[input1].push_back(input2);
        }
    }
    T[2][2] = v[0];
    pair<int, int> cor;
    int mostBlank;
    int curStudent;
    int mostLike;
    for (int i = 1; i < v.size(); i++) {
        curStudent = v[i];
        mostLike = -1;
        mostBlank = -1;
        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= n; c++) {
                if (T[r][c]) {
                    continue;
                }
                int like = 0;
                int blank = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int cr = r + dr[dir];
                    int cc = c + dc[dir];
                    for (int a = 0; a < 4; a++) {
                        if (T[cr][cc] == stu[curStudent][a]) {
                            like++;
                        }
                    }
                    if (!T[cr][cc] && cr != 0 && cc != 0 && cr != n &&
                        cc != n) {
                        blank++;
                    }
                }
                if (mostLike < like) {
                    mostLike = like;
                    mostBlank = blank;
                    cor = {r, c};
                }
                if (mostLike == like) {
                    if (mostBlank < blank) {
                        mostLike = like;
                        mostBlank = blank;
                        cor = {r, c};
                    }
                }
            }
        }
        T[cor.first][cor.second] = curStudent;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int like = 0;
            for (int dir = 0; dir < 4; dir++) {
                int cr = i + dr[dir];
                int cc = j + dc[dir];
                for (int num = 0; num < 4; num++) {
                    if (stu[T[i][j]][num] == T[cr][cc]) {
                        like++;
                        break;
                    }
                }
            }
            ans += score[like];
        }
    }
    cout << ans;
    return 0;
}