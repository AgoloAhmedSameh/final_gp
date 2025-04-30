#include <vector>
using namespace std;

pair<int, int> frequency_Of_Smallest(int n, vector<int>& arr) { 
    int mn = arr[0]; 
    int freq = 1;
    for (int i = 1; i < n; i++) { 
        if (arr[i] < mn) { 
            mn = arr[i]; 
            freq = 1;
        } else if (arr[i] == mn) { 
            freq++;
        }
    }
    return {freq, mn};
}
