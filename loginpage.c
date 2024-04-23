


#include <stdio.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];
};

const int MAX_USERS = 10;
const int MAX_USERNAME_LENGTH = 50;
const int MAX_PASSWORD_LENGTH = 50;

void createUserAccount(struct User users[], int *numUsers);
int login(struct User users[], int numUsers);

int main() {
    struct User users[10];
    int numUsers = 0;

    printf("\n--- Welcome to the Online Grocery Store ---\n");

    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Login\n");
        printf("2. Create Account\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Login
                if (numUsers == 0) {
                    printf("\nNo users exist. Please create an account first.\n");
                } else {
                    int loginStatus = login(users, numUsers);
                    if (loginStatus == 1) {
                        printf("\n------------------------------------------\n");
                        printf("   Login successful! Welcome to the store!\n");
                        printf("------------------------------------------\n");

                        

                        return 0; 
                    } else {
                        printf("\n--------------------------------------\n");
                        printf("   Login failed. Incorrect credentials.\n");
                        printf("--------------------------------------\n");
                    }
                }
                break;
            case 2:
                createUserAccount(users, &numUsers);
                break;
            case 3:
                printf("\nThank you for visiting. Goodbye!\n");
                return 0; // Exit the program
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}

void createUserAccount(struct User users[], int *numUsers) {
    if (*numUsers >= MAX_USERS) {
        printf("\nMaximum number of users reached. Cannot create a new account.\n");
        return;
    }

    printf("\n--- Create a New Account ---\n");

    printf("Enter username: ");
    scanf("%s", users[*numUsers].username);

    printf("Enter password: ");
    scanf("%s", users[*numUsers].password);

    (*numUsers)++;
    printf("\nAccount created successfully!\n");
}

int login(struct User users[], int numUsers) {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("\n--- Login ---\n");

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return 1; 
        }
    }

    return 0; 
}





