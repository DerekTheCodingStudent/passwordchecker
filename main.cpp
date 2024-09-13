#include <iostream>
#include <string>

using std::cout, std::cin, std::string;

void requirements() {
    cout << "The requirements to the password should be:\n";
    cout << "Has atleast 8 characters but less than or equal to 30 characters.\n";
    cout << "Contains both lower and upper case letters.\n";
    cout << "Contains atleast 1 number.\n";
    cout << "Contains 1 special character such as: !@#$%^&*()+\"\n";
    cout << "Does not contain any sequences such as: 'abc' or '123'\n";
}


int main(int argc, char* argv[]) {
    string input = "";

    requirements();

    cout << "\nPlease input your password that follows the requirements: ";
    cin >> input;

    int length = input.length();

    if(length < 8 || length > 30) {
        cout << "You didn't follow the length requirement!\n";
        return 1;
    }

    bool hasLowerLetter = false;
    bool hasUpperLetter = false;
    bool hasNumber = false;
    bool hasSpecialCharacter = false;
    for(int i = 0; i < length; i++) {
        if(input[i] >= 65 || input[i] <= 90) hasUpperLetter = true;
        if(input[i] >= 97 || input[i] <= 122) hasLowerLetter = true;
        
        if(input[i] >= 48 || input[i] <= 57) hasNumber = true;

        if(input[i] == 33 || input[i] == 64 || (input[i] >= 35 && input[i] <= 43) || input[i] == 94) hasSpecialCharacter = true;


        if(hasUpperLetter == true && hasLowerLetter == true && hasNumber == true && hasSpecialCharacter == true) break;
    }

    if(hasLowerLetter == false || hasUpperLetter == false) {
        cout << "You didn't follow the lower and upper case requirement!\n";
        return 2;
    }

    if(hasNumber == false) {
        cout << "You didn't follow the number requirement!\n";
        return 3;
    }

    if(hasSpecialCharacter == false) {
        cout << "You didn't follow the special character requirement!\n";
        return 4;
    }

    bool isSequence = false;
    for(int i = 0; i < length-1; i++) {
        if(input[i]-'0' == input[i]+1-'0') {
            isSequence = true;
            break;
        }
    }

    if(isSequence == false) {
        cout << "You didn't follow the sequence requirement!\n";
        return 5;
    }

    cout << "Congrats! This is a valid password! " << input << "\n";

    return 0;
}