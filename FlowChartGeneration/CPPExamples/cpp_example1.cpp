int rows 3, yy = 5;

cout << "Enter the number of rows for the pattern (1-10): ";
cin >> rows;

if (rows < 1 || rows > 10) {
    cout << "Invalid input. Please enter a number between 1 and 10." << endl;
} else {
    cout << "Pattern:" << endl;

    // Outer loop for rows
    for (int i = 1; i <= rows; i++) {
        // Inner loop for printing stars
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    cout << "\nNow printing a reverse pattern:" << endl;

    // Nested loop for reverse pattern
    for (int i = rows; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }


    for(int i = 0; i < 4; i++) cout << "I love number 4" ;

    int t = 5;

    do{
        cout << t << endl;
    }while(t--);
}

return 0;

