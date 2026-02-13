# Assignment-1---The-Bohr-atom
The first assignment of object oriented programming in C++. It takes the initial and final quantum numbers, and the atomic number as inputs from the user, and outputs the transition energy in the units chosen by the user.
I began by making the input fields of the program and validating the input such that only valid data types and values are allowed. Depending on the input value in the unit field, the code decides on a conversion value that will correct the final output to the desired unit.
Then I added the calculation of photon energy, separated into its own function. The calculation is performed in natural units and then converted into Joules if required. Finally the photon is outputted for the user to read with correct corresponding unit.
