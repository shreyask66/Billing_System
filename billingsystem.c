#include <stdio.h>
#include <string.h>


#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_CART_ITEMS 10


void createUserAccount(char usernames[][MAX_USERNAME_LENGTH], char passwords[][MAX_PASSWORD_LENGTH], int *numUsers);
int login(char usernames[][MAX_USERNAME_LENGTH], char passwords[][MAX_PASSWORD_LENGTH], int numUsers);
void displayItems();
void addToCart(float cart[], int *itemCount);
float calculateTotal(float cart[], int itemCount);

int main() {
    printf("Welcome to the Online Grocery Store\n");

    
    char usernames[MAX_USERS][MAX_USERNAME_LENGTH];
    char passwords[MAX_USERS][MAX_PASSWORD_LENGTH];
    int numUsers = 0;

    
    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Login\n");
        printf("2. Create Account\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Login
                if (numUsers == 0) {
                    printf("No users exist. Please create an account first.\n");
                } else {
                    int loginStatus = login(usernames, passwords, numUsers);
                    if (loginStatus == 1) {
                        printf("Login successful!\n");

                        
                        float cart[MAX_CART_ITEMS];
                        int itemCount = 0;

                        
                        displayItems();

                        
                        addToCart(cart, &itemCount);

                        
                        float totalAmount = calculateTotal(cart, itemCount);
                        printf("Total Amount: Rs%.2f\n", totalAmount);

                        printf("Thank you for shopping with us!\n");
                        return 0; 
                    } else {
                        printf("Login failed. Incorrect username or password.\n");
                    }
                }
                break;
            case 2:
                
                createUserAccount(usernames, passwords, &numUsers);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}

void createUserAccount(char usernames[][MAX_USERNAME_LENGTH], char passwords[][MAX_PASSWORD_LENGTH], int *numUsers) {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Create a new account\n");

    if (*numUsers < MAX_USERS) {
        printf("Enter username: ");
        scanf("%s", username);
        strcpy(usernames[*numUsers], username);

        printf("Enter password: ");
        scanf("%s", password);
        strcpy(passwords[*numUsers], password);

        (*numUsers)++;
        printf("Account created successfully!\n");
    } else {
        printf("Maximum number of users reached. Cannot create new account.\n");
    }
}

int login(char usernames[][MAX_USERNAME_LENGTH], char passwords[][MAX_PASSWORD_LENGTH], int numUsers) {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("\nLogin\n");

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, usernames[i]) == 0 && strcmp(password, passwords[i]) == 0) {
            return 1; 
        }
    }

    return 0; 
}

void displayItems() {
    printf("\nItems Available:\n");
    printf("1. Milk - Rs60.00\n");
    printf("2. Bread - Rs40.00\n");
    printf("3. Cheese - Rs80.00\n");
    printf("4. Apple - Rs12.00\n");
    printf("5. Banana - Rs8.00\n");
}

void addToCart(float cart[], int *itemCount) {
    int choice, quantity;
    do {
        printf("Enter item number to add to cart (0 to checkout): ");
        scanf("%d", &choice);

        float price = 0.0;
        switch (choice) {
            case 1:
                price = 60.00;
                break;
            case 2:
                price = 40.00;
                break;
            case 3:
                price = 80.00;
                break;
            case 4:
                price = 12.00;
                break;
            case 5:
                price = 8.00;
                break;
            default:
                price = 0.00;
                break;
        }

        if (price > 0.00 && *itemCount < MAX_CART_ITEMS) {
            printf("Enter quantity for this item: ");
            scanf("%d", &quantity);

            if (quantity > 0) {
                cart[*itemCount] = price * quantity;
                (*itemCount)++;
                printf("Item(s) added to cart.\n");
            } else {
                printf("Invalid quantity. Please enter a positive number.\n");
            }
        } else if (choice != 0) {
            printf("Invalid item number or cart full.\n");
        }
    } while(choice != 0 && *itemCount < MAX_CART_ITEMS);
}

float calculateTotal(float cart[], int itemCount) {
    float total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        total += cart[i];
    }
    return total;
}
