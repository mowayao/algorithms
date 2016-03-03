class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """

        _,__,___ = n+m-1,m-1,n-1

        while __ >= 0 and ___ >= 0:
            if nums1[__] >= nums2[___]:
                nums1[_] = nums1[__]
                __-=1
            else:
                nums1[_] = nums2[___]
                ___-=1
            _ -= 1

        while ___ >= 0:
            nums1[_] = nums2[___]
            ___ -= 1
            _ -=1

        
