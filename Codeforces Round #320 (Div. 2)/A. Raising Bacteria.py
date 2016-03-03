__author__ = 'mowayao'

x = int(raw_input())

ret = 0
while x > 0:
    if x % 2 == 1:
        ret += 1
    x /= 2

print ret
