bool does_Contain_B(int a, int b, int c) { 
    if (a == b) { 
        return true; 
    } 
    if ((b - a) * c > 0 && (b - a) % c == 0) { 
        return true; 
    } 
    return false; 
}
