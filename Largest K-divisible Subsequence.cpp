int solve(vector<int>& nums, int k) {
    int n = nums.size() ; 
    // pair<int,int> dp[n+1][k+1] ; 
    int dp[2][k] ; 
    for( int i = 0 ; i < 2 ; i++ ){
        for( int j = 0 ; j < k ; j++ ){
            dp[i][j] = 0 ;
        }
    }
    int last = 0 ; 
    vector<int> active(k) ; 
    active[0] = 1 ;
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < k ; j++ ){
            if( active[j] ){
                int x = (j+nums[i])%k ;
                dp[1][x] = max(dp[0][j] + nums[i], dp[1][x]) ;
            }
                
        }
        for( int j = 0 ; j < k ; j++ ){
            dp[0][j] = dp[1][j] ;
            if( dp[0][j] ){
                active[j] = 1;
            } 
        } 
    }
    return dp[0][0] ;

}