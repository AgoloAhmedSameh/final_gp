#include <iostream>

int main() {
    int level1, level2, level3, level4;

    std::cout << "Enter level1 choice (1-2): ";
    std::cin >> level1;

    switch (level1) {
        case 1: {
            std::cout << "Enter level2 choice (1-2): ";
            std::cin >> level2;

            switch (level2) {
                case 1: {
                    std::cout << "Enter level3 choice (1-2): ";
                    std::cin >> level3;

                    switch (level3) {
                        case 1: {
                            std::cout << "Enter level4 choice (1-2): ";
                            std::cin >> level4;

                            switch (level4) {
                                case 1: {
                                    std::cout << "Loop at level 4: ";
                                    for (int i = 0; i < 3; i++) {
                                        std::cout << i << " ";
                                    }
                                    std::cout << "\n";
                                    break;
                                }
                                case 2: {
                                    std::cout << "While loop at level 4:\n";
                                    int j = 0;
                                    while (j < 3) {
                                        std::cout << "Iteration " << j << "\n";
                                        j++;
                                    }
                                    break;
                                }
                                default: {
                                    std::cout << "Invalid choice at level 4\n";
                                }
                            }
                            break;
                        }
                        case 2: {
                            std::cout << "For loop at level 3: ";
                            for (int k = 5; k < 10; k++) {
                                std::cout << k << " ";
                            }
                            std::cout << "\n";
                            break;
                        }
                        default: {
                            std::cout << "Invalid choice at level 3\n";
                        }
                    }
                    break;
                }
                case 2: {
                    std::cout << "Do-while loop at level 2:\n";
                    int m = 0;
                    do {
                        std::cout << "Step " << m << "\n";
                        m++;
                    } while (m < 4);
                    break;
                }
                default: {
                    std::cout << "Invalid choice at level 2\n";
                }
            }
            break;
        }
        case 2: {
            std::cout << "While loop at level 1:\n";
            int n = 0;
            while (n < 3) {
                std::cout << "Cycle " << n << "\n";
                n++;
            }
            break;
        }
        default: {
            std::cout << "Invalid choice at level 1\n";
        }
    }

    return 0;
}
