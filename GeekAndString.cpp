class Solution{

public:

    vector<int> prefixCount(int N, int Q, string li[], string query[])

    {

        unordered_map<string,int> mp;

        // int n=li.size();

        for(int i=0;i<N;i++){

            int m=li[i].size();

            string s="";

            for(int j=0;j<m;j++){

                s+=li[i][j];

                mp[s]++;

            }

        }

        vector<int> v;

        for(int i=0;i<Q;i++){

            v.push_back(mp[query[i]]);

        }

        return v;

    }
