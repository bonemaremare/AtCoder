H,W=map(int,input().split())

C=[[] for _ in range(H)]

for i in range(H):
    C[i]=str(input())

con=True
for i in range(H):
    if con==False:
        break
    for j in range(W):
        if C[i][j]=="#":
            U=i
            con=False
            break


con=True
for i in range(H):
    if con==False:
        break
    for j in range(W):
        if C[H-1-i][j]=="#":
            D=H-1-i
            con=False
            break

con=True
for j in range(W):
    if con==False:
        break
    for i in range(H):
        if C[i][j]=="#":
            L=j
            con=False
            break

con=True
for j in range(W):
    if con==False:
        break
    for i in range(H):
        if C[i][W-1-j]=="#":
            R=W-1-j
            con=False
            break

for i in range(U,D+1):
        print((C[i][L:R+1]))






