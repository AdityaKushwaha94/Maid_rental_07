
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {
public:
    string username;
    string password;
    string phone_number;
    string id_proof;
    double num;

    void registerUser() {
        cout << "Enter a username: ";
        cin >> username;
        cout << "\nEnter a password: ";
        cin >> password;
        cout << "\nenter your phone no. or email address which you want to register " << endl;
        cin >> phone_number;
        cout << "\nID VERIFICATION" << endl;
        cout << "\nenter your any id card number of that card\n";
        cout << "\nexample::adhar card\npan card\nvoting card\nrasan card\n";
        cout << "\nenter your card number\n";
        cin >> id_proof;
        cout << "\n\n\t\tyou register yourself succesfully::" << endl;
    }

    static bool loginUser(const vector<User>& users, string& loggedInUser) {
        string username, password;
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        for (const User& user : users) {
            if (user.username == username && user.password == password) {
                loggedInUser = username;
                return true;
            }
        }
        return false;
    }
};

class Booking {
public:
    string username;
    string servicetype;
    char option1, option2, option3, option4;

    void bookService(const string& loggedInUser) {
        username = loggedInUser;
        cout << "want Cooking?" << endl;
        cout << "want Cleaning?" << endl;
        cout << "want PetCare?" << endl;
        cout << "want Caring?" << endl;
        cin >> servicetype;
        if (servicetype == "cooking" || servicetype == "Cooking" || servicetype == "COOKING") {
            cout << "prize will be 200 for lunch" << endl << "prize will be 250 for dinner" << endl;
            cout << "For Lunch Press 'L'\nFor Dinner Press 'D'\n";
            cin >> option1;
            if (option1 == 'L' || option1 == 'l') {
                cout << "Booking Item = Lunch !!!!\nBooking Amount = Rs 200/- ";
                cout << "\t\t\nBooking successful!\n";
            }
            else if (option1 == 'D' || option1 == 'd') {
                cout << "Booking Item = Dinner !!!!\nBooking Amount = Rs 250/- ";
                cout << "\t\t\nBooking successful!\n";
            }
            else {
                cout << "Invalid Input! , Either Press 'L' or 'D' , Try Again ";
            }
        }
        else if (servicetype == "cleaning" || servicetype == "Cleaning" || servicetype == "CLEANING") {
            cout << "prize will be 300 for Dry Cleaning" << endl << "prize will be 400 for House Cleaning" << endl;
            cout << "For Dry Cleaning Press 'D'\nFor House Cleaning Press 'H'\n";
            cin >> option2;
            if (option2 == 'D' || option2 == 'd') {
                cout << "Booking Item = Dry Cleaning !!!!\nBooking Amount = Rs 300/- ";
                cout << "\t\t\nBooking successful!\n";
            }
            else if (option2 == 'H' || option2 == 'h') {
                cout << "Booking Item = House Cleaning !!!!\nBooking Amount = Rs 400/- ";
                cout << "\t\t\nBooking successful!\n";
            }
            else {
                cout << "Invalid Input! , Either Press 'D' or 'H' , Try Again ";
            }
        }
        else if (servicetype == "petcare" || servicetype == "PetCare" || servicetype == "PETCARE") {
            cout << "prize will be 250 for Pet Caring" << endl;
            cout << "\t To Continue Press 'Y' \n\t For Exit Press 'N'\n";
            cin >> option3;
            if (option3 == 'Y' || option3 == 'y') {
                cout << "Booking Item = Pet Care !!!!\nBooking Amount = Rs 250/- ";
                cout << "\t\t\nBooking successful!\n";
            }
            else if (option3 == 'N' || option3 == 'n') {
                exit(0);
            }
            else {
                cout << "Invalid Input! , Either Press 'Y' or 'N' , Try Again ";
            }
        }
        else if (servicetype == "caring" || servicetype == "Caring" || servicetype == "CARING") {
            cout << "prize will be 400 for Baby Sitting , Press 'B'" << endl;
            cout << "prize will be 500 for Edarly Care , Press 'E'\n";
            cin >> option4;
            if (option4 == 'B' || option4 == 'b') {
                cout << "Booking Item = Baby Sitting !!!!\nBooking Amount = Rs 400/- ";
                cout << "\t\t\nBooking successful!\n";
            }
            else if (option4 == 'E' || option4 == 'e') {
                cout << "Booking Item = Edarly Care !!!!\nBooking Amount = Rs 500/- ";
                cout << "\t\t\nBooking successful!\n";
            }
            else {
                cout << "Invalid Input! , Either Press 'B' or 'E' , Try Again ";
            }
        }
        else {
            cout << "Please Enter Valid Input !!!!";
        }
    }

};

int main() {
    vector<User> users;
    vector<Booking> bookings;
    string loggedInUser;
    int choice;
    do {
        cout << "1. Register\n2. Login\n3. Book Service\n4.look price template\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            User newUser;
            newUser.registerUser();
            users.push_back(newUser);
            break;
        }
        case 2: {
            if (User::loginUser(users, loggedInUser)) {
                cout << "Login successful. Welcome, " << loggedInUser << "!\n";
            }
            else {
                cout << "Login failed. Invalid credentials.\n";
            }
            break;
        }
        case 3: {
            Booking newBooking;
            if (!

loggedInUser.empty()) {
                newBooking.bookService(loggedInUser);
                bookings.push_back(newBooking);
            }
            else {
                cout << "Please log in first.\n";
            }
            break;
        }
        case 4: {
            cout << "-> Cooking = 200/day\n";
            cout << "-> Cleaning = 300/day\n";
            cout << "-> Pet Care = 250/day\n";
            cout << "-> Ederly Care / Baby Sitting  = 400/day\n";
            break;
        }
        case 5:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}