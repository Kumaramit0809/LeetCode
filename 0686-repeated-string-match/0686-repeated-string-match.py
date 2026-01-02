class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        s = ""
        count = 0
        
        while len(s) < len(b) + len(a):
            s += a
            count += 1
            
            if b in s:
                return count
        return -1