'''
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10

'''
class Solution:
    def diffwayshelper(self, inp: str, i, j):
        #print(inp[i:j + 1])
        Res = []
        L = []
        R = []
        binary = 0

        for x in range(i, j):
            if inp[x] == "+" or inp[x] == "-" or inp[x] == "*":
                binary = 1
                break

        if binary == 1:
            for x in range(i, j):
                if inp[x] == "+" or inp[x] == "-" or inp[x] == "*":
                    L = self.diffwayshelper(inp, i, x - 1)
                    #print("Left eval of {0} is {1}".format(inp[i:x], L))
                    R = self.diffwayshelper(inp, x + 1, j)
                    #print("Left eval of {0} is {1}".format(inp[x+1:j+1], R))
                    for l in L:
                        for r in R:
                            Res.append(eval(str(l) + inp[x] + str(r)))
            return Res
        else:
            return [eval(inp[i:j+1])]

    def diffWaysToCompute(self, inp: str):
        return self.diffwayshelper(inp, 0, len(inp) - 1)



#p = Solution()

#print(p.diffWaysToCompute("2*3-4*5"))
