//Edwin Mapulane

#include <iostream>
#include <string>
using namespace std;

// Customer details
string names[3] = {"Thabo", "Lerato", "Sipho"};

int accounts[3] = {1001, 1002, 1003} ;

int pins[3] = {1234, 2222, 3333};

double balances[3] = {2500, 1800, 3200};

// Function declarations
void displayMenu();
void deposit(int user);
void withdraw(int user);
void sendCash(int user);
void checkBalance(int user);

int main()
{
    int account, pin;
    int user = -1;
    int choice;

    cout << "==================================\n" ;
    cout << "       GCC BANK\n" ;
    cout << " YOUR MONEY, YOUR FUTURE\n" ;
    cout << "==================================\n";

    // Customer login
    cout << "\nEnter account number: " ;
    cin >> account;

    cout << "Enter PIN: " <<endl;
    cin >> pin;

    // Find customer
    for (int i = 0; i < 3; i++)
    {
        if (accounts[i] == account && pins[i] == pin)
        {
            user = i;
            break;
        }
    }

    if (user == -1)
    {
        cout << "\nIncorrect account number or PIN!\n";
        return 0;
    }

    cout << "\nWelcome " << names[user] << "!\n";

    // Banking menu
    do
    {
        displayMenu();

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                deposit(user);
                break;

            case 2:
                withdraw(user);
                break;

            case 3:
                sendCash(user);
                break;

            case 4:
                checkBalance(user);
                break;

            case 5:
                cout << "\nThank you for banking with GCC BANK!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}

// Display banking menu
void displayMenu()
{
    cout << "\n========== GCC BANK ==========\n";
    cout << "1. Deposit Money\n";
    cout << "2. Withdraw Money\n";
    cout << "3. Send Cash\n";
    cout << "4. Check Balance\n";
    cout << "5. Exit\n";
    cout << "==============================\n";
}

// Deposit money
void deposit(int user)
{
    double amount;

    cout << "\nEnter amount to deposit: R";
    cin >> amount;

    if (amount > 0)
    {
        balances[user] += amount;

        cout << "Deposit successful!\n";
        cout << "New balance: R" << balances[user] << endl;
    }
    else
    {
        cout << "Invalid amount!\n";
    }
}

// Withdraw money
void withdraw(int user)
{
    double amount;

    cout << "\nEnter amount to withdraw: R";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount!\n";
    }
    else if (amount > balances[user])
    {
        cout << "Insufficient funds!\n";
    }
    else
    {
        balances[user] -= amount;

        cout << "Withdrawal successful!\n";
        cout << "Remaining balance: R" << balances[user] << endl;
    }
}

// Send cash
void sendCash(int user)
{
    int receiverAccount;
    int receiver = -1;
    double amount;

    cout << "\nEnter recipient account number: ";
    cin >> receiverAccount;

    // Find recipient
    for (int i = 0; i < 3; i++)
    {
        if (accounts[i] == receiverAccount)
        {
            receiver = i;
            break;
        }
    }

    if (receiver == -1)
    {
        cout << "Account does not exist!\n";
    }
    else if (receiver == user)
    {
        cout << "You cannot send money to yourself!\n";
    }
    else
    {
        cout << "Recipient: " << names[receiver] << endl;

        cout << "Enter amount to send: R";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount!\n";
        }
        else if (amount > balances[user])
        {
            cout << "Insufficient funds!\n";
        }
        else
        {
            balances[user] -= amount;
            balances[receiver] += amount;

            cout << "\nTransfer successful!\n";
            cout << "Money sent to: " << names[receiver] << endl;
            cout << "Remaining balance: R" << balances[user] << endl;
        }
    }
}

// Check account balance
void checkBalance(int user)
{
    cout << "\n======= ACCOUNT DETAILS =======\n";
    cout << "Customer name: " << names[user] << endl;
    cout << "Account number: " << accounts[user] << endl;
    cout << "Current balance: R" << balances[user] << endl;
    cout << "===============================\n";
}


