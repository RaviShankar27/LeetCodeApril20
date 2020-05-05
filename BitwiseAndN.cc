class Solution {
public:
    /*int rangeBitwiseAnd(int m, int n) {
        unsigned int range_start =  m;
        for (int index = m+1; index <= n; ++index) {
            range_start &= index;
        }
        return range_start;
    }*/
    
     int getMSBIndex(int m) {
        int count = 0;
        while (m) {
            ++count;
            m = m >> 1;
        }
        return count;
    }
    
    int rangeBitwiseAnd(int m, int n) {
        
        if (m==n) return m;
        
        int result = 0;
        while(m > 0 && n > 0) {
            int msb_index_1 = getMSBIndex(m);
            int msb_index_2 = getMSBIndex(n);
            if (msb_index_1 == msb_index_2 && msb_index_1 != 0) {
                result += 1 << (msb_index_1-1);
                m = m - (1 << (msb_index_1-1));
                n = n - (1 << (msb_index_2-1));
            }
            else if (msb_index_2 > msb_index_1) {
                return result;
            }
        }
        return result;
    }  
    
};