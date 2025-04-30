bool is_triangleexists(int a, int b, int c) { 
    if (a != 0 && b != 0 && c != 0 && (a + b + c) == 180) { 
        if ((a + b) >= c || (b + c) >= a || (a + c) >= b) { 
            return true; 
        } else { 
            return false; 
        } 
    } else { 
        return false; 
    } 
}
