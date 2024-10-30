#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for an Expense record
typedef struct {
    char date[11];
    char type[30];
    double amount;
} Expense;

// Maximum number of expenses
#define MAX_EXPENSES 100

// Global array to store expenses
Expense expensesArray[MAX_EXPENSES];
int expenseCount = 0;

// Linked List Node for Expense
typedef struct Node {
    Expense expense;
    struct Node* next;
} Node;

Node* head = NULL;

// Stack to undo the last added expense
typedef struct {
    Expense stack[MAX_EXPENSES];
    int top;
} Stack;

Stack expenseStack = {.top = -1};

// Queue for feedback
typedef struct {
    char feedback[100];
    int rating;
} Feedback;

Feedback feedbackQueue[MAX_EXPENSES];
int feedbackFront = 0;
int feedbackRear = 0;

// Function prototypes
void addExpenseArray();
void editExpenseArray();
void deleteExpenseArray();
void viewExpensesArray();
void viewTotalArray();
void giveFeedbackQueue();
void pushToStack(Expense exp);
Expense popFromStack();

// Function to add an expense
void addExpenseArray() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Expense list is full.\n");
        return;
    }
    Expense newExpense;

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", newExpense.date);
    printf("Enter type of expense: ");
    scanf("%s", newExpense.type);
    do {
        printf("Enter amount: ");
        scanf("%lf", &newExpense.amount);
        if (newExpense.amount < 0) {
            printf("Amount cannot be negative.\n");
        }
    } while (newExpense.amount < 0);

    expensesArray[expenseCount] = newExpense;
    pushToStack(newExpense);
    expenseCount++;

    printf("Expense added successfully.\n");
}

// Function to edit an expense
void editExpenseArray() {
    viewExpensesArray();
    int index;
    printf("Enter the index of the expense to edit: ");
    scanf("%d", &index);

    if (index < 1 || index > expenseCount) {
        printf("Invalid index.\n");
        return;
    }
    index--;  // Adjusting for array index

    Expense* exp = &expensesArray[index];
    printf("Enter new date (dd/mm/yyyy): ");
    scanf("%s", exp->date);
    printf("Enter new type: ");
    scanf("%s", exp->type);

    do {
        printf("Enter new amount: ");
        scanf("%lf", &exp->amount);
        if (exp->amount < 0) {
            printf("Amount cannot be negative.\n");
        }
    } while (exp->amount < 0);

    printf("Expense updated successfully.\n");
}

// Function to delete an expense
void deleteExpenseArray() {
    viewExpensesArray();
    int index;
    printf("Enter the index of the expense to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > expenseCount) {
        printf("Invalid index.\n");
        return;
    }
    index--;  // Adjusting for array index

    for (int i = index; i < expenseCount - 1; i++) {
        expensesArray[i] = expensesArray[i + 1];
    }
    expenseCount--;
    printf("Expense deleted successfully.\n");
}

// Function to view all expenses
void viewExpensesArray() {
    if (expenseCount == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("%-5s %-15s %-15s %-10s\n", "No.", "Date", "Type", "Amount");
    for (int i = 0; i < expenseCount; i++) {
        printf("%-5d %-15s %-15s ₹%.2f\n", i + 1, expensesArray[i].date, expensesArray[i].type, expensesArray[i].amount);
    }
}

// Function to view total expenses
void viewTotalArray() {
    double total = 0;
    for (int i = 0; i < expenseCount; i++) {
        total += expensesArray[i].amount;
    }
    printf("Total Expense: ₹%.2f\n", total);
}

// Stack Functions for Undo Operation
void pushToStack(Expense exp) {
    if (expenseStack.top >= MAX_EXPENSES - 1) {
        printf("Undo stack is full.\n");
        return;
    }
    expenseStack.stack[++expenseStack.top] = exp;
}

Expense popFromStack() {
    Expense exp = {"", "", 0.0};
    if (expenseStack.top < 0) {
        printf("Undo stack is empty.\n");
        return exp;
    }
    return expenseStack.stack[expenseStack.top--];
}

// Function to handle feedback
void giveFeedbackQueue() {
    if ((feedbackRear + 1) % MAX_EXPENSES == feedbackFront) {
        printf("Feedback queue is full.\n");
        return;
    }
    printf("Enter feedback: ");
    scanf(" %[^\n]", feedbackQueue[feedbackRear].feedback);

    do {
        printf("Rate your experience (1 to 5): ");
        scanf("%d", &feedbackQueue[feedbackRear].rating);
    } while (feedbackQueue[feedbackRear].rating < 1 || feedbackQueue[feedbackRear].rating > 5);

    feedbackRear = (feedbackRear + 1) % MAX_EXPENSES;
    printf("Feedback recorded.\n");
}
// Main function
int main() {
    int choice;
    while (1) {
        printf("\n1. Add Expense\n2. Edit Expense\n3. Delete Expense\n4. View Expenses\n5. View Total\n6. Give Feedback\n7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addExpenseArray(); break;
            case 2: editExpenseArray(); break;
            case 3: deleteExpenseArray(); break;
            case 4: viewExpensesArray(); break;
            case 5: viewTotalArray(); break;
            case 6: giveFeedbackQueue(); break;
            case 7: exit(0);
            default: printf("Invalid option.\n");
        }
    }
}
