N=int(input())

t,x,y=0,0,0
can_walk=True
for i in range(N):
    t_next,x_next,y_next=map(int,input().split())
    if 0>=abs(x_next-x)+abs(y_next-y)-(t_next-t) and  (abs(x_next-x)+abs(y_next-y)-(t_next-t))%2==0:
        can_walk=True
    else :
        can_walk=False
        break
    t=t_next
    x=x_next
    y=y_next

if can_walk:
    print("Yes")

else:
    print("No")
    