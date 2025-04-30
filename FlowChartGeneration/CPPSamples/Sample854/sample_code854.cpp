bool check_Even_Parity(int x) { 
    int parity = 0; 
    while (x != 0) { 
        x = x & (x - 1); 
        parity += 1; 
    } 
    return (parity % 2 == 0); 
}
