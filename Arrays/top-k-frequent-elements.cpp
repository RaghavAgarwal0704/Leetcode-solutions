vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto a:nums){
           m[a]++;
        }
        priority_queue<pi,vector<pi>,greater<pi>>q;
        for(auto a:m){
            q.push({a.second,a.first});
            if(q.size()>k)q.pop();
        }
        vector<int>vec;
        while(q.size()){
            vec.push_back(q.top().second);q.pop();
        }
        return vec;
    }
