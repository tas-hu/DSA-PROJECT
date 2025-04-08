#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankAccount {
    int accountNumber;
    char name[100];
    float balance;
};

struct BankAccount account;

void createAccount() {
    printf("Enter Account Number: ");
    scanf("%d", &account.accountNumber);
    printf("Enter Name: ");
    scanf(" %[^\n]%*c", account.name);
    printf("Enter Initial Balance: ");
    scanf("%f", &account.balance);
    printf("\nAccount created successfully!\n");
}

void displayAccount() {
    printf("\n----- Account Details -----\n");
    printf("Account Number: %d\n", account.accountNumber);
    printf("Name: %s\n", account.name);
    printf("Balance: %.2f\n", account.balance);
}

void deposit() {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        account.balance += amount;
        printf("Amount deposited successfully!\n");
    } else {
        printf("Invalid amount.\n");
    }
}

void withdraw() {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= account.balance) {
        account.balance -= amount;
        printf("Amount withdrawn successfully!\n");
    } else {
        printf("Invalid or insufficient balance.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Bank Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Display Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createAccount();
            break;
        case 2:
            displayAccount();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            printf("Thank you for using our banking system!\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
