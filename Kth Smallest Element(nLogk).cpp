int solve(vector<int>& nums, int k) {
    priority_queue<int> q ; 
    for( auto x : nums ){
        q.push(x) ; 
        if( q.size() > k+1 ){
            q.pop(); 
        }
    }
    return q.top() ;
}