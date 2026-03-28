N,M=map(int,input().split())

result=[0 for i in range(M)]

for i in range(N):
    A,B=map(int,input().split())
    result[A-1]-=1
    result[B-1]+=1

for i in range(M):
    print(result[i])
