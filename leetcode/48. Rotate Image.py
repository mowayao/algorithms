class Solution(object):

    def rotate_point_90(self,n,x,y):
        return (y,n-1-x)
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        if n % 2==0:
            l1,l2 = n/2,n/2
        else:
            l1,l2 = n/2,n/2+1
        for i in xrange(l1):
            for j in xrange(l2):
                pre = matrix[i][j]
                x,y = i,j

                for k in xrange(4):
                    #print x,y
                    x,y = self.rotate_point_90(n,x,y)

                    tmp = matrix[x][y]
                    matrix[x][y] = pre
                    pre = tmp
                print
