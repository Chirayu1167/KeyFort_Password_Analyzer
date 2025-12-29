#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// BAR
void print_bar(float score, float max_score) {
    int bar_width = 25; // width of the bar
    int filled = (int)((score / max_score) * bar_width);

    printf("[");
    for (int i = 0; i < bar_width; i++) {
        if (i < filled) printf("█"); // filled block
        else printf(" ");             // empty space
    }
    printf("] %.2f/%.2f\n", score, max_score);
}

int main(){
        system("chcp 65001 > nul");
    printf("************************************************************\n");
    printf("*    🛡️   KEYFORT — Your First Line of WiFi Defense  🛡️      *\n");
    printf("************************************************************\n");
    printf("       Checking password durability and complexity\n");
    printf("------------------------------------------------------------\n\n");
    printf("Enter your password (Max length = 18 characters : Min lenght = 5 characters): ");
    char password[19];
    scanf("%s",password);
    password[strcspn(password, "\n")] = '\0';
    
    //Lenght
    int lenght_password = strlen(password);
    int lenght_point = 0;
    if (lenght_password < 5)
    {
        printf("Minimum lenght of password is set to 5 characters!\nYour password has %d characters\n",lenght_password);
    }
    else if (lenght_password >= 5 && lenght_password <=18)
    {
        lenght_point = 2*lenght_password;
    }
    else
    {
        printf("Maximum lenght of password is set to 18 characters!\nYour password has %d characters\n",lenght_password);
    }
    if (lenght_password <= 18 && lenght_password > 15)
    {
        lenght_point += 3;
    }
    else if (lenght_password <= 15 && lenght_password > 12)
    {
        lenght_point += 2;
    }
    else if (lenght_password <= 12 && lenght_password > 9)
    {
        lenght_point += 1;
    }
    float lenght_point_f = (float)lenght_point;

    // Character count
    int L = 0, U = 0, D = 0, SP = 0;
    int lowerp = 0, upperp = 0, digitp = 0, special = 0;
    float Varpoints = 0;
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (islower(password[i]))
        {
            L += 1;
            lowerp += 4;
        }
        else if (isupper(password[i]))
        {
            U += 1;
            upperp += 4;
        }
        else if (isdigit(password[i]))
        {
            D += 1;
            digitp += 4;
        }
        else 
        {
            SP += 1;
            special += 4;
        }
    }
    Varpoints = lowerp + upperp + digitp + special;
    if (L == 0)
    {
        Varpoints -= 1.5;
    }
    else if (L == 1)
    {
        Varpoints -= 1;
    }
    else if (L == 2)
    {
        Varpoints -= 0.5;
    }
    else if (L > 4)
    {
        Varpoints += 1.5;
    }
    if (D == 0)
    {
        Varpoints -= 1.5;
    }
    else if (D == 1)
    {
        Varpoints -= 1;
    }
    else if (D == 2)
    {
        Varpoints -= 0.5;
    }
    else if (D > 4)
    {
        Varpoints += 1.5;
    }
    if (U == 0)
    {
        Varpoints -= 1;
    }
    else if (U == 1)
    {
        Varpoints -= 0.5;
    }
    else if (U > 3)
    {
        Varpoints += 1.5;
    }    
    if (SP == 0)
    {
        Varpoints -= 1;
    }
    else if (SP == 1)
    {
        Varpoints -= 0.5;
    }
    else if (SP > 3)
    {
        Varpoints += 1.5;
    }
    float Varpoints_f = (float)Varpoints;
    
    // Repetition points
    int repeat = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        for (int j = i + 1; password[j] != '\0'; j++) {
            if (password[i] == password[j]) {
                repeat++;
            }
        }
    }
    float repeat_penalty = (float)2*repeat;

    // Sequential penalty
    int seq_penalty = 0;
    for(int i = 0; password[i+2] != '\0'; i++){
        // check ascending sequences for letters
        if(password[i+1] == password[i]+1 && password[i+2] == password[i]+2) seq_penalty += 1;
        // check ascending sequences for digits
        if(isdigit(password[i]) && isdigit(password[i+1]) && isdigit(password[i+2])){
            if(password[i+1] == password[i]+1 && password[i+2] == password[i]+2) seq_penalty += 1;
        }
    }
    float seq_penalty_f = (float)seq_penalty;
    
    // Total points
    float Total = lenght_point_f + Varpoints_f - repeat_penalty - seq_penalty_f;
    float T = Total/10;
    if (T < 0)
    {
        T = 0;
    }
    else if (T > 10)
    {
        T == 10;
    }
    if (T < 3)
    {
        printf("\nSTRENGHT RATING: Weak\n");
    }
    else if (T < 6)
    {
        printf("\nSTRENGHT RATING: Weak-Moderate\n");
    }
    else if (T < 8)
    {
        printf("\nSTRENGHT RATING: Moderate-Strong\n");
    }
    else if (T <= 10)
    {
        printf("\nSTRENGHT RATING: Strong\n");
    }
    print_bar(T, 10);
    printf("\n\nAnalysis:\n");
    printf("Password Length: %d\nNumber of lowercase characters: %d\nNumber of uppercase characters: %d\nNumber of digits: %d\nNumber of special characters: %d\n",lenght_password,L,U,D,SP);
    if ( L<=2 || U <= 1 || D <= 2 || SP <=1)
    {
        printf("\n\nTips for strengthening your password:\n");
    }
    if (L <= 2)
    {
        printf("Try adding more lowercase letters as your password only containes %d\n",L);
    }
    if (U<=1)
    {
        printf("Try adding more uppercase letters as your password only containes %d\n",U);
    }
    if (D <= 2 )
    {
        printf("Try adding more digits as your password only containes %d\n",D);
    }
    if (SP <= 1)
    {
        printf("Try adding more special characters as your password only containes %d\n",SP);
    }    
    return 0;
}