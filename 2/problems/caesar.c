#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string run_cipher(string input);
// string cipher = "NQXPOMAFTRHLZGECYJIUWSKDVB";
string cipher = "YTNSHKVEFXRBAUQZCLWDMIPGJO";
// string cipher = "JTREKYAVOGDXPSNCUIZLFBMWHQ";
char small_alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char big_alpha[] =   {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main(int argc, char *argv[])
{
    // printf("argc: %i\nargv1: %s\n", argc, argv[1]);
    // get key from user in the command line
    // string input = get_string("plaintext: ");
    string input = "HELLO";
    printf("%s\n", input);
    string output = run_cipher(input);
    printf("\n");
}

string run_cipher(string input)
{
    string output = "";
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        char input_letter = input[i];
        for (int j = 0, n = 26; j < n; j++)
        {
            if (input_letter == big_alpha[j]) // Checking what number it is in the alphabet
            {
                printf("%c", cipher[j]); // displaying the same number but from the cipher
                // j is the number to run out of the regular alphabet.
            }
        }
    }
    return output;
}