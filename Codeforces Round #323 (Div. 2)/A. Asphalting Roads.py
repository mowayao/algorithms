__author__ = 'mowayao'


n = int(raw_input())
visX = [False for i in xrange(n+1)]
visY = visX[:]
for i in xrange(n*n):
    h,v = map(int,raw_input().split())
    if not visX[h] and not visY[v]:
        print i+1,
        visX[h] = visY[v] = True

