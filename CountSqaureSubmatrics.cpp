TC = O(n^3)
SC = O(n^2)

int solve(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size() ;
    int dp[n+1][m+1] ;
    for( int i = 0 ; i <=n ;i++){
        dp[i][0] = 0 ;
    }
    for( int j = 0 ; j <= m ;j++ ){
        dp[0][j] = 0 ;
    }
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + mat[i][j];
        }
    } 
    long long cnt = 0 ;
    for(int k = 1; k <= min(n,m); k++){
        int sq = k*k ; 
        for(int i = k ; i <= n; i++ ){
            for( int j = k ; j <= m ; j++ ){
                int val = (dp[i][j] - dp[i-k][j] - dp[i][j-k] + dp[i-k][j-k] ) ;
                cnt += ( val == sq ) ;
            }
        }    
    }

    return cnt ;
}