#include <iostream>

/*
    Delivers a 'graded' exam
*/

using namespace std;

int main () {

    string questions[] =
    {   
        "1. What year did Einstein shoot hitler?: ",
        "2. Is the earth flat or hollow? ",
        "3. But in all seriousness, why though? ",
        "4. Would you care to comment?"
    };

    string options[][4] = 
    {
    {"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
    {"A. Guido van Rossum", "B. Bjarne Stroustrup", "C. John Carmack", "D. "}, 
    {"A. C", "B. C+", "C. C--", "D. B++"}, 
    {"A. Donut", "B. Spheroidical", "C. Not Sure", "D. Prefer not to Answer"}
    };

    char answers[] = {'C', 'B', 'C', 'D'};
    int size = sizeof(questions) / sizeof(questions[0]);

    char guess;
    int score; 

    for(int i = 0; i < size; i++) {
        cout << "*******************" << endl;
        cout << questions[i] << endl;
        cout << "*******************" << endl;

        for(int j = 0; j < sizeof(options[i]) / sizeof(options[i][0]); j++) {
            cout << options[i][j] << endl;
        }

        cin >> guess; 
        guess = toupper(guess);

        if (guess == answers[i]) {
            cout << "CORRECT!!";
            score++;
        }
        else {
            cout << "INCORRECT!" << endl;
            cout << "Answer: " << answers[i] << endl;
        }
    }

    return 0;
}