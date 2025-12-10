class Solution:
    def countPermutations(self, c: List[int]) -> int:
        di = defaultdict(int)
        for i in c:
            di[i] += 1
        k = len(c)
        n = (10**9) + 7
        mi = min(c)
        if di[mi] > 1 or c[0] != mi:
            return 0
        else:
            return math.factorial(k - 1) % n
