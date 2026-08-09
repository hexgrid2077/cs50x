#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string run_cipher(string input, string cipher);
// string cipher = "NQXPOMAFTRHLZGECYJIUWSKDVB";
// string cipher = "YTNSHKVEFXRBAUQZCLWDMIPGJO";
// string cipher = "JTREKYAVOGDXPSNCUIZLFBMWHQ";
char small_alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char big_alpha[] =   {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main(int argc, char *argv[])
{
    string cipher = argv[1];
    if (argc < 2)
    {
        printf("Usage: ./substutition [key]\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string input = get_string("plaintext: ");
    // string input = "HELLO";
    printf("ciphertext: ");
    string output = run_cipher(input, cipher);
    printf("\n");
}

string run_cipher(string input, string cipher)
{
    string output = "";
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        char input_letter = input[i];
        for (int j = 0, n = 26; j < n; j++)
        {
            if isupper(input_letter)
            {
                if (input_letter == big_alpha[j]) // Checking what number it is in the alphabet
                {
                    printf("%c", cipher[j]); // displaying the same number but from the cipher
                    // j is the number to run out of the regular alphabet.
                }
            }
            else if islower(input_letter)
            {
                if (input_letter == small_alpha[j]) // Checking what number it is in the alphabet
                {
                    printf("%c", tolower(cipher[j])); // displaying the same number but from the cipher
                    // j is the number to run out of the regular alphabet.
                }
            }
        }
    }
    return output;
}