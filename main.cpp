#include <iostream>
#include <fstream>  // <-- Add this for file handling
using namespace std;

void showMenu() {
    cout << "\n===== Password Manager Menu =====\n";
    cout << "1. Add New Password\n";
    cout << "2. View Saved Passwords\n";
    cout << "3. Exit\n";
    cout << "4. Search Password by Site\n";
    cout << "Enter your choice: ";
}


void addPassword() {
    string site, username, password;

    cout << "\n🔐 Add New Password\n";
    cin.ignore();  // Clear leftover newline character

    cout << "Enter site name: ";
    getline(cin, site);

    cout << "Enter username/email: ";
    getline(cin, username);

    cout << "Enter password: ";
    getline(cin, password);

    // Save to file
    ofstream file("passwords.txt", ios::app); // Append mode
    if (file.is_open()) {
        file << site << "," << username << "," << password << "\n";
        file.close();
        cout << "✅ Password saved successfully!\n";
    } else {
        cout << "❌ Error: Could not open file to save password.\n";
    }
cout << "Press Enter to continue...";
cin.ignore();
cin.get();

}

void viewPasswords() {
    ifstream file("passwords.txt");
    string line;

    cout << "\n📂 Saved Passwords:\n";

    if (file.is_open()) {
        int count = 0;
        while (getline(file, line)) {
            count++;
            size_t pos1 = line.find(',');
            size_t pos2 = line.rfind(',');

            string site = line.substr(0, pos1);
            string username = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string password = line.substr(pos2 + 1);

            cout << count << ". " << site << "\n";
            cout << "   👤 " << username << "\n";
            cout << "   🔑 " << password << "\n\n";
        }
        file.close();

        if (count == 0) {
            cout << "⚠️ No saved passwords found.\n";
        }
    } else {
        cout << "❌ Error: Could not open file.\n";
    }
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();

}
void searchPassword() {
    ifstream file("passwords.txt");
    string line, keyword;
    bool found = false;

    cout << "\n🔍 Search Password by Site\n";
    cin.ignore(); // Clear buffer
    cout << "Enter site name to search: ";
    getline(cin, keyword);

    if (file.is_open()) {
        int count = 0;
        while (getline(file, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.rfind(',');

            string site = line.substr(0, pos1);
            string username = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string password = line.substr(pos2 + 1);

            if (site.find(keyword) != string::npos) {
                count++;
                found = true;
                cout << count << ". " << site << "\n";
                cout << "   👤 " << username << "\n";
                cout << "   🔑 " << password << "\n\n";
            }
        }
        file.close();

        if (!found) {
            cout << "❌ No passwords found for that site.\n";
        }
    } else {
        cout << "❌ Error: Could not open file.\n";
    }

    cout << "Press Enter to continue...";
    cin.get();
}


int main() {
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

if (choice == 1) {
    addPassword();
} else if (choice == 2) {
    viewPasswords();
} else if (choice == 3) {
    cout << "👋 Exiting... Goodbye!\n";
    break;
} else if (choice == 4) {
    searchPassword();
} else {
    cout << "❌ Invalid choice. Please try again.\n";
}

    }

    return 0;
}
