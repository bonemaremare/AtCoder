import sys
sys.setrecursionlimit(5000000)

H,W=map(int,input().split())

M=[[] for i in range(H)]

for i in range(H):
    M[i]=list(input())

sy,sx,gy,gx=-1,-1,-1,-1
for i in range(H):
    for j in range(W):
        if M[i][j]=="S":
            sy=i
            sx=j
        if M[i][j]=="G":
            gy=i
            gx=j

dx=[1,-1,0,0]
dy=[0,0,1,-1]

can_visit=False

visited=[[[False]*W for _ in range(H)] for i in range(4)]

root=[]
result=[]

def dfs(y,x,dydx):
    if visited[y][x][dydx] or M[y][x]=="#" or y<0 or x<0 or y>=H or x>W or can_visit:
        return
    if M[y][x]=="S" or M[y][x]==".":
        visited[0][y][x]=True
        visited[1][y][x]=True
        visited[2][y][x]=True
        visited[3][y][x]=True
        for i in range(4):
            root.append(i)
            dfs(y+dy[i],x+dx[i],i)
            root.pop()

        
    if M[y][x]=="o":
        visited[dydx][y][x]=True
        dfs(y+dy[dydx],x+dx[dydx],dydx)
        root.pop()

            
    
    if M[y][x]=="x":
        visited[dydx][y][x]=True
        for i in range(4):
            if i==dydx:
                continue
            root.append(i)
            dfs(y+dy[i],x+dx[i],i)
            root.pop()

    if M[y][x]=="G":
        can_visit=True
        result=root

dfs(sy,sx,-1)

if can_visit:
    print("Yes")
    for i in range(len(result)):
        if result[i]==0:
            result[i]="R"
        elif result[i]==1:
            result[i]="L"
        elif result[i]==2:
            result[i]="U"
        elif result[i]==3:
            result[i]="D"
else:
    print("No")

            

