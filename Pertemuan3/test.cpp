#include <iostream>
using namespace std;

int main() {
    double month1, month2, MoM;

    // Ask for input
    cout << "Enter value for Month 1: ";
    cin >> month1;

    cout << "Enter value for Month 2: ";
    cin >> month2;

    // Calculate Month-over-Month change
    MoM = ((month2 - month1) / month1) * 100;

    // Display result
    cout << "The Month-over-Month (MoM) change is " << MoM << "%" << endl;

    return 0;
}
