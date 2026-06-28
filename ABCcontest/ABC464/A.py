A=str(input())
n=0
for i in range(len(A)):
    if A[i]=="E":
        n+=1
    else:
        n-=1

if n>0:
    print("East")
else:
    print("West")
