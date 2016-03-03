__author__ = 'mowayao'

import bisect

n,d = map(int,raw_input().split())
friends = [map(int,raw_input().split()) for i in xrange(n)]
friends.sort(lambda x,y:cmp(x[0],y[0]))


S = [0 for i in xrange(n+1)]
ret = 0

for i in xrange(n):
    S[i+1] = S[i]+friends[i][1]

money = [friends[i][0] for i in xrange(n)]
ret = 0
for i in xrange(n):
    id = bisect.bisect_left(money,money[i]+d)
    ret = max(ret,S[id]-S[i])
print ret