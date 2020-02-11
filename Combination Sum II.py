'''
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
'''


from collections import defaultdict


class Solution:
    R = []
    l = []
    d = defaultdict(list)
    str=" "

    def combinationsumHelper(self, c, target, indx):
        self.str+="    "

        print("{3} Child invoked: cand {0}, target {1}, indx {2}".format(c, target, indx, self.str))
        if (len(c) == 0):
            self.str= self.str[:-1]
            return

        if (c[0] > target):
        #   self.str = self.str[:-1]
            return
        if (c[0] == target):
            self.l.append(c[0])
            self.R.append(self.l.copy())
            print("{1} found solution {0}".format(self.l, self.str))
            self.l.pop(len(self.l) - 1)
            self.str = self.str[:-1]
            return
        else:
            print("{3} Attempting to Choosing {0} at indx {1} for target {2}".format(c[0], indx, target, self.str))
            choose = 1
            if len(self.d[target]) != 0:
                y = self.d[target]
                print("{1} Mapping exists {0} : Mapping for target {2} is {3}".format(y, self.str, target, y))
                for a, b in y:
                    if b == c[0]:
                        print("{5} Eliminated choosing {0} at {1} for target {2} as already visited at {4} partial {3}".format(
                            c[0], indx, target, self.l, a, self.str))
                        self.str = self.str[:-1]
                        choose = 0
            if (choose == 1):
                self.d[target].append([indx, c[0]])
                print("{4} Chose {0} at indx {1} for target {2} new targer for child is {3}".format(c[0], indx, target, target-c[0], self.str))
                # choose
                self.l.append(c[0])
                self.combinationsumHelper(c[1:len(c)], target - c[0], indx + 1)
                self.l.pop(len(self.l) - 1)
                self.str = self.str[:-1]

        # not-choose
        #print("{1} Not choose {0}".format(c[0], self.str))
        self.combinationsumHelper(c[1:len(c)], target, indx + 1)
        if (choose == 1):
            self.d[target].remove([indx, c[0]])

    def combinationSum2(self, candidates, target):
        self.R = []
        self.l = []
        self.d = defaultdict(list)
        candidates.sort()
        self.combinationsumHelper(candidates, target, 0)
        return self.R


p = Solution()
#print(p.combinationSum2([2,2,1,5,2], 5))
print(p.combinationSum2([4,4,2,1,4,2,2,1,3], 6))



'''

'''
