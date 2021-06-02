const int Mxn = 101 ; 
int dp[Mxn][Mxn][Mxn] ;  
int x, y, z  ;

string A,B,C ;

int LCS(int i = 0, int j = 0, int k = 0){
    if( i == x || j == y || k == z ){
        return 0 ; 
    }
    if(dp[i][j][k] != -1 )return dp[i][j][k] ; 
    int best = 0 ;
    if( A[i] == B[j] && B[j] == C[k] ){
        best = 1+LCS(i+1,j+1,k+1) ;
    }
    best = max(best,max(LCS(i+1,j,k),max(LCS(i,j+1,k),LCS(i,j,k+1)))) ;
    best = max(best,max(LCS(i+1,j,k+1),max(LCS(i+1,j+1,k),LCS(i,j+1,k+1)))) ;
    return dp[i][j][k] = best ;
}

int solve(string a, string b, string c) {
    x = a.size(), y = b.size(), z = c.size() ;
    A = a, B = b, C = c ; 
    for(int i = 0 ; i < x ; i++ ){
        for( int j = 0 ; j < y ; j++){
            for( int k = 0 ; k < z ; k++ ){
                dp[i][j][k] = -1 ;
            }
        }
    }
    return LCS() ;
}