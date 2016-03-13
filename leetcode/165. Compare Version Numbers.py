class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        a = version1.split('.')
        b = version2.split('.')
        n = max(len(a),len(b))
        ret1,ret2 = 0,0

        for i in xrange(n):
            ret1 *= 10
            ret2 *= 10
            if i < len(a):
                ret1 += int(a[i])
            if i < len(b):
                ret2 += int(b[i])


        if ret1 > ret2:return 1
        elif ret1 < ret2: return -1
        else:return 0
