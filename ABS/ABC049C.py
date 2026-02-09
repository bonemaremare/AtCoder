S=input()

S=S[::-1]

words=["maerd","remaerd","esare","resare"]

i=0
N=len(S)
can_make=True
while i<N:
    matched=False
    for w in words:
        if S[i: i+len(w)]==w:
            i+=len(w)
            matched=True
            break
    if not matched:
        can_make=False
        break

if can_make:
    print("YES")
    
else:
    print("NO")


