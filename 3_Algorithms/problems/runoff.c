#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);
int get_vote(int voter);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
            // else
            //     printf("Voter valid.\n");
        }
        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        printf("Tabulating...\n");
        tabulate();
        printf("Done tabulating...\n");
        // return 0;

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        printf("min is... %i\n", min);
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // First check if candidate found:
    for (int i = 0; i < candidate_count; i++)
    {
        if (!strcmp(candidates[i].name, name))
        {
            // Then record the candidate in preferences, the voter's 2d array.
            preferences[voter][rank] = i;
            // preferences[voter][rank] = candidate[1].name;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // loop through all VOTERS
    printf("Tabulate: looping through all voters...\n");
    for (int voter = 0; voter < voter_count; voter++)
    {
        // Get the top vote candidate using the get_vote function
        int candidate_to_vote_for = get_vote(voter);
        printf("We think the candidate to vote for is: %i\n", candidate_to_vote_for);
        // add that vote
        candidates[candidate_to_vote_for].votes += 1;
    }
    return;
}

int get_vote(int voter) // TODO still have to prototype this too.
{
    int candidate_to_vote_for;
    // loop through the preferences array til you find a candidate that's not eliminated
    for (int i = 0; i < candidate_count; i++)
    {
        while (true)
        {
            int candidate_check = preferences[voter][i]; // shortening this up because it's a long one.
            if (!candidates[candidate_check].eliminated)
                // return the candidate they're voting for.
                return candidate_check; // be done. End of loop for that voter.
        }
        // return the top candidate for that voter.
        // get out so the loop stops.
    }
    return candidate_to_vote_for; // It shouldn't actually get here i just had to return an int.
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Check if there's a winner.
    // figure out what amount of votes you'd need and if they have it, then you're done.
    int winning_vote_count = voter_count / 2;
    printf("Well, you need over %i votes to win.\n", winning_vote_count);
    // go thru candidates and find out non-eliminated ones and then see if their votes are win it.
    for (int i = 0; i < voter_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes > winning_vote_count)
            {
                printf("AND THE WINNER IS... %s\n", candidates[i].name);
                return true;
            }
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int lowest_votes;
    // Find the one candidate with the lowest votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < lowest_votes)
        lowest_votes = i;
    }
    printf("The lowest number of votes is %s with %i votes.\n", candidates[lowest_votes].name, candidates[lowest_votes].votes);
    return candidates[lowest_votes].votes;
}

// Return true if the election is tied between all candidates, false otherwise

bool is_tie(int min)
{
    // figure out if any candidates have the same number.
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        if (candidates[i].eliminated == false && candidates[j].eliminated == false)
        {
            if (candidates[i].name != candidates[j].name && candidates[i].votes == candidates[j].votes)
            {
                printf("Tie with %s and %s\n", candidates[i].name, candidates[j].name);
                return true;
            }
        }
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
            printf("Eliminating %s\n", candidates[i].name);
        }
    }
    return;
}


/*
preferences[voter][candidate preference] = whichever candidate

./runoff alice bob charlie
preference[0][1] = 0
First voter, second preference = alice (candidate 0)

preferences[2][0] = 1
third voter, first preference is bob (candidate 1)

so it'll be like this order
voter 1: if you're going Alice then Bob then Charlie in that order:
preference[0][0] = 0;
preference[0][1] = 1;
preference[0][2] = 2;

WORKING ON TABULATE -- Call line 89; function line 145
*/ 