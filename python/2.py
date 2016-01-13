import itertools

all_edges = list(itertools.combinations(range(1,8), 2))
space = []

for x in xrange(1,8):
  space = space + list(itertools.combinations(all_edges, x))

print space[101814]

# t = len(space)
# f = open('bruteout.txt', 'w')
# f.write(str(t) + '\n')

# for edges in space:
#   # f.write('7' + ' ' + str(len(edges)) + '\n')
#   # for edge in edges:
#   #   f.write(str(edge[0]) + ' ' + str(edge[1]) + '\n')
#   # f.close()
#   ans = 0
#   for x in list(itertools.permutations(range(1,8))):
#     flag = 0
#     for y in xrange(6):
#       if( (tuple((x[y],x[y+1])) in edges) or (tuple((x[y+1],x[y])) in edges)):
#         flag = 1
#         break
#     if flag == 0:
#       ans += 1
#   f.write(str(ans) + '\n')
# f.close()