A=[[] for _ in range(3)]
for i in range(3):
    A[i]=list(map(int,input().split()))
    
num=[[0]*3 for _ in range(3)]
for i in range(3):
    for j in range(6):
        if A[i][j]==4:
            num[i][0]+=1
        if A[i][j]==5:
            num[i][1]+=1
        if A[i][j]==6:
            num[i][2]+=1

result=num[0][0]*num[1][1]*num[2][2]+num[0][0]*num[1][2]*num[2][1]+num[0][1]*num[1][0]*num[2][2]+num[0][1]*num[1][2]*num[2][0]+num[0][2]*num[1][0]*num[2][1]+num[0][2]*num[1][1]*num[2][0]

print(result/216)

