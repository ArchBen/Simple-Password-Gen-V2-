#include<iostream>
#include<cstdlib>

// Functions 
void GeneratePassword();
void GenerateUsername();
void Register();
void Login();

// Globals
std::string password = "";
std::string username = "";

int main() {
    // A console clear would be added but this is being programmed on an Android based Tablet :P

    int menuChoice = 0;

    std::cout << "Login System (Password Gen V2)\n";
    std::cout << "1. Register / Login\n";
    std::cout << "2. Generate a password (Password Gen V1)\n";
    std::cout << "3. Exit\n";
    std::cout << "Choice: ";
    std::cin >> menuChoice;

    switch (menuChoice) {
        case 1:
            Login();
        case 2:
            GeneratePassword();
        case 3:
            exit(0);
    }
}

void Register() {

    int rgstChoice = 0;

    std::cout << "Register\n";
    std::cout << "1. Generate Credentials\n";
    std::cout << "2. Enter your own Username and Password\n";
    std::cout << "Choice: ";
    std::cin >> rgstChoice;

    switch (rgstChoice) {
        case 1:
        {
            int gcChoice = 0;

            std::cout << "1. Generate a username\n";
            std::cout << "2. Generate a password\n";
            std::cin >> gcChoice;

            switch (gcChoice) {
                case 1:
                    GenerateUsername();
                case 2:
                    GeneratePassword();
            }
            break;
        } 
        case 2:
            std::cout << "Enter a username: ";
            std::cin >> username;
            std::cout << "Enter a password: ";
            std::cin >> password;

            Login();
    }
}

void Login() {

    int lgnChoice = 0;

    std::cout << "NOTE: Please ensure you have registered before logging in\n";

    std::cout << "Login / Register\n";
    std::cout << "1. Register\n";
    std::cout << "2. Login\n";
    std::cout << "3. Return to menu\n";
    std::cout << "4. Exit Program\n";
    std::cout << "Choice: ";
    std::cin >> lgnChoice;

    switch (lgnChoice) {
        case 1:
            Register();
        case 2:
        {
            std::string verifyUs = "";
            std::string verifyPsw = "";

            int attempts = 3;

            for (int i = 0; i < 3; i++) {
                std::cout << "Enter Username: ";
                std::cin >> verifyUs;
                std::cout << "Enter Password: ";
                std::cin >> verifyPsw;

                if (verifyUs == username && verifyPsw == password) {
                    std::cout << "You have successfully logged in :)";
                    exit(0);
                } else {
                    std::cout << "Your username or password is not correct, please try again\n";
                    std::cout << "You have " << (attempts - i) - 1<< " attempt(s) left\n";
                }

            }

            std::cout << "You attempted logging in unsuccessfully too many times, please try again later\n";
            exit(0);
        } 
        case 3:
            main();
        case 4:
            exit(0);
    }
}

void GenerateUsername() {
    //Rand Seed
    srand((unsigned) time(NULL));
    bool numbersB = false;
    bool speicialsB = false;

    char nCheck = 'y';
    char sCheck = 'y';

    std::string letters ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string numbers = "0123456789";
    std::string specials = "#£&_-@()=+':%/*,.$€[]{}<>^`;÷";
    username = "";

    int length = 0;
    int lettersL = letters.length();
    int numbersL = numbers.length();
    int specialsL = specials.length();

    std::cout << "Username Generator - Ben Archard\n";
    std::cout << "Please enter length of desired username: ";
    std::cin >> length;
    std::cout << "Do you wish to have numbers included (y/n): ";
    std::cin >> nCheck;
    std::cout << "Do you wish to have speicial chars included (y/n): ";
    std::cin >> sCheck;

    switch (nCheck) {
        case 'y':
            numbersB = true;
            break;
        case 'n':
            break;
    }

    switch (sCheck) {
        case 'y':
            speicialsB = true;
            break;
        case 'n':
            break;
    }

    for (int i = 0; i < length; i++) {
        if (username.length() >= length) {
            break;
        } else {
           switch (numbersB){
               case true:
                   username += numbers[0 + (std::rand() % numbersL)];
                   break;
               case false:
                   break;
            }
            if (username.length() >= length) {
               break;
            } else {
                   switch (speicialsB){
                        case true:
                           username += specials[0 + (std::rand() % specialsL)];
                           break;
                        case false:
                            break;
                    }
                    if (username.length() >= length) {
                       break;
                    } else {
                      username += letters[0 + (std::rand() % lettersL)];
                    } 
                } 

        }   
    }

    std::cout << "Your username is: "<< username << std::endl;

    int genpswChoice = 0;

    std::cout << "Options:\n";
    std::cout << "1. Generate new username\n";
    std::cout << "2. Enter login page\n";
    std::cout << "3. Return to main menu\n";
    std::cout << "4. Exit program\n";
    std::cout << "Choice: ";
    std::cin >> genpswChoice;

    switch (genpswChoice) {
        case 1:
            GeneratePassword();
        case 2:
            Login();
        case 3:
            main();
        case 4:
            exit(0);
    }
}

void GeneratePassword() {
    //Rand Seed
    srand((unsigned) time(NULL));
    bool numbersB = false;
    bool speicialsB = false;

    char nCheck = 'y';
    char sCheck = 'y';

    std::string letters ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string numbers = "0123456789";
    std::string specials = "#£&_-@()=+':%/*,.$€[]{}<>^`;÷";
    password = "";

    int length = 0;
    int lettersL = letters.length();
    int numbersL = numbers.length();
    int specialsL = specials.length();

    std::cout << "Password Generator - Ben Archard\n";
    std::cout << "Please enter length of desired password: ";
    std::cin >> length;
    std::cout << "Do you wish to have numbers included (y/n): ";
    std::cin >> nCheck;
    std::cout << "Do you wish to have speicial chars included (y/n): ";
    std::cin >> sCheck;

    switch (nCheck) {
        case 'y':
            numbersB = true;
            break;
        case 'n':
            break;
    }

    switch (sCheck) {
        case 'y':
            speicialsB = true;
            break;
        case 'n':
            break;
    }

    for (int i = 0; i < length; i++) {
        if (password.length() >= length) {
            break;
        } else {
           switch (numbersB){
               case true:
                   password += numbers[0 + (std::rand() % numbersL)];
                   break;
               case false:
                   break;
            }
            if (password.length() >= length) {
               break;
            } else {
                   switch (speicialsB){
                        case true:
                           password += specials[0 + (std::rand() % specialsL)];
                           break;
                        case false:
                            break;
                    }
                    if (password.length() >= length) {
                       break;
                    } else {
                      password += letters[0 + (std::rand() % lettersL)];
                    } 
                } 

        }   
    }

    std::cout << "Your password is: "<< password << std::endl;

    int genpswChoice = 0;

    std::cout << "Options:\n";
    std::cout << "1. Generate new password\n";
    std::cout << "2. Enter login page\n";
    std::cout << "3. Exit Program\n";
    std::cout << "Choice: ";
    std::cin >> genpswChoice;

    switch (genpswChoice) {
        case 1:
            GeneratePassword();
        case 2:
            Login();
        case 3:
            exit(0);
    }
}