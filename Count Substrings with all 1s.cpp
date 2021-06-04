const int mod = 1e9+7 ;
int solve(string s) {
    int n = s.size() ; 
    long long res = 0 ;
    for( int i = 0, j = 0 ; i < n ;  ){
        if( s[i] == '0' ) {
            i++ ; 
            continue ;
        }
        j = i ;
        while( s[i] == '1' ){
            i++ ; 
        }
        long long x = (i-j) ;
        res = (res + (x*(x+1))/2ll ) % mod ;
    }
    return res ;
}