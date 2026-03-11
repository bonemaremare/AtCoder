#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void dfs(int y, int x, const vector<string> &map, vector<vector<bool>> &seen)
{
    if (y >= 10 || y < 0 || x >= 10 || x < 0)
    {
        return;
    }
    if (map[y][x] == 'x')
    {
        return;
    }

    if (seen[y][x])
    {
        return;
    }

    seen[y][x] = true;
    rep(i, 4)
    {
        dfs(y + dy[i], x + dx[i], map, seen);
    }
}

bool check(int y, int x, const vector<string> &map)
{
    if (map[y][x] == 'o')
    {
        return false;
    }
    vector<vector<bool>> seen(10, vector<bool>(10, false));
    rep(i, 4)
    {
        dfs(y + dy[i], x + dx[i], map, seen);
    }
    bool oneland = true;
    rep(i, 10)
    {
        rep(j, 10)
        {
            if (map[i][j] == 'o' && seen[i][j] == false)
            {
                oneland = false;
                break;
            }
        }
        if (oneland == false)
        {
            break;
        }
    }
    if (oneland)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> map(10);
    rep(i, 10)
    {
        cin >> map[i];
    }

    rep(i, 10)
    {
        rep(j, 10)
        {
            if (check(i, j, map))
            {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";

    return 0;
}
