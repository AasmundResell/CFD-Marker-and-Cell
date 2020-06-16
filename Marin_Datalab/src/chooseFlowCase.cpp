#include "header.h"

using namespace std;

int choice()
{
    int choice = 0;
    cout << "Choose one of the following situations: " << endl;
    cout << "Type 1 for Cavity box" << endl;
    cout << "Type 2 for flow over box" << endl;
    cout << "Type 3 for flow over plate" << endl;
    cin >> choice;
    return choice;
}
