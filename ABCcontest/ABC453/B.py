T,X=map(int,input().split())
A=list(map(int,input().split()))

for i in range(T+1):
    if i==0:
        print(i,A[i])
        num=A[i]
    else:
        if abs(A[i]-num)>=X:
            print(i,A[i])
            num=A[i]

