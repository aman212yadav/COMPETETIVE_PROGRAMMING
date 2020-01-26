class Solution {
public:

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector< vector<long long > > dist(n,vector<long long >(n,INT_MAX));
        for(auto k : edges ){
            dist[k[0]][k[1]]=k[2];
            dist[k[1]][k[0]]=k[2];
        }

        for (int k = 0; k < n; k++)
    {

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {

                if (dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
        int co=0,city=INT_MAX,idx=-1;
        for(int i=0;i<n;i++){
            co=0;
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                if(dist[i][j]==INT_MAX)
                    continue;
                   if(dist[i][j]<=distanceThreshold)
                        co++;
            }
        //   cout<<i<<" "<<co<<"\n";
            if(co<=city)
            {idx=i;
             city=co;
            }
        }
        return idx;


    }
};
