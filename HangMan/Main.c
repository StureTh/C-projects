#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>



#define arr_size                    80

#define LenghtOfArray(x) (sizeof(x) / sizeof(x)[0])


char main_string[arr_size];
char player_string[arr_size];
char player_chars_used[arr_size];

bool win;

int8_t max_tries;
int8_t tries;
int8_t string_length;
int8_t char_counter = 0;

bool arrayContainsChar(char *array, char ch)
{
    int i;
    bool chr_found = false;

    for(i = 0; i < string_length; i++)
    {
        if(array[i] == ch)
        {
            chr_found = true;
            goto out;
        }
    }

out:
    return chr_found;
}

void PopulateArrays(void)
{
    int i;
    char temp;


    printf("\nEnter desired word: ");
 
    for(i = 0; i < LenghtOfArray(main_string); i++)
    {
        temp = getche();

        if(temp == ' ' || temp == 13)
        {
            break;
        }
        else
        {
            main_string[i] = temp;
            string_length++;
        }
    }
}


void PopulatePlayerArray(char correctChar)
{
    int i;

    for(i = 0; i < string_length; i++)
    {
        if(main_string[i] == correctChar)
        {
            player_string[i] = correctChar;
            char_counter++;
        }
    }
}


void PrintPlayerArray(void)
{
    int i;
    for(i = 0; i < string_length; i++)
    {
        if(isalpha(player_string[i]))
        {
            printf("%c ", player_string[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf(" %d", tries);
    printf("\n");
}


char GetPlayerInput(void)
{
    char player_input;

    printf("Enter your guess: ");
    player_input = getche();

    return player_input;
}

void PrintCharsUsed(void)
{
    int i;
    for(i = 0; i < max_tries; i++)
    {
        printf("%c", player_chars_used[i]);
    }

    printf("\n");
}

void SetMaxTries(void)
{
    int input;
    int temp_max_tries = 0;
    bool inputDone = false;

    printf("Enter max number of tries: ");
    do
    {
        input = getch();
        if(isdigit(input))
        {
            printf("%i", input - '0');

            temp_max_tries *= 10;
            temp_max_tries += (input - '0');
        }
        else if(input == ' ' || input == 13)
        {
            inputDone = true;
        }

    }
    while(!inputDone);

    max_tries = temp_max_tries;
}

bool TriesLeft(void)
{
    bool tries_left = true;

    if(tries >= max_tries)
    {
        tries_left = false;
        printf("\nYou loose! Man is dead\n");
    }
    return tries_left;
}

bool hasWon(void)
{
    bool has_won = false;
    if(char_counter == string_length)
    {
        system("cls");
        PrintPlayerArray();

        printf("GZ!");
        has_won = true;
    }
    return has_won;
}

void InitGame(void)
{
    SetMaxTries();
    PopulateArrays();
}

void StartGame(void)
{
    char playerIn;
    win = false;


    system("cls");
    while(TriesLeft())
    {
        PrintPlayerArray();
        PrintCharsUsed();

        playerIn = GetPlayerInput();

        if(arrayContainsChar(main_string, playerIn))
        {
            if(!arrayContainsChar(player_string, playerIn))
            {
                PopulatePlayerArray(playerIn);
                tries++;

                if(hasWon())
                {
                    return;
                }
            }
        }
        else
        {
            printf("Fel");
            if(!arrayContainsChar(player_chars_used, playerIn))
            {
                player_chars_used[tries] = playerIn;
                tries++;
            }
        }
        system("cls");
    }
    PrintPlayerArray();
    return;
}

int main(int argc, char** argv)
{

    InitGame();
    StartGame();

    return 0;
}









