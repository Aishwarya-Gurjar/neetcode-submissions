class DisjointSetUnion {
    public:
        vector<int>parent;
        vector<int>size;
        int findParent(int x) {
            if(parent[x]==x)    return x;
            return parent[x]=findParent(parent[x]);
        }

        void unionParent(int x, int y){
            int par_x = findParent(x);
            int par_y = findParent(y);

            if(par_x==par_y)    return;

            if(size[par_x]<size[par_y]) {
                parent[x]=y;
                size[par_y]+=size[par_x];
            }else {
                parent[y]=x;
                size[par_x]+=size[par_y];
            }
        }

        DisjointSetUnion(int n) {
            parent.resize(n+1);
            size.resize(n+1,1);

            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        if(n<=1)    return n;
        DisjointSetUnion dsu(n);

        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end())  continue;

            mp[nums[i]]=i;
            if(mp.find(nums[i]-1)!=mp.end()){
                dsu.unionParent(i, mp[nums[i]-1]);
            }
            if(mp.find(nums[i]+1)!=mp.end()){
                dsu.unionParent(i, mp[nums[i]+1]);
            }
        }

        int max_size=INT_MIN;
        for(int i=0;i<n;i++){
            if(i==dsu.findParent(i)){
                max_size=max(max_size,dsu.size[i]);
            }
        }
        return max_size;
    }
};
