__author__ = 'mowayao'


logo = map(int,raw_input().split())

for i in xrange(0,6,2):
    logo[i],logo[i+1] = min(logo[i],logo[i+1]),max(logo[i],logo[i+1])

if logo[1] == logo[3] and logo[1]==logo[5]:
    if logo[0]+logo[2]+logo[4] == logo[1]:
        print logo[1]
        for i in xrange():
    else:
        print -1

elif


