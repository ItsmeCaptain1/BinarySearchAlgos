#define ll long long

ll dp[251][251] ;
int n, c ;

int go(int i, int curr,vector<int>& w, vector<int>& val){
    if( i==n ){
        return 0 ;
    }
    if(dp[i][curr] != -1) return dp[i][curr] ; 
    int best = 0 ;
    if( curr >= w[i] ){
        best = val[i] + go(i+1,curr-w[i], w, val); 
    }
    best = max(best,go(i+1,curr, w, val) ) ; 
    return dp[i][curr]=best ;


}

int solve(vector<int>& w, vector<int>& val, int cost) {
    n = w.size(), c = cost ; 
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j <= c ; j++ ){
            dp[i][j] = -1 ;
        }
    }
    
    return go(0,cost,w,val) ;
}