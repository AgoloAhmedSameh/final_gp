bool is_Power_Of_Two(int x) { 
    return x && !(x & (x - 1)); 
}

bool differ_At_One_Bit_Pos(int a, int b) { 
    return is_Power_Of_Two(a ^ b); 
}
