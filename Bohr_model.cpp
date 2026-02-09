#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

double calc_energy(int Z, int n_i, int n_f, double conv) {
    //Calculates photon energy
    return fabs(conv * 13.6 * pow(Z,2) * (1/(pow(n_f,2)) - 1/(pow(n_i,2)))) ;
}

int main() {
    // Initialise variables
    int Z;
    int n_initial;
    int n_final;
    char unit;
    double conv;
    bool evs_unit;
    char repeat;

    // Code repeats until user stops the process 
    while(true){
        // Ask for input parameters
        cout << "Enter the atomic number (Z) of the atom." << endl;

        // While loop takes for input and checks validity, only breaks loop upon valid input
        while(true) {
            cin >> Z;
            // Checks for invalid data types including floats
            if (cin.fail() || cin.peek() == '.') {
                // Clears invalid input and asks for new input
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Invalid input, please enter integer value." << endl;
            }

            else if(Z <= 0){
            // Asks for new input if Z =< 0
                cout << "Invalid Z value, please enter valid integer."  << endl;
            }

            else{
            // Breaks loop if input is valid
                break;
            }
        }

        cout << "Enter the principle quantum numbers (n) of the intial and final energy levels."<< endl;
         while(true) {
            cin >> n_initial >> n_final;
            // Checks for invalid inputs including floats
            if (cin.fail() || cin.peek() == '.') {
                // Clears invalid input and asks for new input
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                // Asks for new valid inputs
                cout << "Invalid input, please enter integer values." << endl;
            }

            else if( n_initial < n_final){
             // Checks for n_initial < n_final
             cout << "n_initial < n_final. Invalid input, please try again." << endl;
            }

            else if(n_initial <= 0 || n_final <= 0){
                cout << "Invalid value. Please try again" << endl;
            }

            else{
             // Breaks while loop if input is valid
                break;
            }
        }
        cout << "Would you like energy in units of Joules or electronvolts? [J/E]" << endl;
        // Checks input for desired energy unit. Sets conversion value based on input.
        // Also determines which unit is displayed at in the answer output.
        while (true) {
            cin >> unit;
            if (toupper(unit) == 'E'){
                conv = 1;
                evs_unit = true;
            break;
            }

            else if (toupper(unit) == 'J'){
                conv = 1.602176e-19;
                evs_unit = false;
                break;
            }

            else{
                cout << "Your input was invalid. Please input J or E for desired unit." << endl;
            }
        }
        // Calculate and display photon energy
        double Energy = calc_energy(Z, n_initial, n_final, conv);
        cout << "The photon energy released by an electron transition from state n = "
         << n_initial << " to n = " << n_final << " is " << Energy;
         // Prints correct unit
             if(evs_unit == true){
              cout << " eV" << endl;
            } 

            else{
             cout << " J" << endl;
            }

        // Asks if user wants to do another calculation
        cout << "Would you like to perform another calculation? [Y/N]" << endl;
        while(true){
            cin >> repeat;
            if (toupper(repeat) == 'Y'){
                break;
            }

            else if (toupper(repeat) == 'N'){
                return 0;
            }

            else{
                cout << "Invalid input. Please try again." << endl;
            }
        }
    }
}
