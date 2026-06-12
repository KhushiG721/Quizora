#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Question {
    string text;
    string optionA, optionB, optionC, optionD;
    char correctOption;
};

vector<Question> questionBank;

void adminMenu();
void studentMenu();

void addQuestion() {
    Question q;
    cout << "\nEnter Question: ";
    cin.ignore();
    getline(cin, q.text);
    cout << "Option A: ";
    getline(cin, q.optionA);
    cout << "Option B: ";
    getline(cin, q.optionB);
    cout << "Option C: ";
    getline(cin, q.optionC);
    cout << "Option D: ";
    getline(cin, q.optionD);
    cout << "Correct Option (A/B/C/D): ";
    cin >> q.correctOption;

    questionBank.push_back(q);
    cout << "Question added successfully.\n";
}

void viewQuestions() {
    cout << "\n--- All Questions ---\n";
    if (questionBank.empty()) {
        cout << "No questions available.\n";
        return;
    }

    for (size_t i = 0; i < questionBank.size(); ++i) {
        cout << "\nQ" << i + 1 << ": " << questionBank[i].text << "\n";
        cout << "A. " << questionBank[i].optionA << "\n";
        cout << "B. " << questionBank[i].optionB << "\n";
        cout << "C. " << questionBank[i].optionC << "\n";
        cout << "D. " << questionBank[i].optionD << "\n";
        cout << "Answer: " << questionBank[i].correctOption << "\n";
    }
}

void takeQuiz() {
    int score = 0;
    char ans;

    if (questionBank.empty()) {
        cout << "No questions to take quiz.\n";
        return;
    }

    for (size_t i = 0; i < questionBank.size(); ++i) {
        cout << "\nQ" << i + 1 << ": " << questionBank[i].text << "\n";
        cout << "A. " << questionBank[i].optionA << "\n";
        cout << "B. " << questionBank[i].optionB << "\n";
        cout << "C. " << questionBank[i].optionC << "\n";
        cout << "D. " << questionBank[i].optionD << "\n";
        cout << "Enter your answer (A/B/C/D): ";
        cin >> ans;

        if (toupper(ans) == toupper(questionBank[i].correctOption)) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong! Correct answer: " << questionBank[i].correctOption << "\n";
        }
    }

    cout << "\nQuiz complete! Your score: " << score << "/" << questionBank.size() << "\n";
}

void adminLogin() {
    string user, pass;
    cout << "\n--- Admin Login ---\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    if (user == "admin" && pass == "1234") {
        adminMenu();
    } else {
        cout << "Invalid credentials!\n";
    }
}

void adminMenu() {
    int choice;
    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Add Question\n";
        cout << "2. View All Questions\n";
        cout << "3. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addQuestion(); break;
            case 2: viewQuestions(); break;
            case 3: cout << "Logging out...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 3);
}

void studentMenu() {
    cout << "\n--- Student Quiz Portal ---\n";
    takeQuiz();
}

int main() {
    int roleChoice;
    do {
        cout << "\n==== Online Quiz System ====\n";
        cout << "1. Admin Login\n";
        cout << "2. Student Login\n";
        cout << "3. Exit\n";
        cout << "Enter your role: ";
        cin >> roleChoice;

        switch (roleChoice) {
            case 1: adminLogin(); break;
            case 2: studentMenu(); break;
            case 3: cout << "Exiting program. Goodbye!\n"; break;
            default: cout << "Invalid input.\n";
        }
    } while (roleChoice != 3);

    return 0;
}
