# 🔐 Password Manager (C++ Project)

A simple, beginner-friendly **C++ Password Manager** that lets you:
- Add and store new passwords
- View saved passwords
- Search passwords by site
- Keep your credentials in one place (locally stored)

> ⚙️ Built as a console-based project using basic C++ file handling and string manipulation.

---

## 🛠 Features

- ➕ Add new credentials (Site, Username, Password)
- 📂 View all saved passwords
- 🔍 Search passwords by site name
- 💾 Stores data in a local `.txt` file
- 🧼 Clean, menu-based user interface
- 🔒 `.gitignore` protects sensitive files (like `passwords.txt`)

---

## 📁 How It Works

- When you add a password, it saves it in a `passwords.txt` file
- Each entry is stored as:

Site,Username,Password
- You can view or search these anytime from the menu

---

## 🚀 How to Run

1. Clone this repo:
 ```bash
 git clone https://github.com/yourusername/PasswordManager.git
 cd PasswordManager

2. Compile the code: 
g++ main.cpp -o passwordmanager

3. Run the program:
./passwordmanager


Concepts Used
C++ File I/O (fstream)
String operations (getline, substr, find)
Menu loops and user input handling
Data persistence through text files


🧑‍💻 Author
Your Name – surabhi03


Star This Repo
If you found it useful, consider giving it a ⭐️ on GitHub!