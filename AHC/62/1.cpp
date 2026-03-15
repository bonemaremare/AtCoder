#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <cstring>

using namespace std;

const int N = 200;
long long A[N][N];
long long macro_val[10][10]; // 20x20マスの合計 (10x10ブロック)
long long mid_val[50][50];   // 4x4マスの合計 (50x50サブブロック)

struct Point
{
    int r, c;
};
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool is_adj(Point p1, Point p2)
{
    return max(abs(p1.r - p2.r), abs(p1.c - p2.c)) <= 1;
}

// ---------------------------------------------------
// タイムマネジメント設定（0.5秒残すために全体を2.5秒以内に収める）
// ---------------------------------------------------
const double TIME_LIMIT_PHASE1 = 1.0; // マクロ層の焼きなまし（1.0秒）
const double TIME_LIMIT_PHASE2 = 2.0; // ミドル層の焼きなまし（累積2.0秒）
// 残りの0.5秒はミクロ層の経路探索（一瞬で終わる想定）

// ---------------------------------------------------
// 安全装置付きDFS（指定された入口から出口までを一筆書き）
// ---------------------------------------------------
struct Node
{
    int r, c, deg;
    double dist;
};

bool vis[10][10];
int path_r[100], path_c[100];
int dfs_iters = 0; // 探索回数をカウントして暴走を防ぐ

bool solve_dfs(int r, int c, int depth, int max_depth, int goal_r, int goal_c, int grid_size, int limit)
{
    dfs_iters++;
    if (dfs_iters > limit)
        return false; // 規定回数を超えたら強制終了（TLE防止）

    path_r[depth] = r;
    path_c[depth] = c;
    vis[r][c] = true;

    if (depth == max_depth - 1)
    {
        if (r == goal_r && c == goal_c)
            return true;
        vis[r][c] = false;
        return false;
    }

    vector<Node> nxts;
    for (int i = 0; i < 8; i++)
    {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < grid_size && nc >= 0 && nc < grid_size && !vis[nr][nc])
        {
            if (depth < max_depth - 2 && nr == goal_r && nc == goal_c)
                continue;
            if (depth == max_depth - 2 && (nr != goal_r || nc != goal_c))
                continue;

            int deg = 0;
            for (int j = 0; j < 8; j++)
            {
                int nnr = nr + dr[j], nnc = nc + dc[j];
                if (nnr >= 0 && nnr < grid_size && nnc >= 0 && nnc < grid_size && !vis[nnr][nnc])
                    deg++;
            }
            nxts.push_back({nr, nc, deg, max(abs(nr - goal_r), abs(nc - goal_c)) * 1.0});
        }
    }

    // Warnsdorffのヒューリスティック：行き止まりになりやすいマスを優先
    sort(nxts.begin(), nxts.end(), [](const Node &a, const Node &b)
         {
        if (a.deg != b.deg) return a.deg < b.deg;
        return a.dist > b.dist; });

    for (auto &nxt : nxts)
    {
        if (solve_dfs(nxt.r, nxt.c, depth + 1, max_depth, goal_r, goal_c, grid_size, limit))
            return true;
    }

    vis[r][c] = false;
    return false;
}

