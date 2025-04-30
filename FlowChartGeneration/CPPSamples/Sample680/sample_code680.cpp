int smallest_Divisor(int n) { 
    if (n % 2 == 0) { 
        return 2; 
    } 
    int i = 3;  
    while (i * i <= n) { 
        if (n % i == 0) { 
            return i; 
        } 
        i += 2; 
    } 
    return n; 
}
