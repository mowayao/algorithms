__author__ = 'mowayao'

n = int(raw_input())

a = map(int,raw_input().split())

M = -1
ans = []
for i in xrange(n-1,-1,-1):
    if M < a[i]:
        ans.append(0)
        M = a[i]
    elif M==a[i]:
        ans.append(1)
    else:
        ans.append(M-a[i]+1)

for i in xrange(n-1,-1,-1):
    print ans[i],