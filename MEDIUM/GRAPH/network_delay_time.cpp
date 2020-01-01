// problem link - https://leetcode.com/problems/network-delay-time
// time complexity - O(Elog(V))
// space complexity - O(N)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
       vector< vector<pair<int,int> > > v(N+1);
        for(int i=0;i<times.size();i++){
            vector<int> &g=times[i];
            v[g[0]].push_back(make_pair(g[1],g[2]));
        }
    vector<int> dist(N+1,INT_MAX);
    priority_queue< pair<int,int> ,vector< pair<int,int> >,greater< pair<int,int> > > pq;
    dist[K]=0;
        pq.push(make_pair(0,K));
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            for(auto v : v[p.second]){

                if( v.second+dist[p.second] < dist[v.first] ){
                       dist[v.first]=v.second+dist[p.second];
                       pq.push({dist[v.first],v.first});
                }
            }

        }
     int sum=0;
     for(int i=1;i<=N;i++){
          if(dist[i]==INT_MAX)
               return -1;
         sum=max(sum,dist[i]);
     }
        return sum;


    }
};