// ブロック間のざっくりとした出入り口を決める関数
pair<Point, Point> get_conn(int size, int r1, int c1, int r2, int c2)
{
    int max_idx = size - 1;
    int d_r = r2 - r1, d_c = c2 - c1;
    Point out1, in2;
    if (d_r == 1 && d_c == 0)
    {
        out1 = {max_idx, size / 2};
        in2 = {0, size / 2};
    }
    else if (d_r == -1 && d_c == 0)
    {
        out1 = {0, size / 2};
        in2 = {max_idx, size / 2};
    }
    else if (d_r == 0 && d_c == 1)
    {
        out1 = {size / 2, max_idx};
        in2 = {size / 2, 0};
    }
    else if (d_r == 0 && d_c == -1)
    {
        out1 = {size / 2, 0};
        in2 = {size / 2, max_idx};
    }
    else if (d_r == 1 && d_c == 1)
    {
        out1 = {max_idx, max_idx};
        in2 = {0, 0};
    }
    else if (d_r == 1 && d_c == -1)
    {
        out1 = {max_idx, 0};
        in2 = {0, max_idx};
    }
    else if (d_r == -1 && d_c == 1)
    {
        out1 = {0, max_idx};
        in2 = {max_idx, 0};
    }
    else if (d_r == -1 && d_c == -1)
    {
        out1 = {0, 0};
        in2 = {max_idx, max_idx};
    }
    else
    {
        out1 = {0, 0};
        in2 = {0, 0};
    }
    return {out1, in2};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dummy_N;
    if (!(cin >> dummy_N))
        return 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            macro_val[i / 20][j / 20] += A[i][j];
            mid_val[i / 4][j / 4] += A[i][j];
        }
    }

    auto start_time = chrono::system_clock::now();

    // ==========================================
    // 第1フェーズ：10x10 マクロ層の焼きなまし (1.0秒まで)
    // ==========================================
    vector<Point> macro_path;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i % 2 == 0)
                macro_path.push_back({i, j});
            else
                macro_path.push_back({i, 9 - j});
        }
    }

    while (true)
    {
        auto now = chrono::system_clock::now();
        double elapsed = chrono::duration_cast<chrono::milliseconds>(now - start_time).count() / 1000.0;
        if (elapsed > TIME_LIMIT_PHASE1)
            break;

        int l = rand() % 100, r = rand() % 100;
        if (l == r)
            continue;
        if (l > r)
            swap(l, r);

        bool ok = true;
        if (l > 0 && !is_adj(macro_path[l - 1], macro_path[r]))
            ok = false;
        if (r < 99 && !is_adj(macro_path[l], macro_path[r + 1]))
            ok = false;

        if (ok)
        {
            long long delta = 0;
            for (int i = l; i <= r; i++)
            {
                int new_pos = r - (i - l);
                delta -= (long long)i * macro_val[macro_path[i].r][macro_path[i].c];
                delta += (long long)new_pos * macro_val[macro_path[i].r][macro_path[i].c];
            }
            if (delta > 0)
                reverse(macro_path.begin() + l, macro_path.begin() + r + 1);
        }
    }

    // ==========================================
    // 第2フェーズ：5x5 ミドル層の焼きなまし 100セット (累積2.0秒まで)
    // ==========================================
    vector<Point> global_mid_path;

    for (int i = 0; i < 100; i++)
    {
        Point cur_m = macro_path[i];
        Point in_p, out_p;

        if (i == 0)
            in_p = {0, 0};
        else
            in_p = get_conn(5, macro_path[i - 1].r, macro_path[i - 1].c, cur_m.r, cur_m.c).second;

        if (i == 99)
            out_p = {4, 4};
        else
            out_p = get_conn(5, cur_m.r, cur_m.c, macro_path[i + 1].r, macro_path[i + 1].c).first;

        memset(vis, 0, sizeof(vis));
        dfs_iters = 0;

        // 5x5の一筆書き生成（失敗防止のため上限2000回）
        if (!solve_dfs(in_p.r, in_p.c, 0, 25, out_p.r, out_p.c, 5, 2000))
        {
            // 万が一失敗した場合は適当なジグザグで埋める（安全対策）
            int idx = 0;
            for (int rr = 0; rr < 5; rr++)
            {
                for (int cc = 0; cc < 5; cc++)
                {
                    path_r[idx] = rr;
                    path_c[idx] = (rr % 2 == 0) ? cc : 4 - cc;
                    idx++;
                }
            }
        }

        vector<Point> mid_path(25);
        for (int k = 0; k < 25; k++)
            mid_path[k] = {path_r[k], path_c[k]};

        double time_limit = TIME_LIMIT_PHASE1 + (TIME_LIMIT_PHASE2 - TIME_LIMIT_PHASE1) * ((i + 1) / 100.0);
        while (true)
        {
            auto now = chrono::system_clock::now();
            double elapsed = chrono::duration_cast<chrono::milliseconds>(now - start_time).count() / 1000.0;
            if (elapsed > time_limit)
                break;

            int l = 1 + rand() % 23;
            int r = 1 + rand() % 23;
            if (l == r)
                continue;
            if (l > r)
                swap(l, r);

            if (is_adj(mid_path[l - 1], mid_path[r]) && is_adj(mid_path[l], mid_path[r + 1]))
            {
                long long delta = 0;
                for (int k = l; k <= r; k++)
                {
                    int new_pos = r - (k - l);
                    int gr = cur_m.r * 5 + mid_path[k].r;
                    int gc = cur_m.c * 5 + mid_path[k].c;
                    delta -= (long long)k * mid_val[gr][gc];
                    delta += (long long)new_pos * mid_val[gr][gc];
                }
                if (delta > 0)
                    reverse(mid_path.begin() + l, mid_path.begin() + r + 1);
            }
        }

        for (int k = 0; k < 25; k++)
        {
            global_mid_path.push_back({cur_m.r * 5 + mid_path[k].r, cur_m.c * 5 + mid_path[k].c});
        }
    }

    // ==========================================
    // 第3フェーズ：4x4 ミクロ層の繋ぎこみ 2500セット
    // ==========================================
    vector<Point> final_path;

    for (int i = 0; i < 2500; i++)
    {
        Point cur_s = global_mid_path[i];
        Point in_m;

        // 入口の確定：前のブロックの最後のマスと隣接するマスを探す
        if (i == 0)
        {
            in_m = {0, 0};
        }
        else
        {
            Point last_p = final_path.back();
            bool found = false;
            for (int r = 0; r < 4 && !found; r++)
            {
                for (int c = 0; c < 4 && !found; c++)
                {
                    int gr = cur_s.r * 4 + r;
                    int gc = cur_s.c * 4 + c;
                    if (is_adj({gr, gc}, last_p))
                    {
                        in_m = {r, c};
                        found = true;
                    }
                }
            }
            if (!found)
                in_m = {0, 0}; // 安全装置
        }

        // 出口候補のリストアップ：次のブロックと隣接しているマスを全て候補にする
        vector<Point> valid_exits;
        if (i == 2499)
        {
            for (int r = 0; r < 4; r++)
                for (int c = 0; c < 4; c++)
                    valid_exits.push_back({r, c});
        }
        else
        {
            Point next_s = global_mid_path[i + 1];
            for (int r = 0; r < 4; r++)
            {
                for (int c = 0; c < 4; c++)
                {
                    int gr = cur_s.r * 4 + r;
                    int gc = cur_s.c * 4 + c;
                    bool adj_next = false;
                    for (int nr = 0; nr < 4 && !adj_next; nr++)
                    {
                        for (int nc = 0; nc < 4 && !adj_next; nc++)
                        {
                            if (is_adj({gr, gc}, {next_s.r * 4 + nr, next_s.c * 4 + nc}))
                                adj_next = true;
                        }
                    }
                    if (adj_next)
                        valid_exits.push_back({r, c});
                }
            }
        }

        // DFSで複数のゴール候補を試し、一瞬（上限300回）でパスを見つける
        bool path_found = false;
        for (auto out_m : valid_exits)
        {
            memset(vis, 0, sizeof(vis));
            dfs_iters = 0;
            if (solve_dfs(in_m.r, in_m.c, 0, 16, out_m.r, out_m.c, 4, 300))
            {
                path_found = true;
                break;
            }
        }

        // 万が一全てのゴール候補で失敗した場合の安全装置（ジグザグ）
        if (!path_found)
        {
            int idx = 0;
            for (int rr = 0; rr < 4; rr++)
            {
                for (int cc = 0; cc < 4; cc++)
                {
                    path_r[idx] = rr;
                    path_c[idx] = (rr % 2 == 0) ? cc : 3 - cc;
                    idx++;
                }
            }
        }

        for (int k = 0; k < 16; k++)
        {
            final_path.push_back({cur_s.r * 4 + path_r[k], cur_s.c * 4 + path_c[k]});
        }
    }

    // ==========================================
    // 結果出力
    // ==========================================
    for (auto &p : final_path)
    {
        cout << p.r << " " << p.c << "\n";
    }

    return 0;
}
