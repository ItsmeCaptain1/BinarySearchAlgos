#define ll long long

ll dp[251][251] ;

int solve(vector<int>& w, vector<int>& val, int c) {
    int n = w.size() ; 
    
    for( int i = n ; i >= 0 ; i-- ){
        for( int j = 0 ; j <= c ; j++ ){
            dp[i][j] = 0 ;
        }
    }
    ll best = 0 ;
    for( int i = n-1 ; i >= 0 ; i-- ){
        
        for( int j = 0 ; j <= c ; j++ ){
            if( j >= w[i] ){
                dp[i][j] = max(dp[i+1][j-w[i]]+val[i], dp[i+1][j] ) ;
            }
            else{
                dp[i][j] = dp[i+1][j] ;
            }
            best = max(best,dp[i][j]) ; 
        }
    }
    
    return best ;
}