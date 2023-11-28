#include <iostream>

using namespace std;

int main() {
    int n, out;
    cout << "Enter month number: ";
    cin >> n;

    // if (n == 2) out = 28;
    // else if (n == 8) out = 31;
    // else if (n % 2 == 0) out = 30;
    // else out = 31;

    switch(n) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            out = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            out = 30;
            break;
        case 2:
            out = 28;
            break;
        default:
            cout << "Invalid input" << endl;
            // exit(0);
    }

    cout << "Number of days: " << out << "\n";
    return 0;
}
