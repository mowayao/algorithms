__author__ = 'mowayao'

n = int(raw_input())
a,b = map(int,raw_input().split())


pl = a - b
ad = a + b

if pl < 0:
    print -1
elif pl == 0:
    print a
else:
    x = 1e9
    k1 = ad / b
    k2 = pl / b
    k1 -= k1%2+1
    k2 -= k2%2
    while k1 > 2 and ad/(k1+1) < b :
        k1 -= 2
    x = min(x,float(ad)/(k1+1))
    while k2 > 3 and pl/k2 < b  :
        k2 -= 2
    if k2 > 0:
        x = min(x,float(pl)/k2)
    print x