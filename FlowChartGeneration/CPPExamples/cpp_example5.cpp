int n, stopValue;
cout << "Enter the range and a stop value: ";
cin >> n >> stopValue;

for (int i = 1; i <= n; ++i) {
    if (i % 2 == 0) continue; // Skip even numbers
    cout << i << " ";
    if (i == stopValue) {
        cout << "\nStopping at " << stopValue << endl;
        break; // Stop the loop when the stop value is reached
    }
}

return 0;

