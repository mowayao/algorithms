__author__ = 'mowayao'
n,k = map(int,raw_input().split())

a = map(int,raw_input().split())

ret = 0
t = []
for i in xrange(n):
    ret += a[i]/10
    if a[i] < 100:
        t.append([a[i]%10,100-a[i]])
t = sorted(t,cmp=lambda x,y:cmp(x[0],y[0]),reverse=True)
cnt = 0
for i in xrange(len(t)):
    x,f = t[i]
    if 10-x <= k:
        ret += 1
        t[i][1] -= 10-x
        k -= 10-x
        cnt += 10-x
for f,x in t:
    if k < 10:
        break
    if x/10 < k/10:
        ret += x/10
        k -= x/10*10
    else:
        ret += k/10
        k = 0

print ret