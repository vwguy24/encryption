#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 500
//Initialize variables
char message[500];
int shift = 3;
//Initialize functions
int getUserChoice();
int getShift();
void getString(char buf[]);
void encrypt(char buf[], int shift);
void decrypt(char buf[], int shift);

int main()
{
    //Only need one function in main, as it branches to others
    getUserChoice();

	return 0;
}
//Function everything branches from
int getUserChoice()
{
    //Initialize variable needed
    int choice;
    //Set up a menu
    printf("-------------------------------\n");
    printf("| 1) Change Shift (default 3) |\n");
    printf("| 2) Encrypt a message        |\n");
    printf("| 3) Decrypt a message        |\n");
    printf("| 4) Quit                     |\n");
    printf("-------------------------------\n");
    //Ask for item
    printf("Option: ");
    scanf("%d", &choice);
    //Make sure they answer inside parameters
    if (choice < 5 && choice > 0){
        //Tests the input
        switch (choice) {
            case 1:
                getShift();
                getUserChoice();
                break;
            case 2:
                getString(message);
                encrypt(message, shift);
                getUserChoice();
                break;
            case 3:
                getString(message);
                decrypt(message, shift);
                getUserChoice();
                break;
            case 4:
                break;
        }
    }
    //If out of parameters it gives warning and restarts
    else {
        printf("That is not a viable selection.\n\n\n");
        getUserChoice();
    }
}
//Function to change shift
int getShift()
{
    //Ask for shift amount
    printf("Input: ");
    scanf(" %d", &shift);
    printf("\n\n\n");
}
//Function to get String
void getString(char buf[])
{
    //Ask for string
    printf("Input: ");
    scanf(" %[^\n]s", buf);
}
//Function to encrypt String
void encrypt(char buf[], int shift)
{
    //Initialize needed variables
    int i;
    //For loop to go through each character in the string
    for (i = 0; i < strlen(buf); i++){
        //If statement to make sure the character isn't a space
        if (buf[i] != ' ') {
                buf[i] = buf[i] - shift;
        }
    }
    //Print out the encrypted string
    printf("Output:  %s\n\n\n", buf);
}
//Function to decrypt a string
void decrypt(char buf[], int shift)
{
    //Initialize variables
    int i;
    //For loop to go through each character in the string
    for(i = 0; i < strlen(buf); i ++) {
        //If statement to make sure the character isn't a space
        if (buf[i] != ' ') {
                buf[i] = buf[i] + shift;
        }
    }
    //Print out the decrypted string
    printf("Output:  %s\n\n\n", buf);
}
