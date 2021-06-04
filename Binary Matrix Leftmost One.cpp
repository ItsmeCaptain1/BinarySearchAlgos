int solve(vector<vector<int>>& mat) {
    int n = mat.size() ;
    if( n == 0 ) return -1 ;
    int m = mat[0].size() ; 
    int ans = m ; 
    for( int i = 0 ; i < n ; i++ ){
        int l = 0, r = m-1 ; 
        while( l <= r ){
            int mid = (l+r)/2 ; 
            if( mat[i][mid] == 1 ){
                ans = min(mid,ans) ; 
                r = mid-1 ;
            }
            else{
                l = mid+1 ;
                if( mat[i][l] == 1 ) ans = min(l,ans) ;
            }
        }
    }
    return ans==m ? -1 : ans  ;
}