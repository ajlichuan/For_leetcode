class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int S = (C-A)*(D-B) + (G-E)*(H-F);
        
        if(B > H || F > D || E > C || A > G)
            return S;
        
        int l1 = min(C,G) - max(A,E);
        int l2 = min(D,H) - max(B,F);
        
        return S - l1*l2;
    }
};