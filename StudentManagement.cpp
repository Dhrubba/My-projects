#include <iostream>
using namespace std;


class Person {
protected:
    string name;
public:
    Person() { name = "Unknown"; }

    Person(string n) { name = n; }

    virtual ~Person() { }
};

class Student : public Person {
private:
    int rollNo;
    string department;
    int semester;
    int marks[5];      
    int total;
    float percentage;
    char grade;

public:
    Student() : Person() {
        rollNo = 0;
        department = "";
        semester = 0;
        for (int i = 0; i < 5; i++) marks[i] = 0;
        total = 0;
        percentage = 0;
        grade = 'F';
    }

    void input() {
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cin.ignore();
        cout << "Enter Department: ";
        getline(cin, department);

        cout << "Enter Semester: ";
        cin >> semester;

        cout << "Enter marks of 5 subjects: ";
        total = 0;
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
            total += marks[i];
        }
        calculateResult();
    }

    void calculateResult() {
        percentage = total / 5.0;

        if (percentage >= 90) grade = 'A+';
        else if (percentage >= 80) grade = 'A';
        else if (percentage >= 70) grade = 'B';
        else if (percentage >= 50) grade = 'C';
        else if (percentage >= 40) grade = 'D';
        else grade = 'F';
    }

    void display() {
        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Dept: " << department
             << " | Sem: " << semester
             << " | %: " << percentage
             << " | Grade: " << grade << endl;
    }

    void reportCard() {
        cout << "\n=== Report Card ===\n";
        cout << "Name: " << name
             << "\nRoll: " << rollNo
             << "\nDepartment: " << department
             << "\nSemester: " << semester
             << "\nMarks: ";
        for (int i = 0; i < 5; i++) cout << marks[i] << " ";
        cout << "\nTotal: " << total
             << "\nPercentage: " << percentage
             << "\nGrade: " << grade << endl;
        cout << "*\n";
    }

    int getRollNo() { return rollNo; }

    void modify() {
        cout << "Re-enter details:\n";
        input();
    }
};


Student students[100];   
int studentCount = 0;    


void addStudent() {
    students[studentCount].input();
    studentCount++;
}

void displayAll() {
    if (studentCount == 0) cout << "No records!\n";
    else {
        for (int i = 0; i < studentCount; i++) {
            students[i].display();
        }
    }
}

void searchStudent() {
    int roll;
    cout << "Enter roll no: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].getRollNo() == roll) {
            students[i].display();
            return;
        }
    }
    cout << "Student not found!\n";
}

void modifyStudent() {
    int roll;
    cout << "Enter roll no: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].getRollNo() == roll) {
            students[i].modify();
            return;
        }
    }
    cout << "Student not found!\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter roll no: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].getRollNo() == roll) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Record deleted!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void generateReportCard() {
    int roll;
    cout << "Enter roll no: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].getRollNo() == roll) {
            students[i].reportCard();
            return;
        }
    }
    cout << "Student not found!\n";
}

int main() {
    int choice;
    do {
        cout << "\n Student Management System \n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Modify Student Record\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Generate Report Card\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: modifyStudent(); break;
            case 5: deleteStudent(); break;
            case 6: generateReportCard(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}