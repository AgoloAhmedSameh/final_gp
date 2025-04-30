#include <vector>
using namespace std;

int min_Num(vector<int>& arr, int n) {  
    int odd = 0; 
    for (int i = 0; i < n; i++) { 
        if (arr[i] % 2) { 
            odd++; 
        } 
    } 
    if (odd % 2) { 
        return 1; 
    } 
    return 2; 
}
