#include <iostream>

using namespace std;



    double num1, num2;
    double product, sum, difference, division;
    int option;

    double add()
    {
        sum = num1 + num2;
        return sum;
    }
    double subtract()
    {
        difference = num1 - num2;
        return difference;
    }
    double multiply()
    {
        product = num1 * num2;
        return product;
    }
    double divide()
    {
        if (num2 != 0)
        {
            division  = num1 / num2;
            return division;
        }
        cout << "Cannot divide by zero!" << endl;
        return 0;
    }
    void menu()
    {
        cout << "\n===== SIMPLE CALCULATOR =====" << endl;
        cout << "1. ADD" << endl;
        cout << "2. SUBTRACT" << endl;
        cout << "3. MULTIPLY" << endl;
        cout << "4. DIVISION" << endl;
        cout << "4. EXIT" << endl;
        cout << "Enter Your Choice :" << endl;
        cin >> option;

        if (option >= 1 && option <= 4)
        {
            cout << "Enter Number 1: ";
            cin >> num1;

            cout << "Enter Number 2: ";
            cin >> num2;
        }
        switch (option)
        {
            case 1:
                cout << "Answer = " << add() << endl;
            case 2:
                cout << "Answer = " << subtract() << endl;
            case 3:
                cout << "Answer = " << multiply() << endl;
            case 4:
                cout << "Answer = " << divide() << endl;
            case 5:
                cout << "Calculator Closed" << endl;

            default:
                cout << "Invaild Choice" << endl;
        }
    }
    int main()
    {
        do
        {
            menu ();
        }
        while (option != 5);
    }

return 0;
