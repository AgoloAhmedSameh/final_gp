int find_Min(vector<int>& arr, int low, int high) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == arr[high]) {
            high -= 1;
        } else if (arr[mid] > arr[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return arr[high];
}
