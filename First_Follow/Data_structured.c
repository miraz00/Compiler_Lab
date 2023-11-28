//This Program is for DSA Lovers!!!! Other's shall go for first_follow..c 


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRODUCTIONS 10

// Data structure for a production
struct Production {
    char lhs;
    char rhs[10];
};

// Data structure for a set of terminals
struct TerminalSet {
    char terminals[10];
    int size;
};

// Function prototypes
bool isTerminal(char sym);
bool isNonTerminal(char sym);
void calculateFirst(struct Production productions[], int numProductions, char symbol, struct TerminalSet *firstSet);
void calculateFollow(struct Production productions[], int numProductions, char symbol, struct TerminalSet *followSet);
void printSet(char symbol, struct TerminalSet set);

int main() {
    int numProductions;
    struct Production productions[MAX_PRODUCTIONS];
    char c;
    int choice;

    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);

    if (numProductions > MAX_PRODUCTIONS) {
        printf("Too many productions. Max allowed is %d\n", MAX_PRODUCTIONS);
        return 1;
    }

    // Input productions
    for (int i = 0; i < numProductions; ++i) {
        printf("Enter production number %d (e.g., A=alpha): ", i + 1);
        scanf(" %c=%s", &productions[i].lhs, productions[i].rhs);
    }

    // Main loop for calculating FIRST and FOLLOW sets
    do {
        struct TerminalSet firstSet;
        struct TerminalSet followSet;

        printf("\nEnter symbol to calculate FIRST and FOLLOW for: ");
        scanf(" %c", &c);

        calculateFirst(productions, numProductions, c, &firstSet);
        calculateFollow(productions, numProductions, c, &followSet);

        printf("\nFIRST(%c) = ", c);
        printSet(c, firstSet);

        printf("FOLLOW(%c) = ", c);
        printSet(c, followSet);

        printf("Do you want to continue (Press 1 to continue): ");
        scanf("%d", &choice);
    } while (choice == 1);

    return 0;
}
bool isTerminal(char sym) {
    return !isupper(sym) && sym != 'E'; // 'E' represents epsilon
}

// Function to calculate FIRST set for a symbol
void calculateFirst(struct Production productions[], int numProductions, char symbol, struct TerminalSet *firstSet) {
    // Initialize the firstSet to an empty set
    firstSet->size = 0;

    // Helper function to check if a symbol is a terminal

    // Iterate through productions to find productions with the given symbol as the left-hand side
    for (int i = 0; i < numProductions; ++i) {
        if (productions[i].lhs == symbol) {
            char nextSymbol = productions[i].rhs[0]; // Get the first symbol on the right-hand side

            // If the next symbol is a terminal or epsilon, add it to the FIRST set
            if (isTerminal(nextSymbol) || nextSymbol == '#') {
                firstSet->terminals[firstSet->size++] = nextSymbol;
            } else {
                // Recursive call to calculate FIRST set for the next symbol
                calculateFirst(productions, numProductions, nextSymbol, firstSet);

                // Check if epsilon is in the FIRST set of the next symbol
                bool epsilonInFirst = false;
                for (int j = 0; j < firstSet->size; ++j) {
                    if (firstSet->terminals[j] == '#') {
                        epsilonInFirst = true;
                        break;
                    }
                }

                // If epsilon is in the FIRST set of the next symbol, continue checking the next symbol(s)
                if (epsilonInFirst) {
                    int k = 1;
                    while (epsilonInFirst && productions[i].rhs[k] != '\0') {
                        nextSymbol = productions[i].rhs[k];

                        // If the next symbol is a terminal or epsilon, add it to the FIRST set
                        if (isTerminal(nextSymbol) || nextSymbol == '#') {
                            firstSet->terminals[firstSet->size++] = nextSymbol;
                        } else {
                            // Recursive call to calculate FIRST set for the next symbol
                            calculateFirst(productions, numProductions, nextSymbol, firstSet);

                            // Check if epsilon is in the FIRST set of the next symbol
                            epsilonInFirst = false;
                            for (int j = 0; j < firstSet->size; ++j) {
                                if (firstSet->terminals[j] == '#') {
                                    epsilonInFirst = true;
                                    break;
                                }
                            }
                        }

                        k++;
                    }
                }
            }
        }
    }
}
    bool isNonTerminal(char sym) {
        return isupper(sym);
    }

// Function to calculate FOLLOW set for a symbol
void calculateFollow(struct Production productions[], int numProductions, char symbol, struct TerminalSet *followSet) {
    // Initialize the followSet to an empty set
    followSet->size = 0;

    // Add '$' (end marker) to the FOLLOW set of the start symbol
    if (symbol == 'S') {
        followSet->terminals[followSet->size++] = '$';
    }

    // Helper function to check if a symbol is a non-terminal


    // Iterate through productions to find occurrences of the symbol on the right-hand side
    for (int i = 0; i < numProductions; ++i) {
        char *rhs = productions[i].rhs;
        int rhsLength = strlen(rhs);

        for (int j = 0; j < rhsLength; ++j) {
            if (rhs[j] == symbol) {
                if (j < rhsLength - 1) {
                    // Case 1: Symbol is followed by a terminal
                    if (!isNonTerminal(rhs[j + 1])) {
                        followSet->terminals[followSet->size++] = rhs[j + 1];
                    }
                    // Case 2: Symbol is followed by a non-terminal
                    else {
                        char nextSymbol = rhs[j + 1];

                        // Calculate FIRST set for the non-terminal that follows
                        struct TerminalSet firstOfNext;
                        calculateFirst(productions, numProductions, nextSymbol, &firstOfNext);

                        // Add the terminals in FIRST set of the non-terminal to the FOLLOW set
                        for (int k = 0; k < firstOfNext.size; ++k) {
                            if (firstOfNext.terminals[k] != '#') {
                                followSet->terminals[followSet->size++] = firstOfNext.terminals[k];
                            }
                        }

                        // If 'ε' is in FIRST set of the non-terminal, add the FOLLOW set of the current symbol
                        if (isTerminal(nextSymbol) || firstOfNext.size == 0) {
                            // Recursive call to calculate FOLLOW set for the non-terminal
                            struct TerminalSet followOfNext;
                            calculateFollow(productions, numProductions, nextSymbol, &followOfNext);

                            // Add the FOLLOW set of the non-terminal to the current FOLLOW set
                            for (int k = 0; k < followOfNext.size; ++k) {
                                followSet->terminals[followSet->size++] = followOfNext.terminals[k];
                            }
                        }
                    }
                } else {
                    // Case 3: Symbol is at the end of the production
                    char lhsOfProduction = productions[i].lhs;

                    if (lhsOfProduction != symbol) {
                        // Recursive call to calculate FOLLOW set for the left-hand side of the production
                        struct TerminalSet followOfLHS;
                        calculateFollow(productions, numProductions, lhsOfProduction, &followOfLHS);

                        // Add the FOLLOW set of the left-hand side to the current FOLLOW set
                        for (int k = 0; k < followOfLHS.size; ++k) {
                            followSet->terminals[followSet->size++] = followOfLHS.terminals[k];
                        }
                    }
                }
            }
        }
    }
}

// Function to print a set of terminals
void printSet(char symbol, struct TerminalSet set) {
    printf("{ ");
    for (int i = 0; i < set.size; ++i) {
        printf("%c ", set.terminals[i]);
    }
    printf("}\n");
}
