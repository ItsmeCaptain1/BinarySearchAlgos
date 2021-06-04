int partition( vector<int>& a, int l, int r){
    int pivot = a[l], j = r ; 
    for( int i = l+1; i <= j ; ){
        if( pivot <= a[i] ){
            swap(a[i], a[j--]) ;
        }else{
            i++ ;
        }
    }
    swap(a[l],a[j]) ; 
    return j ;
}

int solve(vector<int>& nums, int k) {
    int l = 0, r = nums.size()-1 ; 
    while( l < r ){
        int m = partition(nums,l, r) ;
        if(m ==k ){
            return nums[m] ;
        } 
        if( m < k ){
            l = m+1 ; 
        }else{
            r = m-1 ;
        }

    }    
    return nums[l] ;
}