N,Y=map(int,input().split())
y=Y//1000

n=y//10 
a,b,c=-1,-1,-1
answer=True
for i in range(n+1):
    left=y-10*i
    m=left//5
    for j in range(m+1):
        if left-5*j==N-i-j:
            a=i
            b=j
            c=N-i-j
            answer=False
            break
    if not answer:
        break
print(a,b,c)
