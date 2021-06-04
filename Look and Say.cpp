string solve(int n) {
    vector<int> temp ; 
    temp.push_back(1) ; 
    vector<int> z ; 
    for( int j = 1 ; j < n ; j++  ){
        
        for( int i = 0 ; i < temp.size() ; ){
            int cnt = 1 ;
            int last = temp[i++] ;
            
            while( i < temp.size() && last == temp[i] ){
                i++ ;
                cnt++ ;
            } 
            z.push_back(cnt) ;
            z.push_back(last) ; 
            
        }
        temp = z ;
        z.clear() ;

    }
    string s ; 
    for( auto x : temp ){
        s += (x+'0') ;
    }
    return s ;
}