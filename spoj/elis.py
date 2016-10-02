from itertools import combinations, chain
allsubsets = lambda n: list(
    chain(*[combinations(range(n), ni) for ni in range(n + 1)]))

n = input()
allsets = allsubsets(n)

numbers = []

num = raw_input().split()

for x in xrange(n):
    numbers.append(int(num[x]))
ans = 0

for x in allsets:
    curnum = -1
    curans = 0
    for y in x:
        if curnum < numbers[y]:
            curans = curans + 1
            curnum = numbers[y]
    if curans > ans:
        ans = curans

print ans
