// Lab9.1.cpp
// Михайлов Олександр
// Послідовний пошук в масиві структур
// Варіант 24

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>

using namespace std;

enum Speciality { KN, In, ME, FI, TN };

string specialityStr[]{ "КН","ІН","МЕ","ФІ","ТН" };

struct StudentA {
    string surname;
    int kurs;
    Speciality speciality;
    double physicsMark;
    double mathsMark;
    double OITmark;
};

struct StudentB {
    string surname;
    int kurs;
    Speciality speciality;
    double physicsMark;
    double mathsMark;
    union {
        double programmingMark;
        double chislMethodMark;
        double pedMark;
    };
};

void CreateA(StudentA* sa, const int amount) {
    int speciality;
    for (int i = 0; i < amount; i++) {
        cout << "Студент № " << i + 1 << ": " << endl;
        
        cin.get();
        cin.sync();

        cout << "   Прізвище: "; getline(cin, sa[i].surname);

        do {
            cout << "   Курс: "; cin >> sa[i].kurs;
            if (sa[i].kurs < 1 || sa[i].kurs > 6)
                cout << "   Є тільки 1-6 курси!" << endl;
        } while (sa[i].kurs < 1 || sa[i].kurs > 6);

        do {
            cout << "   Спеціальність (0 — КН, 1 — ІН, 2 — МЕ, 3 — ФІ, 4 — ТН): ";
            cin >> speciality;
            sa[i].speciality = (Speciality)speciality;

            if (speciality < 0 || speciality > 4)
                cout << "Ви ввели невірний номер!" << endl;
        } while (speciality < 0 || speciality > 4);

        do {
            cout << "   Оцінка з фізики: "; cin >> sa[i].physicsMark;
            if (sa[i].physicsMark <= 0 || sa[i].physicsMark > 5)
                cout << "Невірна оцінка!" << endl;
        } while (sa[i].physicsMark <= 0 || sa[i].physicsMark > 5);

        do {
            cout << "   Оцінка з математики: "; cin >> sa[i].mathsMark;
            if (sa[i].mathsMark <= 0 || sa[i].mathsMark > 5)
                cout << "Невірна оцінка!" << endl;
        } while (sa[i].mathsMark <= 0 || sa[i].mathsMark > 5);

        do {
            cout << "   Оцінка з інформатики: "; cin >> sa[i].OITmark;
            if (sa[i].OITmark <= 0 || sa[i].OITmark > 5)
                cout << "Невірна оцінка!" << endl;
        } while (sa[i].OITmark <= 0 || sa[i].OITmark > 5);

        cout << endl;
    }
}

void PrintA(StudentA* sa, const int amount) {
    cout << "===========================================================================" << endl;
    cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Інформатика |" << endl;
    cout << "---------------------------------------------------------------------------" << endl;

    for (int i = 0; i < amount; i++) {
        cout << "| " << right << i + 1 << " ";
        cout << "| " << setw(8) << left << sa[i].surname
            << " | " << setw(4) << left << sa[i].kurs
            << " | " << setw(13) << left << specialityStr[sa[i].speciality]
            << " | " << setw(6) << left << sa[i].physicsMark
            << " | " << setw(10) << left << sa[i].mathsMark
            << " | " << setw(11) << left << sa[i].OITmark
            << " |";
        cout << endl;
    }
    cout << "===========================================================================" << endl << endl;
}

int FindStudentA_AmountPerfectMark(StudentA* sa, const int amount) {
    int perfectMarkAmount = 0;

    for (int i = 0; i < amount; i++) {
        if (sa[i].physicsMark == 5 && sa[i].mathsMark == 5 && sa[i].OITmark == 5) {
            perfectMarkAmount++;
        }
    }

    return perfectMarkAmount;
}

double FindStudentA_PercentagePhysicsPerfect(StudentA* sa, const int amount) {
    double k = 0;

    for (int i = 0; i < amount; i++) {
        if (sa[i].physicsMark == 5) {
            k++;
        }
    }
    double PercentagePhysicsPerfect = (k / amount * 1.0) * 100;

    return PercentagePhysicsPerfect;
}

