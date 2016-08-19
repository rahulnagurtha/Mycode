from decimal import Decimal
t = map(int,raw_input().split())
t = t[0]
for x in xrange(1,t+1):
    n , m = map(int,raw_input().split())
    dimension = map(int,raw_input().split())
    print "Case #" + str(x) + ":"
    for z in xrange(0,m):
        l , r = map(int,raw_input().split())
        volume = 1.0
        for y in xrange(l,r+1):
            volume = volume*(dimension[y]**(1.0/(r-l+1)))
        print volume