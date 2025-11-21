#include <iostream>
#include <vector>
using namespace std;

// Class to store a single subject
class Subject {
private:
    string name;
    int credits;
    float gradePoint;

public:
    Subject(string n, int c, float g) {
        name = n;
        credits = c;
        gradePoint = g;
    }

    int getCredits() {
        return credits;
    }

    float getGradePoint() {
        return gradePoint;
    }

    void display() {
        cout << "Subject: " << name
             << " | Credits: " << credits
             << " | Grade Point: " << gradePoint << endl;
    }
};

// Student Class
class Student {
private:
    string studentName;
    vector<Subject> subjects;
public:
    Student(string name) {
        studentName = name;
    }
    void addSubject(string name, int credits, float gradePoint) {
        Subject s(name, credits, gradePoint);
        subjects.push_back(s);
    }
    float calculateCGPA() {
        float totalPoints = 0;
        int totalCredits = 0;

        for (auto &sub : subjects) {
            totalPoints += sub.getCredits() * sub.getGradePoint();
            totalCredits += sub.getCredits();
        }

        if (totalCredits == 0) return 0;

        return totalPoints / totalCredits;
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
// Main Function
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
        int credits;
        float gradePoint;
        cout << "\nEnter name of subject " << i + 1 << ": ";
        getline(cin, subName);
        cout << "Enter credits for " << subName << ": ";
        cin >> credits;
        cout << "Enter grade point for " << subName << " (0–10): ";
        cin >> gradePoint;
        s.addSubject(subName, credits, gradePoint);
    }
    s.displayDetails();
    return 0;
}
