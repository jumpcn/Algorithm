import sys

INT_MAX = sys.maxint + 1


class LoserTree:
    def __init__(self, L):
        self.L = L
        self.N = len(L)
        self.curN = self.N
        self.tree = [0 for i in xrange(self.N * 2 + 1)]
        self.cur  = [0 for i in xrange(self.N + 1)]
        for i in xrange(self.N):
            self.tree[i + self.N] = i
        for i in range(1, self.N):
            id = self.N - i
            left = id * 2
            right = left + 1
            if self.L[self.tree[left]][0] < self.L[self.tree[right]][0]:
                self.tree[id] = self.tree[left]
            else:
                self.tree[id] = self.tree[right]

        self.Merge()

    def Merge(self):
        print "Merge Begin"
        loser = self.tree[1]
        while self.curN != 0:
            print self.L[loser][self.cur[loser]]
            if self.cur[loser] == len(self.L[loser]) - 1:
                self.curN -= 1
                self.L[loser][-1] = INT_MAX
            else:
                self.cur[loser] += 1
            self.adjust(loser)
            loser = self.tree[1]

    def adjust(self, d):
        d += self.N
        while d != 1:
            d /= 2
            left = d * 2
            right = left + 1
            leftId = self.tree[left]
            rightId = self.tree[right]
            if L[leftId][self.cur[leftId]] < L[rightId][self.cur[rightId]]:
                self.tree[d] = leftId
            else:
                self.tree[d] = rightId


L = [[-1, 1], [2,3,4], [0, 3], [4], [5, 9, 10]]

lt = LoserTree(L)
