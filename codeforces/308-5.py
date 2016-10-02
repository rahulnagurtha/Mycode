'''input
3+5*7+8*4
'''


tmp = raw_input().split('+')
tlen = len(tmp)
newstr = []
z = 0
while(z < tlen):
    if(len(tmp[z]) == 1):
        tempans = 0
        while(z < tlen and len(tmp[z]) == 1):
            tempans += int(tmp[z])
            z += 1
        newstr.append(str(tempans))
    else:
        newstr.append(tmp[z])
        z += 1

original = "+".join(newstr)
orlen = len(original)
fanswer = -1

for x in xrange(0, orlen):
    if(x != 0):
        if(original[x - 1] not in ['+', '*']):
            continue
    for y in xrange(x, orlen):
        if(y != orlen - 1):
            if(original[y + 1] not in ['+', '*']):
                continue
        answer = eval(original[0:x] + '(' + str(eval(original[x:y + 1])) + ')' + original[y + 1:])
        if(answer > fanswer):
            fanswer = answer

print fanswer
