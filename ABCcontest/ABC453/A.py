N=int(input())
S=str(input())

for i in range(N):
    if S[0]=="o":
        S=S[1:]
    else:
        break

print(S)
