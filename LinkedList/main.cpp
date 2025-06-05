#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Print welcome message
    cout << "Welcome to My C++ Program!" << endl;
    
    // Get user's name
    string name;
    cout << "Please enter your name: ";
    getline(cin, name);
    
    // Greet the user
    cout << "Hello, " << name << "! Welcome to the world of C++!" << endl;
    
    return 0;  // Return success status
}






