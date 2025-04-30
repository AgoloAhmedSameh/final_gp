int count_Unset_Bits(int n) {  
    int cnt = 0;  
    for (int i = 1; i <= n; i++) {  
        int temp = i;  
        while (temp) {  
            if (temp % 2 == 0) {  
                cnt++;  
            }  
            temp = temp / 2;  
        }  
    }  
    return cnt;  
}
