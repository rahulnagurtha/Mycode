def fac_mod(n, p):
    if n >= p:
        return 0
    f = 1
    for i in xrange(1, n + 1):
        f = f * i % p
    return f
     
def fac_mod2(n, k):
    if n >= k:
        return 0
    f = 1
    for i in xrange(1, n + 1):
        f = f * i % k
        if f == 0:
            break
    return f

n=input()
p=input()
ans=0
ans1=1
ans2=1

a = []
for x in raw_input().split():
    a.append(int(x))


for x in xrange(0,n):
    ans1=modFact(a[i]+1,p);
    if a[i]%2==0: 
        ans2=(((a[i]%p)*((a[i]/2)%p))*(((a[i]+1))%p))%p
    else: 
        ans2=(((a[i]%p)*((a[i])%p))*(((a[i]+1)/2)%p))%p;
    ans= ans + (ans1+ans2+p-1);
    ans=ans%p;

print ans
    