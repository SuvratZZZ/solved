
def hel(ind,cou,plr,a,dp):
    if ind < 0 :
        return 1
    res:int = 0
    if(plr==1):
        if(a[ind]==cou):
            res=res+hel(ind-1,cou,0,a,dp)
        else:
            return 0
            
    else :
        res=res+hel(ind-1,cou+1,1,a,dp)
        if(a[ind]==cou):
            res=res+hel(ind-1,cou,0,a,dp)
    
    dp[cou][plr]=res
    return res

    

def sol():
    n = int(input())
    a = list(map(int,input().split()))
    dp = []
    for i in range(n):
        tem = []
        for j in range (2):
            tem.append(-1)
        dp.append(tem)
    print(hel(n-1,0,0,a,dp))

if __name__ == "__main__" :
    n = int(input())
    while(n):
        sol()
        n=n-1
