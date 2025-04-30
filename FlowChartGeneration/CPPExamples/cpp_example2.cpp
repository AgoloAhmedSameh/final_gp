int start, end;
    cout << "Enter start and end of range: ";
    cin >> start >> end;

    cout << "Prime numbers: ";
    for (int i = start; i <= end; ++i) {
        bool isPrime = true;
        if (i < 2) isPrime = false;
        for (int j = 2; j * j <= i && isPrime; ++j) {
            if (i % j == 0) isPrime = false;
        }
        if (isPrime) cout << i << " ";
    }
    cout << endl;

    return 0;