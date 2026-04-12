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
int H;
int W;
bool can_visit = false;
vector<int> result;

void dfs(int y, int x, int dir, vector<vector<vector<bool>>> &seen, vector<string> &field, vector<int> &root)
{
    if (y < 0 || x < 0 || y >= H || x >= W)
    {
        return;
    }
    if (seen[dir][y][x] == true)
    {
        return;
    }
    if (field[y][x] == '#' || can_visit)
    {
        return;
    }
    if (field[y][x] == 'G')
    {
        result = root;
        can_visit = true;
        return;
    }
    if (field[y][x] == 'S' || field[y][x] == '.')
    {
        rep(i, 4)
        {
            seen[i][y][x] = true;
        }
        rep(i, 4)
        {
            root.push_back(i);
            dfs(y + dy[i], x + dx[i], i, seen, field, root);
            root.pop_back();
        }
    }
    if (field[y][x] == 'o')
    {
        seen[dir][y][x] = true;
        root.push_back(dir);
        dfs(y + dy[dir], x + dx[dir], dir, seen, field, root);
        root.pop_back();
    }
    if (field[y][x] == 'x')
    {
        seen[dir][y][x] = true;
        rep(i, 4)
        {
            if (i != dir)
            {
                root.push_back(i);
                dfs(y + dy[i], x + dx[i], i, seen, field, root);
                root.pop_back();
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> H >> W;

    vector<string> field(H);
    int sy = -1;
    int sx = -1;

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
    vector<vector<vector<bool>>> seen(4, vector<vector<bool>>(H, vector<bool>(W, false)));

    vector<int> root;

    dfs(sy, sx, 0, seen, field, root);

    if (can_visit)
    {
        cout << "Yes\n";
        rep(i, result.size())
        {
            if (result[i] == 0)
                cout << "R";
            else if (result[i] == 1)
                cout << "L";
            else if (result[i] == 2)
                cout << "D";
            else if (result[i] == 3)
                cout << "U";
        }
        cout << "\n";
    }

    else
    {
        cout << "No\n";
    }
    return 0;
}
