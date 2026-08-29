class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0];
        int sc = source[1];

        int tr = target[0];
        int tc = target[1];

        if((sr + sc) % 2 != (tr + tc) % 2){
            return -1;
        }   
        if(abs(tr - sr) == abs(tc - sc))
            return 1;

        else return 2;
    }
};