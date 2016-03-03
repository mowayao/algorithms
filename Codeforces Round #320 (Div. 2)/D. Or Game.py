__author__ = 'mowayao'

n,k,x = map(int,raw_input().split())
a = map(int,raw_input().split())

p = [0 for i in xrange(n+1)]
s = [0 for i in xrange(n+1)]

for i in xrange(n):
    p[i+1] = p[i]|a[i]

for i in xrange(n-1,0,-1):
    s[i] = s[i+1]|a[i]

d = x**k
ret = 0
for i in xrange(n):
    ret = max(ret,p[i]|a[i]*d|s[i+1])
print ret