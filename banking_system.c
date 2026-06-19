#include <stdio.h>

struct Account
{
    int accountNumber;
    char name[50];
    float balance;
};

void deposit(struct Account *acc)
{
    float amount;

    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);

    acc->balance += amount;

    printf("Amount deposited successfully!");
    printf("\nCurrent Balance: %.2f\n", acc->balance);
}

void withdraw(struct Account *acc)
{
    float amount;

    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);

    if(amount > acc->balance)
    {
        printf("Insufficient Balance!\n");
    }
    else
    {
        acc->balance -= amount;

        printf("Withdrawal successful!");
        printf("\nCurrent Balance: %.2f\n", acc->balance);
    }
}

void checkBalance(struct Account acc)
{
    printf("\nAccount Number : %d", acc.accountNumber);
    printf("\nAccount Holder : %s", acc.name);
    printf("\nCurrent Balance: %.2f\n", acc.balance);
}

int main()
{
    struct Account acc;
    int choice;

    printf("=====================================\n");
    printf("      BANKING MANAGEMENT SYSTEM\n");
    printf("=====================================\n");

    printf("Enter Account Number: ");
    scanf("%d", &acc.accountNumber);

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", acc.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &acc.balance);

    do
    {
        printf("\n\n========== MENU ==========\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Balance Enquiry\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                deposit(&acc);
                break;

            case 2:
                withdraw(&acc);
                break;

            case 3:
                checkBalance(acc);
                break;

            case 4:
                printf("\nThank You for Using Banking System!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}
