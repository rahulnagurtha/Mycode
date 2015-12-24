import string
digs = string.digits + string.letters
 
def int2base(x, base):
  if x < 0: sign = -1
  elif x == 0: return digs[0]
  else: sign = 1
  x *= sign
  digits = []
  while x:
    digits.append(digs[x % base])
    x /= base
  if sign < 0:
    digits.append('-')
  digits.reverse()
  return ''.join(digits)
 
 
t = input()
for x in xrange(0,t):
  a = raw_input()
  b = raw_input()
  l = input()
  ans = int2base(int(a,7)/int(b,7),7)
  lft = max(0,len(ans)-l)
  print ans[lft:]