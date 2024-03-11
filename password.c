#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
int has_uppercase(char *password);
int has_lowercase(char *password);
int has_digit(char *password);
int has_special(char *password);

int main() {
    char password[20];

    printf("Enter a password: ");
    scanf("%s", password);

    // Check the length of the password
    if (strlen(password) != 14) {
        printf("Error: Password should have a length of 14 characters.\n");
        return 1;
    }

    // Check if the password contains any whitespace character
    for (int i = 0; i < strlen(password); i++) {
        if (isspace(password[i])) {
            printf("Error: Password should not contain any whitespace character.\n");
            return 1;
        }
    }

    // Check if the password meets all the criteria
    if (!has_uppercase(password) || !has_lowercase(password) || !has_digit(password) || !has_special(password)) {
        printf("Error: Password should contain at least one uppercase letter, one lowercase letter, one digit, and one special symbol.\n");
        return 1;
    }

    printf("Password is valid.\n");
    return 0;
}

// Function to check if the password contains at least one uppercase letter
int has_uppercase(char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one lowercase letter
int has_lowercase(char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one digit
int has_digit(char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one special symbol
int has_special(char *password) {
    char special[] = "!@#$%^&*()_+-=[]{};:,.<>?";

    for (int i = 0; i < strlen(password); i++) {
        for (int j = 0; j < strlen(special); j++) {
            if (password[i] == special[j]) {
                return 1;
            }
        }
    }
    return 0;

}

