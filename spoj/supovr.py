balls = raw_input().split()

b = []

b.append(0)
b.append(0)
b.append(0)
b.append(0)

cur = 1
opp = 2
present = 0
flag = 0

for x in balls:
	# print 'cur is:',cur
 # 	print 'opp is:',opp,'\n'
 	if x in ['W','N','O']:
 		if x == 'O':
 			if(cur == 3 or opp == 3) :
 				flag = 1
 			cur = 3
 	else:
 		present = int(x)
 		b[cur] = present + b[cur]
 		if present%2 == 1:
 			cur,opp = opp,cur
 	if flag == 1:
 		break
 	

print b[1]
print b[2]
print b[3]