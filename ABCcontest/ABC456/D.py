S=str(input())
N=[0]*len(S)
N[0]=1
if len(S)==1:
    print(1)
else:
    for i in range(1,len(S)):
        N[i]+=1
        for j in range(i):
            if S[i]!=S[j]:
                N[i]+=N[j]
    print(sum(N)%998244353 )
