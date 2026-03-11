A=int(input())
B=int(input())
C=int(input())
X=int(input())

x=X//50

count=0
for i in range(A+1):
    for j in range(B+1):
        left= x-10*i-2*j
        if left<=C and left>=0:
            count+=1
print(count)
