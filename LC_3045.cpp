//https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/description/
struct TrieNode {
    struct TrieNode *children[26];
    set<int>inds;

    // isLeaf is true if the node represents
    // end of a word
    // bool isLeaf;
};
class Solution {
public:
    
    #define ll long long 
    void deleteTrie(TrieNode* t) {
        if (t == nullptr) return;
        for (int i = 0; i < 26; ++i) {
            deleteTrie(t->children[i]);
        }
        delete t;
    }
    void Insert(TrieNode* t, string w, int ind)
    {
        for(auto &ch : w)
        {
            if(t -> children[ch - 'a'] == NULL)
            {
                t -> children[ch - 'a'] = new TrieNode();
            }
            t = t -> children[ch - 'a'];
            t -> inds.insert(ind);
        }
        
    }
    set<int> FindPrefs(TrieNode *t, string &w)
    {
        set<int>ans;
        for(auto &ch : w)
        {
            if(t -> children[ch - 'a'] == NULL)
            {
                return ans;
            }
            t = t -> children[ch - 'a'];
            // t -> inds.insert(ind);
        }
        return t -> inds;
    }
    long long countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        ll ans = 0;
        TrieNode t1, t2;
        for(int i = n - 1; i >= 0; i--)
        {
            // cout<<"i "<<i<<endl;
            string w = words[i];
            // search in t1 and collect indx
            set<int>is = FindPrefs(&t1, w);
            
            // search in t2 and collect indx
            string rw = w;
            reverse(rw.begin(), rw.end());
            set<int>js = FindPrefs(&t2, rw);
            // add intersection to ans
            ll cur = 0;
            for(auto &it : is)
            {
                if(js.find(it) != js.end() )
                {
                    // cout<<"it "<<it<<endl;
                    cur++;
                }
            }
            ans += cur;
            // insert w to t1 and rev_w to t2
            Insert(&t1, w, i); Insert(&t2, rw, i);            
        }
        // deleteTrie(&t1);deleteTrie(&t2);
        return ans;
    }
};
/*
Input:
["tt","av","tav","tt","t","v","va","tva","a","vvv","aa","ata","v","va","vt"]
Output:
7
Expected:
6
*/
