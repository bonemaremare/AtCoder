import heapq

Q=int(input())
N=[]
result=0
for i in range(Q):
    n,h=map(int,input().split())
    if n==1:
        heapq.heappush(N,h)
        result+=1
        print(result)
    if n==2:
        while N and N[0]<=h:
            heapq.heappop(N)
            result-=1

        
        print(result)



        






    
