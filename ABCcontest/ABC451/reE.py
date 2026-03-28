N=int(input())

G=[]
for i in range(1,N):
    connect=list(map(int,input().split()))
    G.append(connect)

can_make=True

for i in range(N-2):
    if not can_make:
        break
    Gi=G[i]
    for j in range(i+1,N-1):
        if not can_make:
            break
        Gj=G[j]
        t1=Gi[j-i-1]
        for k in range(j+1,N):
            t2=Gj[k-j-1]
            t3=Gi[k-i-1]
            
            if t1+t2<t3 or t1+t3<t2 or t2+t3<t1:
                can_make=False
                break

if can_make:
    print("Yes")
else:
    print("No")



