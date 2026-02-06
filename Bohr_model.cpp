#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
int main() {
    // Initialise variables
    int Z;
    int n_initial;
    int n_final;
    char unit;
    // Ask for inputs
    cout << "Enter the atomic number (Z) of the atom." << endl;
    cin >> Z;
    while(true) {
        // Checks for invalid input including floats
        if (cin.fail() || cin.peek() == '.') {
            // Clears invalid input and asks for new input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input, please enter integer value." << endl;
            cin >> Z;
        }
        else if(Z == 0){
            // Ends program if Z = 0
            cout << "Invalid Z value.";
            return 0;
        }
        else{
            // Breaks loop if input is valid
            break;
        }
    }
    cout << "Enter the principle quantum numbers (n) of the intial and final energy levels."<< endl;
    cin >> n_initial >> n_final;
        while(true) {
        // Checks for invalid inputs including floats
        if (cin.fail() || cin.peek() == '.') {
            // Clears invalid input and asks for new input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            // Asks for new valid inputs
            cout << "Invalid input, please enter integer values." << endl;
            cin >> n_initial >> n_final;
        }
        else if( n_initial < n_final){
            // Checks for n_initial < n_final
            cout << "n_initial < n_final. Invalid input, please try again." << endl;
            cin >> n_initial >> n_final;
        }
        else{
            // Breaks while loop if input is valid
            break;
        }
    }
    cout << "Would you like energy in units of Joules or electronvolts? [J/E]" << endl;
    cin >> unit;
    bool valid_unit = false;
    // Checks value of unit for desired energy unit. Sets conversion value based on input.
    while (valid_unit == false) {
        if (toupper(unit) == 'E'){
           int conv = 1;
           valid_unit = true;
        }
        else if (toupper(unit) == 'J'){
            double conv = 2.5;
            valid_unit = true;
        }
        else{
            cout << "Your input was invalid. Please input J or E for desired unit." << endl;
            cin >> unit;
        }
    }
    return 0;
}