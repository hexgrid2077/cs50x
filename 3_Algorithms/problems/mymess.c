#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    int votes;
} candidate;

int main(int argc, char *argv[])
{
    int total_candidates = argc - 1;
    // setup a data struct off the argv's
    candidate candidates[argc]; // array of amount of candidates
    int total_voters = get_int("Number of voters: "); // get_vote_amount function
    int to_win = total_voters / total_candidates;
    printf("Candidates: %i\n", total_candidates);
    printf("To win you need more than: %i vote(s)\n", to_win);
    
    for (int i = 0; i < total_voters; i++) // Go through all the voters
    {
        string current_vote = get_string("Vote: ");
        for (int j = 0; j < total_candidates; j++)// check if current vote is a valid candidate
        {
            if (strcmp(argv[j], current_vote))
            {
                printf("Invalid Vote.\n");
            }
        }
    }

    //when the vote input asks the user (get_vote) add one to that name
    // when the candidate hits the to_win number it prints their name and they won.

}