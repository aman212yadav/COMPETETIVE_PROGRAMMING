#include<bits/stdc++.h>
using namespace std;
  int check(string &s, int k) {
        int n = s.size();
        int q = 6 * (1 << 20) + 1;

        int b = 31;
        int power = 1;
        for (int i = 1; i < k; i++) {
            power = (power * b) % q;
        }
        unordered_map<int, vector<int>> seen;
        int hash = 0;
        for (int i = 0; i < k; i++) {
            hash = (hash * b % q + s[i]) % q;
        }
        seen[hash].push_back(0);
        for (int i = k; i < n; i++) {
            hash = (hash - power * s[i - k] % q + q) % q;
            hash = (hash * b % q + s[i]) % q;
            if (seen.count(hash)) {
                for (int &index : seen[hash]) {
                    if (s.substr(index, k) == s.substr(i - k + 1, k)) {
                        return index;
                    }
                }
            }
            seen[hash].push_back(i - k + 1);
        }
        return -1;
    }
int longestDupSubstring(string &s) {
        int n = s.size();
        int lo = 0, hi = n - 1, mid;
        int startIndex = -1, k = 0;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            int index = check(s, mid);
            if (index != -1) {
                startIndex = index;
                k = mid;

                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (k == 0) {
            return 0;
        }
        return s.substr(startIndex, k).size();
    }

  int main(){
   string s;
   cin>>s;
   cout<<longestDupSubstring(s)<<"\n";
  }
