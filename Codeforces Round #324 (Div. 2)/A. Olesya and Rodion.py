__author__ = 'mowayao'


n,t = map(int,raw_input().split())

ret = 0
if t==10:
    ret = 10**(n-1)
    if ret == 1:ret=-1
else:
    for i in xrange(n):
        ret *= 10
        ret += t
print ret