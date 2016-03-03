__author__ = 'mowayao'


n = int(raw_input())
a = map(int,raw_input().split())

cnt = ret = 1

for i in xrange(1,n):
    if a[i] >= a[i-1]:
        cnt += 1
        ret = max(ret,cnt)
    else:
        cnt = 1


print ret
