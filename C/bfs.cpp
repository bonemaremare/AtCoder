#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <cmath>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;

    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;

    vector<string> field(R);
    rep(i, R)
    {
        cin >> field[i];
    }

    vector<vector<int>> dist(R, vector<int>(C, -1));

    queue<pair<int, int>> q;

    dist[sy][sx] = 0;
    q.push({sy, sx});

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        int y = current.first;
        int x = current.second;
        q.pop();

        rep(dir, 4)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || ny >= R || nx < 0 || ny >= R)
            {
                continue;
            }
            if (field[ny][nx] == '#')
            {
                continue;
            }
            if (dist[ny][nx] != -1)
            {
                continue;
            }
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }

    cout << dist[gy][gx] << "\n";

    return 0;
}
