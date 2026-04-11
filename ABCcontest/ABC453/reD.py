import sys

sys.setrecursionlimit(5000000)

H, W = map(int, input().split())
M = [list(input()) for _ in range(H)]

sy, sx, gy, gx = -1, -1, -1, -1
for i in range(H):
    for j in range(W):
        if M[i][j] == "S":
            sy, sx = i, j
        if M[i][j] == "G":
            gy, gx = i, j

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

can_visit = False
visited = [[[False] * W for _ in range(H)] for i in range(4)]
root = []
result = []

def dfs(y, x, dydx):
    global can_visit, result

    if y < 0 or x < 0 or y >= H or x >= W:
        return
    if M[y][x] == "#" or can_visit:
        return
    if dydx != -1 and visited[dydx][y][x]:
        return

    if M[y][x] == "G":
        can_visit = True
        result = list(root)
        return

    if M[y][x] == "S" or M[y][x] == ".":
        visited[0][y][x] = True
        visited[1][y][x] = True
        visited[2][y][x] = True
        visited[3][y][x] = True
        for i in range(4):
            root.append(i)
            dfs(y + dy[i], x + dx[i], i)
            root.pop()

    elif M[y][x] == "o":
        if dydx != -1:
            visited[dydx][y][x] = True
            root.append(dydx)
            dfs(y + dy[dydx], x + dx[dydx], dydx)
            root.pop()

    elif M[y][x] == "x":
        if dydx != -1:
            visited[dydx][y][x] = True
            for i in range(4):
                if i == dydx:
                    continue
                root.append(i)
                dfs(y + dy[i], x + dx[i], i)
                root.pop()

dfs(sy, sx, -1)

if can_visit:
    print("Yes")
    ans_chars = []
    for i in range(len(result)):
        if result[i] == 0:
            ans_chars.append("R")
        elif result[i] == 1:
            ans_chars.append("L")
        elif result[i] == 2:
            ans_chars.append("D")
        elif result[i] == 3:
            ans_chars.append("U")
    print(*ans_chars, sep="")
else:
    print("No")
