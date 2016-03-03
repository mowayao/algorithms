__author__ = 'mowayao'
import sys
sys.setrecursionlimit(10**8)
from Queue import Queue
pattern = lambda :map(int,raw_input().split())
n,m = pattern()
a = [0]+pattern()
edges = [[] for i in xrange(n+1)]
for i in range(n-1):
    u,v = pattern()
    edges[u].append(v)
    edges[v].append(u)

que = Queue()
que.put_nowait((1,-1,a[1]))
ret = 0
while not que.empty():
    u,fa,cnt = que.get_nowait()
    for v in edges[u]:
        if v != fa:
            cnt1 = cnt+1 if a[v] else 0
            if cnt1 <= m:
                que.put_nowait((v,u,cnt1))
                if len(edges[v]) == 1:
                    ret += 1
                    #print v

print ret
