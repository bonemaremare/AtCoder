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

void dfs(int h, int w, int H, int W, const vector<string> &field, vector<vector<bool>> &seen)
{
    if (h < 0 || h >= H || w < 0 || w >= W)
        return;

    if (field[h][w] == '#')
        return;

    if (seen[h][w])
        return;

    seen[h][w] = true;

    rep(dir, 4)
    {
        int next_h = h + dy[dir];
        int next_w = w + dx[dir];
        dfs(next_h, next_w, H, W, field, seen);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;

    vector<string> field(H);
    rep(i, H) cin >> field[i];

    vector<vector<bool>> seen(H, vector<bool>(W, false));

    int start_h = -1, start_w = -1;
    int goal_h = -1, goal_w = -1;

    rep(i, H)
    {
        rep(j, W)
        {
            if (field[i][j] == 's')
            {
                start_h = i;
                start_w = j;
            }
            if (field[i][j] == 'g')
            {
                goal_h = i;
                goal_w = j;
            }
        }
    }

    dfs(start_h, start_w, H, W, field, seen);

    if (seen[goal_h][goal_w])
    {
        cout << "Yes\n";
        return 0;
    }
    else
    {
        cout << "No\n";
        return 0;
    }

    return 0;
}
