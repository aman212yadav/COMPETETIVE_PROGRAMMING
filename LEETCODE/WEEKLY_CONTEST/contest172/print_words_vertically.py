# problem link - https://leetcode.com/contest/weekly-contest-172/problems/print-words-vertically
# space complexity - O(number of words * maxlen)
class Solution:
    def printVertically(self, s: str) -> List[str]:
        p=s.split(" ")
        l=len(max(p,key=len))
        ll=[""]*l
        for i in range(l):
            for j in range(len(p)):
                if len(p[j])>=i+1:
                    ll[i]=ll[i]+p[j][i]
                else:
                    ll[i]=ll[i]+" "
        for i in range(l):
            ll[i]=ll[i].rstrip()
        return ll

