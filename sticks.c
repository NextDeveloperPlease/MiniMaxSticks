#include <stdio.h>
#include <stdlib.h>

int add_hand(int hands[], int curr_hand[], int length) {
    int next_index = 0;
    // printf("Length: %d\n", length);
    for (int i = 0; i < length; i+=2) {
        int j = i + 1;
        if (hands[i] == -1) {
            next_index = i;
            break;
        }
        else if (hands[j] == -1) {
            next_index = j;
            break;
        }
        // printf("i:%d - %d, j:%d - %d", i, hands[i], j, hands[j]);
        // printf("i,j: %d,%d\n hands: %d,%d\n", i, j, hands[i], hands[j]);
        if (hands[i] == curr_hand[0] && hands[j] == curr_hand[1]) {
            // printf("ENTERED");
            return 1;
        }
    }
    hands[next_index] = curr_hand[0];
    hands[++next_index] = curr_hand[1];
    return 0;
}

int calc_score(int curr_hands[], int opp_hands[], int possible_hands[], int level, int array_length) {
    // printf("a:%d, b:%d\n", curr_hands[0], curr_hands[1]);
    // if (curr_hands[0] == 0 && curr_hands[1] == 0) {
    //     return -1;
    // }
    // printf("level:%d\ncurr_hand: %d, %d\nopp_hand: %d, %d\n", level, curr_hands[0], curr_hands[1], opp_hands[0], opp_hands[1]);

    if (opp_hands[0] == 0 && opp_hands[1] == 0) {
        // printf("curr_hand: %d, %d\nopp_hand: %d, %d\n", curr_hands[0], curr_hands[1], opp_hands[0], opp_hands[1]);
        return 1;
    }
    // else if (add_hand(possible_hands, opp_hands)) {
    //     printf("curr_hand: %d, %d\nopp_hand: %d, %d\n", curr_hands[0], curr_hands[1], opp_hands[0], opp_hands[1]);
    //     return 0;
    // }
    else {
        int a_opp[2] = {(curr_hands[0] + opp_hands[0]) % 5, opp_hands[1]};
        int a_score = 0;
        if (!add_hand(possible_hands, a_opp, array_length)) {
            a_score = -calc_score(a_opp, curr_hands, possible_hands, level+1, array_length);
            printf("Score: %d\n", a_score);
        }
        int b_opp[2] = {opp_hands[0], (opp_hands[1] + curr_hands[0]) % 5};
        int b_score = 0;
        if (!add_hand(possible_hands, b_opp, array_length)) {
            b_score = -calc_score(b_opp, curr_hands, possible_hands, level+1, array_length);
            printf("Score: %d\n", b_score);
        }
        int c_opp[2] = {(curr_hands[1] + opp_hands[0]) % 5, opp_hands[1]};
        int c_score = 0;
        if (!add_hand(possible_hands, c_opp, array_length)) {
            c_score = -calc_score(c_opp, curr_hands, possible_hands, level+1, array_length);
            printf("Score: %d\n", c_score);
        }
        int d_opp[2] = {opp_hands[0], (opp_hands[1] + curr_hands[1]) % 5};
        int d_score = 0;
        if (!add_hand(possible_hands, d_opp, array_length)) {
            d_score = -calc_score(d_opp, curr_hands, possible_hands, level+1, array_length);
            printf("Score: %d\n", d_score);
        }
        // bump
        return a_score + b_score + c_score + d_score;
    }
}

int main(int argc, char *argv[]) {
    int a[2] = {1,1};
    int b[2] = {1,1};
    int possible_hands[50] = {};
    for (int i = 0; i < 50; i++) {
        possible_hands[i] = -1;
    }
    int array_length = 50;
    int score = calc_score(a, b, possible_hands, 0, array_length);
    printf("Score: %d\n", score);
    // printf("Hello World\n");
    return 0;
}