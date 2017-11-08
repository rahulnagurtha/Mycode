n = input()
src = raw_input().split('0')
ans = ""
for x in src:
	ans += str(len(x))
print ans