N=int(input())
num=list(map(int,input().split()))
count=0
while True:
    divide=True
    for i in range(N):
        if num[i]%2!=0:
            divide=False
            break
    if not divide:
        break
    num=[i//2 for i in num]
    count+=1

print(count)
