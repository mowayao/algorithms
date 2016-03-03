__author__ = 'mowayao'


n = int(raw_input())
MOD = int(1e9+7)
all = 1
for i in xrange(3*n):
    all = all*3%MOD

NO = 1
for i in xrange(n):
    NO = NO*7%MOD
print ((all-NO)%MOD+MOD)%MOD