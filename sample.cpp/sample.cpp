#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
};

void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);

    cout << "Enter ID: ";
    cin >> s.id;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);

    file << s.id << "," << s.name << endl;

    file.close();
    cout << "Student Added Successfully!\n";
}

void displayStudents() {
    ifstream file("students.txt");
    string line;

    cout << "\nStudent Records:\n";

    while(getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void deleteStudent() {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    string line;

    while(getline(file, line)) {
        int pos = line.find(",");
        int currentId = stoi(line.substr(0, pos));

        if(currentId != id)
            temp << line << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    cout << "Record Deleted!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                cout << "Thank You!\n";
                break;
            default:
                cout << "Invalid Choice\n";
        }
    } while(choice != 4);

    return 0;
}