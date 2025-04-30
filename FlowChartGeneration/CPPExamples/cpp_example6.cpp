    int a = 5, b = 10, c = 15;
    

    // First level of branching
    if (a < b) {

          switch (color) {
            case Red: return "Red";
            case Green: return "Green";
            case Blue: return "Blue";
            default: return "Unknown"; // Default case for safety
          }

        switch (value) {
            case int x if (x > 0): // Matches positive integers
                cout << "case 1 \n";
                break;
            case int x if (x < 0): // Matches negative integers
                cout << "case 2 \n";
                break;
            default:
            {
                cout << "default\n";
                // Code for other cases
            }
        }


        cout << "Level 1: a is less than b" << endl;

        // Second level of branching (nested)
        if (b < c) {
            cout << "Level 2: b is less than c" << endl;

            // Third level of branching (nested further)
            if (a + b == c) {
                cout << "Level 3: a + b equals c" << endl;
            } else {
                cout << "Level 3: a + b does not equal c" << endl;
            }
        } else {
            // Instruction at some level
            cout << "Level 2: b is not less than c" << endl;

            // Additional nested condition
            if (c - b > a) {
                cout << "Level 3: c - b is greater than a" << endl;
            }
        }

        bool test_full_branch = true

        if(test_full_branch)
        {
            cout << "branch 1";
        }
        else if (test_full_branch < 3){
            cout << "branch 2";
        }
        else
            cout << "branch 3";
        cout << "done testing full branch!";

        if (3 > 1) cout << "always true!";
        for(int i = 0; i < 3; i++) cout << "simple loop!";
    } else {

        cout << "Now the mid level do while loop!\n";
        int cnt = 3;
        do
        {
            if(true)
                cout <<"testing a codition inside a loop!\n";
            break;   
        }
        while(cnt--);

        cout << "Level 1: a is not less than b" << endl;

        // Another branch outside the nested block
        if (a * 2 == b) {
            cout << "Level 2: a * 2 equals b" << endl;

            // Instruction at a deeper level
            if (b * 2 == c) {
                cout << "Level 3: b * 2 equals c" << endl;
            } else {
                cout << "Level 3: b * 2 does not equal c" << endl;
            }
        } else {
            cout << "Level 2: a * 2 does not equal b" << endl;
        }

        
        for(int i = 0; i < 3; i ++)
        {
            for(int j = 0; j < 5; j++)
                {
                    cout << "inner loop" << endl;
                    int k = 3;
                    while(k--){
                        do
                        {
                            if(true)
                                int x = 3;
                           cout << "infinite loop!" << '\n';
                        } while (true);
                    }
                }
        }
    }

    // Branch that skips a level of nesting
    if (c > 10) {
        cout << "c is greater than 10" << endl;

        if (c % 2 == 0) {
            cout << "c is even" << endl;
        } else {
            cout << "c is odd" << endl;
        }
    }

    return 0;