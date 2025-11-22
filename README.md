📘 CGPA Calculator – C++ OOP Project

A simple and efficient CGPA (Cumulative Grade Point Average) Calculator built using Object-Oriented Programming in C++, where CGPA is calculated based on marks, not credits.
The program converts marks → grade points → CGPA using the standard 10-point grading scale.

✨ Features

Accepts marks for any number of subjects

Converts marks automatically to grade points

Calculates CGPA = average of grade points

Clean OOP design using classes, objects, vectors, constructor, encapsulation

Works on all platforms (Windows, Linux, macOS)

Beginner-friendly & lab-ready code

🧮 CGPA Formula Used
1️⃣ Marks → Grade Point Conversion
Marks Range	Grade Point
90–100	10
80–89	9
70–79	8
60–69	7
50–59	6
40–49	5
Below 40	0 (Fail)
2️⃣ CGPA Calculation

Since credits are not used:

CGPA
=
∑
Grade Points
Number of Subjects
CGPA=
Number of Subjects
∑Grade Points
	​

📂 Project Structure
CGPA-Calculator/
│
├── cgpa.cpp          # Main C++ source code
├── README.md         # Documentation (this file)
├── screenshots/      # (Optional) Output images
└── docs/             # (Optional) Report / PDF files

🚀 How to Run This Project
1️⃣ Install C++ Compiler

Windows → MinGW-w64

Linux → GCC

macOS → Xcode / Clang

2️⃣ Compile the code

Open terminal inside project folder:

g++ cgpa.cpp -o cgpa

3️⃣ Run the program
./cgpa


or (Windows)

cgpa.exe

👨‍💻 Usage Example
Enter Student Name: Narasimha
Enter number of subjects: 3

Enter name of subject 1: Maths
Enter marks for Maths: 95

Enter name of subject 2: Physics
Enter marks for Physics: 82

Enter name of subject 3: OOPS
Enter marks for OOPS: 76


Output

===== Student Details =====
Name: Narasimha

Subject: Maths | Marks: 95 | Grade Point: 10
Subject: Physics | Marks: 82 | Grade Point: 9
Subject: OOPS | Marks: 76 | Grade Point: 8

Final CGPA: 9.0

💻 Source Code (cgpa.cpp)
#include <iostream>
#include <vector>
using namespace std;

// Converts marks to grade point (0–10)
float marksToGradePoint(float marks) {
    if (marks >= 90) return 10;
    else if (marks >= 80) return 9;
    else if (marks >= 70) return 8;
    else if (marks >= 60) return 7;
    else if (marks >= 50) return 6;
    else if (marks >= 40) return 5;
    else return 0; // fail
}

class Subject {
private:
    string name;
    float marks;
    float gradePoint;

public:
    Subject(string n, float m) {
        name = n;
        marks = m;
        gradePoint = marksToGradePoint(m);
    }

    float getGradePoint() {
        return gradePoint;
    }

    void display() {
        cout << "Subject: " << name
             << " | Marks: " << marks
             << " | Grade Point: " << gradePoint << endl;
    }
};

class Student {
private:
    string studentName;
    vector<Subject> subjects;

public:
    Student(string name) {
        studentName = name;
    }

    void addSubject(string name, float marks) {
        Subject s(name, marks);
        subjects.push_back(s);
    }

    float calculateCGPA() {
        if (subjects.size() == 0) return 0;

        float totalGP = 0;
        for (auto &sub : subjects) {
            totalGP += sub.getGradePoint();
        }

        return totalGP / subjects.size(); // Average grade point
    }

    void displayDetails() {
        cout << "\n===== Student Details =====\n";
        cout << "Name: " << studentName << endl;

        cout << "\nSubjects Entered:\n";
        for (auto &sub : subjects) {
            sub.display();
        }

        cout << "\nFinal CGPA: " << calculateCGPA() << endl;
    }
};

int main() {
    string name;
    int numSubjects;

    cout << "Enter Student Name: ";
    getline(cin, name);

    Student s(name);

    cout << "Enter number of subjects: ";
    cin >> numSubjects;

    for (int i = 0; i < numSubjects; i++) {
        cin.ignore();
        string subName;
        float marks;

        cout << "\nEnter name of subject " << i + 1 << ": ";
        getline(cin, subName);

        cout << "Enter marks for " << subName << " (0–100): ";
        cin >> marks;

        s.addSubject(subName, marks);
    }

    s.displayDetails();

    return 0;
}

📌 Future Enhancements

Add credit-based CGPA calculation

Store data in a CSV or database

Add GPA + SGPA calculator

Add GUI (Qt, Tkinter, Flutter Desktop)

Add error validation for invalid marks

🧑‍💻 Author

Narasimha
2nd Year Engineering Student

📜 License

This project is released under the MIT License.
You are free to use, modify, and distribute it.
