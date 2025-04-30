#include <cmath>

int get_Pos_Of_Right_most_Set_Bit(int n) { 
    return static_cast<int>(log2(n & -n) + 1);   
}

int set_Right_most_Unset_Bit(int n) { 
    if (n == 0) { 
        return 1; 
    }
    if ((n & (n + 1)) == 0) {     
        return n; 
    }
    int pos = get_Pos_Of_Right_most_Set_Bit(~n);      
    return ((1 << (pos - 1)) | n); 
}
