#include <iostream>
using namespace std;

pair<double, double> cal_electbill(int units) {
    double amount, surcharge;
    if (units < 50) {
        amount = units * 2.60;
        surcharge = 25;
    } else if (units <= 100) {
        amount = 130 + ((units - 50) * 3.25);
        surcharge = 35;
    } else if (units <= 200) {
        amount = 130 + 162.50 + ((units - 100) * 5.26);
        surcharge = 45;
    } else {
        amount = 130 + 162.50 + 526 + ((units - 200) * 8.45);
        surcharge = 75;
    }
    double total = amount + surcharge;
    return make_pair(total, surcharge);
}
