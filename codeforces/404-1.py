value = { "Tetrahedron":4,"Cube":6,"Octahedron":8,"Dodecahedron":12,"Icosahedron":20 }

n = input()
answer = 0
for x in xrange(0,n):
	cur = raw_input()
	answer += value[cur]

print answer