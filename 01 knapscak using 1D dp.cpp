#define ll long long

ll dp[251] ;

int solve(vector<int>& w, vector<int>& val, int c) {
    int n = w.size() ; 
    
    for( int j = 0 ; j <= c ; j++ ){
        dp[j] = 0 ;
    }
    ll best = 0 ;
    for( int i = n-1 ; i >= 0 ; i-- ){
        
        for( int j = c ; j >= w[i] ; j-- ){
            if( j >= w[i] ){
                dp[j] = max(dp[j-w[i]]+val[i], dp[j] ) ;
            }
            best = max(best,dp[j]) ; 
        }
    }
    
    return best ;
}