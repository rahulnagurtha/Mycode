from sets import Set
t = int(raw_input())
for i in range(0,t):
	b = raw_input();
	w = raw_input();
	bset = Set(list(b))
	wset = Set(list(w))
	print len(bset.intersection(wset));
