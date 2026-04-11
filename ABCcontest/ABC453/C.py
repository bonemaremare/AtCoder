N=int(input())

S=list(map(int,input().split()))

x=0.5
count=0

for i in range(N):
    if x>0:
        if x<S[i]:
            count+=1
        x-=S[i]
    
    elif x<0:
        if abs(x)<=S[i]:
            count+=1
        x+=S[i]


print(count)
