N=int(input())

S=list(map(int,input().split()))
result=0
for bit in range(1<<N):
    x=0.5
    next_x=0
    count=0
    for i in range(N):
        if bit & (1<<i):
            next_x=x+S[i]
        else:
            next_x=x-S[i]
        
        if x*next_x<0:
            count+=1
        x=next_x
    
    if count>result:
        result=count

print(result)
    
                
