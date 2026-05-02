S=str(input())
result=0
con_num=1
if len(S)==1:
    print(1)
else:
    for i in range(1,len(S)):
        if S[i]==S[i-1]:
            result+=(1+con_num)*con_num//2
            con_num=1
            if  i==len(S)-1:
                result+=1
        elif i==len(S)-1:
            con_num+=1
            result+=(1+con_num)*con_num//2
        else:
            con_num+=1

    print(result%998244353)