void CreateB(StudentB* sb, const int amount) {
    int speciality;

    for (int i = 0; i < amount; i++) {
        cout << "Студент № " << i + 1 << ": " << endl;

        cin.get();
        cin.sync();

        cout << "   Прізвище: "; getline(cin, sb[i].surname);

        do {
            cout << "   Курс: "; cin >> sb[i].kurs;
            if (sb[i].kurs < 1 || sb[i].kurs > 6)
                cout << "   Є тільки 1-6 курси!" << endl;
        } while (sb[i].kurs < 1 || sb[i].kurs > 6);

        do {
            cout << "   Спеціальність (0 — КН, 1 — ІН, 2 — МЕ, 3 — ФІ, 4 — ТН): ";
            cin >> speciality;
            sb[i].speciality = (Speciality)speciality;

            if (speciality < 0 || speciality > 4)
                cout << "Ви ввели невірний номер!" << endl;
        } while (speciality < 0 || speciality > 4);

        do {
            cout << "   Оцінка з фізики: "; cin >> sb[i].physicsMark;
            if (sb[i].physicsMark <= 0 || sb[i].physicsMark > 5)
                cout << "Невірна оцінка!" << endl;
        } while (sb[i].physicsMark <= 0 || sb[i].physicsMark > 5);

        do {
            cout << "   Оцінка з математики: "; cin >> sb[i].mathsMark;
            if (sb[i].mathsMark <= 0 || sb[i].mathsMark > 5)
                cout << "Невірна оцінка!" << endl;
        } while (sb[i].mathsMark <= 0 || sb[i].mathsMark > 5);

        switch (sb[i].speciality) {
        case KN:
            do {
                cout << "   Оцінка з програмування: "; cin >> sb[i].programmingMark;
                if (sb[i].programmingMark <= 0 || sb[i].programmingMark > 5)
                    cout << "Невірна оцінка!" << endl;
            } while (sb[i].programmingMark <= 0 || sb[i].programmingMark > 5);
            break;
        case In:
            do {
                cout << "   Оцінка з чисельних методів: "; cin >> sb[i].chislMethodMark;
                if (sb[i].chislMethodMark <= 0 || sb[i].chislMethodMark > 5)
                    cout << "Невірна оцінка!" << endl;
            } while (sb[i].chislMethodMark <= 0 || sb[i].chislMethodMark > 5);
            break;
        case ME:
        case FI:
        case TN:
            do {
                cout << "   Оцінка з педагогіки: "; cin >> sb[i].pedMark;
                if (sb[i].pedMark <= 0 || sb[i].pedMark > 5)
                    cout << "Невірна оцінка!" << endl;
            } while (sb[i].pedMark <= 0 || sb[i].pedMark > 5);
            break;
        }
        cout << endl;
    }
}

void PrintB(StudentB* sb, const int amount) {
    cout << "============================================================================================================" << endl;
    cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Програмування | Чисельні Методи | Педігогіка |" << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < amount; i++) {
        cout << "| " << right << i + 1 << " ";
        cout << "| " << setw(8) << left << sb[i].surname
            << " | " << setw(4) << left << sb[i].kurs
            << " | " << setw(13) << left << specialityStr[sb[i].speciality]
            << " | " << setw(6) << left << sb[i].physicsMark
            << " | " << setw(10) << left << sb[i].mathsMark;

        switch (sb[i].speciality) {
        case KN:
            cout << " | " << setw(13) << left << sb[i].programmingMark
                << " | " << setw(15) << left << "—" << " | " << setw(10) << left << "—" << " |";
            break;
        case In:
            cout << " | " << setw(13) << left << "—"
                << " | " << setw(15) << sb[i].chislMethodMark
                << " | " << setw(10) << left << "—" << " |";
            break;
        case ME:
        case FI:
        case TN:
            cout << " | " << setw(13) << left << "—"
                << " | " << setw(15) << left << "—"
                << " | " << setw(10) << left << sb[i].pedMark << " |";
        }
        cout << endl;
    }
    cout << "============================================================================================================" << endl << endl;
}

int FindStudentB_AmountPerfectMark(StudentB* sb, const int amount) {
    int perfectMarkAmount = 0;

    for (int i = 0; i < amount; i++) {
        if (sb[i].physicsMark == 5 && sb[i].mathsMark == 5) {
            switch (sb[i].speciality) {
            case KN:
                if (sb[i].programmingMark == 5) {
                    perfectMarkAmount++;
                }
                break;
            case In:
                if (sb[i].chislMethodMark == 5) {
                    perfectMarkAmount++;
                }
                break;
            case ME:
            case FI:
            case TN:
                if (sb[i].pedMark == 5) {
                    perfectMarkAmount++;
                }
                break;
            }
        }
    }
    return perfectMarkAmount;
}

double FindStudentB_PercentagePhysicsPerfect(StudentB* sb, const int amount) {
    double k = 0;

    for (int i = 0; i < amount; i++) {
        if (sb[i].physicsMark == 5) {
            k++;
        }
    }
    double PercentagePhysicsPerfect = (k / amount * 1.0) * 100;

    return PercentagePhysicsPerfect;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int amount;

    do {
        cout << "Введіть кількість студентів: "; cin >> amount;
        if (amount < 1)
            cout << endl << "Кількість студентів не може бути меньше одного!" << endl << endl;
    } while (amount < 1);

    StudentA* sa = new StudentA[amount];
    StudentB* sb = new StudentB[amount];

    //Спосіб А
    cout << endl << "Level A: " << endl << endl;

    CreateA(sa, amount);
    PrintA(sa, amount);
    cout << "Кількість студентів, які вчаться на відмінно: " << FindStudentA_AmountPerfectMark(sa, amount) << endl;
    cout << "Процент студентів, які отримали з фізики оцінку 5: " << FindStudentA_PercentagePhysicsPerfect(sa, amount) << " %" << endl;

    //Спосіб B
    cout << endl << "Level B: " << endl << endl;

    CreateB(sb, amount);
    PrintB(sb, amount);
    cout << "Кількість студентів, які вчаться на відмінно: " << FindStudentB_AmountPerfectMark(sb, amount) << endl;
    cout << "Процент студентів, які отримали з фізики оцінку 5: " << FindStudentB_PercentagePhysicsPerfect(sb, amount) << " %" << endl;

    return 0;
}