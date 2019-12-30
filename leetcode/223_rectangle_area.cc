C++
```
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (A >= G || E >= C || B >= H || F >= D)
            return computeArea(A, B, C, D) + computeArea(E, F, G, H);
        
        int I = max(A, E);
        int J = max(B, F);
        int K = min(C, G);
        int L = min(D, H);
        
        return computeArea(A, B, C, D) 
               - computeArea(I, J, K, L)
               + computeArea(E, F, G, H);
    }
    
private:
    inline int computeArea(int ld_x, int ld_y, int ru_x, int ru_y) {
        return (ru_x - ld_x) * (ru_y - ld_y);
    }
};
```

