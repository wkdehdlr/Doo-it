
#include <algorithm>


int solution(vector<int> &A) {
    int N = A.size();
    sort(A.begin(), A.end());\
    auto it = lower_bound(A.begin(), A.end(), 1);
    if(it == A.end())return 1;
    if(A[it-A.begin()]>1)return 1;
    
    for(int i=it-A.begin();i<N-1;++i){
        if(A[i]==A[i+1] || A[i]+1 == A[i+1])continue;
        else{
            return A[i]+1;
        }
    }
    return A[N-1]+1;
}
