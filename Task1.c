#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define USER_LENGTH 15
#define PASS_LENGTH 15

typedef struct {
    char username[USER_LENGTH];
    char password[PASS_LENGTH];
} User;

User users[];
int numofUsers = 0;

void registeration() {
   

    User newUser;
    printf("Enter your username: ");
    scanf("%s", newUser.username);

    // Check if the username already exists
    for (int i = 0; i < numofUsers; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf(" This Username already exists. Please Enter a different username.\n");
            return;
        }
    }

    printf("Enter your password: ");
    scanf("%s", newUser.password);

    users[numofUsers] = newUser;
    numofUsers++;

    printf("Registration successful.\n");
}

void login() {
    char username[USER_LENGTH];
    char password[PASS_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < numofUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");
            return;
        }
    }

    printf("Invalid username or password. Please Check that you entered your correct username and password. \n");
}

int main() {
    int answer;

    while (1) {
        printf("1: Register\n");
        printf("2: Login\n");
        printf("3: Exit\n");
        printf("What Process will you choose: ");
        scanf("%d", &answer);

        switch (answer) {
            case 1:
                registeration();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter one of the options (1 ,2 or 3).\n");
        }

        printf("\n");
    }
}