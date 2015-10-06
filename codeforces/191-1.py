ans = 0
cur = 0
temp = 0
dataone = []
datazero = []

dataone.append(0)
datazero.append(0)

inpu = raw_input()

inp = raw_input().split();


for x in inp:
	temp = len(dataone)
	if x == '0':
		dataone.append(dataone[temp-1])
		datazero.append(datazero[temp-1] + 1)
	else:
		cur = cur + 1
		dataone.append(dataone[temp-1] + 1)
		datazero.append(datazero[temp-1])

ans = 0

for i in xrange(1,len(inp)+1):
	for j in xrange(1,len(inp)-i+2):
		temp = cur + (datazero[j+i-1] - datazero[j-1]) - (dataone[j+i-1] - dataone[j-1])
		if ans < temp :
			ans = temp

print ans