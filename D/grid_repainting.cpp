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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;
    vector<string> field(H);
    rep(i, H)
    {
        cin >> field[i];
    }

    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};

    vector<vector<int>> dist(H, vector<int>(W, -1));

    queue<pair<int, int>> q;

    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        rep(i, 4)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= H || nx >= W)
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

            q.push({ny, nx});
            dist[ny][nx] = dist[y][x] + 1;
        }
    }
    if (dist[H - 1][W - 1] == -1)
    {
        cout << "-1\n";
        return 0;
    }
    else
    {
        int black_count = 0;
        rep(i, H)
        {
            black_count += count(all(field[i]), '#');
        }

        int result = H * W - (dist[H - 1][W - 1] + 1) - black_count;
        cout << result << "\n";
        return 0;
    }
}
