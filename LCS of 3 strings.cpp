int solve(string a, string b, string c) {
    int x = a.size(), y = b.size(), z = c.size() ;
    int dp[x+1][y+1][z+1];
    memset(dp,0,sizeof(dp)) ;
    for(int i = x-1 ; i >= 0 ;i-- ){
        for( int j = y-1 ; j>=0 ; j--){
            for( int k = z-1 ; k>=0 ; k--){
                if(a[i]==b[j]&&b[j] == c[k]){
                    dp[i][j][k] = 1 + dp[i+1][j+1][k+1] ;
                }
                dp[i][j][k] = max(max(dp[i+1][j][k],max(dp[i][j+1][k],dp[i][j][k+1])),dp[i][j][k]) ;
                dp[i][j][k] = max(max(dp[i+1][j][k+1],max(dp[i+1][j+1][k],dp[i][j+1][k+1])),dp[i][j][k]) ;
            }
        }
    }
    return dp[0][0][0] ;