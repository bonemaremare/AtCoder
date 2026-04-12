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

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const char dir_char[4] = {'R', 'L', 'D', 'U'};

struct State
{
    int y, x, dir;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;

    vector<string> field(H);
    int sy, sx;
    rep(i, H)
    {
        cin >> field[i];
        rep(j, W)
        {
            if (field[i][j] == 'S')
            {
                sy = i;
                sx = j;
            }
        }
    }
    vector<vector<vector<bool>>> seen(5, vector<vector<bool>>(H, vector<bool>(W, false)));

    vector<vector<vector<vector<int>>>> pre_state(4, vector<vector<vector<int>>>(H, vector<vector<int>>(W, vector<int>(4, -1))));

    queue<State> q;

    q.push({sy, sx, 4});
    seen[4][sy][sx] = true;

    int gy = -1, gx = -1, g_dir = -1;

    while (!q.empty())
    {
        State current = q.front();
        q.pop();

        int y = current.y;
        int x = current.x;
        int dir = current.dir;

        if (field[y][x] == 'G')
        {
            gy = y, gx = x, g_dir = dir;
            break;
        }
        vector<int> next_dirs;
        if (field[y][x] == 'S' || field[y][x] == '.')
        {
            next_dirs = {0, 1, 2, 3};
        }
        if (field[y][x] == 'o')
        {
            next_dirs = {dir};
        }
        if (field[y][x] == 'x')
        {
            rep(i, 4)
            {
                if (i != dir)
                {
                    next_dirs.push_back(i);
                }
            }
        }

        for (int ndir : next_dirs)
        {
            int ny = y + dy[ndir];
            int nx = x + dx[ndir];
            if (ny >= H || nx >= W || ny < 0 || nx < 0)
            {
                continue;
            }
            if (field[ny][nx] == '#')
            {
                continue;
            }
            if (seen[ndir][ny][nx])
            {
                continue;
            }

            seen[ndir][ny][nx] = true;
            pre_state[ndir][ny][nx] = {y, x, dir, ndir};
            q.push({ny, nx, ndir});
        }
    }

    if (gy != -1)
    {
        cout << "Yes\n";
        string ans = "";
        int cy = gy, cx = gx, cdir = g_dir;

        while (cdir != 4)
        {
            vector<int> p = pre_state[cdir][cy][cx];
            int py = p[0], px = p[1], pdir = p[2], move_dir = p[3];
            ans += dir_char[move_dir];
            cy = py, cx = px, cdir = pdir;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }

    else
    {
        cout << "No\n";
    }

    return 0;
}
