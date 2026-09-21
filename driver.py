f_hands = [1,1]
s_hands = [1,1]

def calc_score(curr_hands, opp_hands) -> int:
    if curr_hands == [0,0]:
        print("curr_wins")
        return 1
    elif s_hands == [0,0]:
        print("opp_wins")
        return -1
    else:
        a_opp = [(opp_hands[0] + curr_hands[0]) % 5, opp_hands[1]]
        b_opp = [opp_hands[0], (opp_hands[1] + curr_hands[0]) % 5]
        c_opp = [(opp_hands[0] + curr_hands[1]) % 5, opp_hands[1]]
        d_opp = [opp_hands[0], (opp_hands[1] + curr_hands[1]) % 5]
        return calc_score(a_opp, curr_hands) + calc_score(b_opp, curr_hands) + calc_score(c_opp, curr_hands) + calc_score(d_opp, curr_hands)


if __name__ == '__main__':
    calc_score(f_hands, s_hands)