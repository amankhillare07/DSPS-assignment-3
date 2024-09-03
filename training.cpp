#include <iostream>
#include <string>
using namespace std;

int f = 0; 

class student {
public:
    int rno;
    string name, branch, T_name;
    void accept() {
        cout << "Enter the Student rollno: ";
        cin >> rno;
        cout << "Enter the name of student: ";
        cin >> name;
        cout << "Enter the branch of student: ";
        cin >> branch;
        cout << "Enter the Training name: ";
        cin >> T_name;
    }
    void display() const {
        cout << "\nRollno: " << rno;
        cout << "\nName of Student: " << name;
        cout << "\nBranch: " << branch;
        cout << "\nTraining name: " << T_name << endl;
    }

    void Lsearch(int r) {
        if (rno == r) {
            f = 1; 
            cout << "\nRecord found!";
            cout << "\nRollno: " << rno;
            cout << "\nName of Student: " << name;
            cout << "\nBranch: " << branch;
            cout << "\nTraining name: " << T_name << endl;
        }
    }
};

void binarySearch(student s[], int n, int r) {
    int low = 0, high = n - 1, mid;
    f = 0; 

    while (low <= high) {
        mid = (low + high) / 2;
        if (s[mid].rno == r) {
            f = 1;
            cout << "\nRecord found!";
            cout << "\nRollno: " << s[mid].rno;
            cout << "\nName of Student: " << s[mid].name;
            cout << "\nBranch: " << s[mid].branch;
            cout << "\nTraining name: " << s[mid].T_name << endl;
            return;
        } else if (s[mid].rno < r) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (f == 0) {
        cout << "Student is absent for the training program." << endl;
    }
}

int main() {
    int r, n;
    student s[20];

    cout << "Enter the number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        s[i].accept();
    }
    cout << "\nDisplaying all students:\n";
    for (int i = 0; i < n; i++) {
        s[i].display();
    }
    cout << "Enter the roll number of the student to search (Linear Search): ";
    cin >> r;

    for (int i = 0; i < n; i++) {
        s[i].Lsearch(r);
    }

    if (f == 0) {
        cout << "Student is absent for the training program." << endl;
    }
    cout << "\nEnter the roll number of the student to search (Binary Search): ";
    cin >> r;

    binarySearch(s, n, r);

    return 0;
}