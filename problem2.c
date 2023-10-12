/*
Zachary Willingham
zwillingham04@ku.edu
10/13/2023
Lab 5 Problem 2

The programming lab assignment requires reading an NFL game score by a team and determining the scoring possibilities. A score is expected to be 2 or higher. Thus, the program should stop if a score less than 2 is entered.
*/
#include <stdio.h>
#include <stddef.h>

int main() {
    int valid_score = 1; // Variable to control the loop, initially set to 1 to start the loop
    while (valid_score) { // Enter the loop
        printf("Enter 0 or 1 to STOP\n");
        int score; // Variable to store the user input score
        printf("Enter a score: ");
        scanf("%d", &score); // Read user input for the score
        
        if (score <= 1) { // If the entered score is less than or equal to 1
            valid_score = 0; // Set valid_score to 0 to exit the loop
        }
        
        printf("Possible combinations of scoring plays:\n");
        int conversions, extra_points, touchdowns, field_goals, safeties; // Variables for different types of scoring plays
        
        // Nested loops to iterate through all possible combinations of scoring plays
        for (conversions = score / 8; conversions >= 0; conversions--) { // Loop for 8-point conversions
            for (extra_points = (score - conversions * 8) / 7; extra_points >= 0; extra_points--) { // Loop for 7-point extra points
                for (touchdowns = (score - conversions * 8 - extra_points * 7) / 6; touchdowns >= 0; touchdowns--) { // Loop for 6-point touchdowns
                    for (field_goals = (score - conversions * 8 - extra_points * 7 - touchdowns * 6) / 3; field_goals >= 0; field_goals--) { // Loop for 3-point field goals
                        for (safeties = (score - conversions * 8 - extra_points * 7 - touchdowns * 6 - field_goals * 3) / 2; safeties >= 0; safeties--) { // Loop for 2-point safeties
                            int total = conversions * 8 + extra_points * 7 + touchdowns * 6 + field_goals * 3 + safeties * 2; // Calculate the total score
                            if (total == score) { // If the total score matches the user input score
                                // Print the combination of scoring plays
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", conversions, extra_points, touchdowns, field_goals, safeties);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0; // Exit the program
}