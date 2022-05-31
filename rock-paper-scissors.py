# Rock, Paper, Scissors
# logic: r > s, p > r, s > p

import random as rn
import time as tm

def welcome_message():
    print("Here we are again. This time, we're going to play Rock, Paper, Scissors. Before we begin, I'll lay out the rules nicely, in the off chance you've never played.")
    tm.sleep(1)
    print("Paper beats rock. Rock beats scissors. Scissors beat paper. So, in order to test what I've told you, I'll throw this one your way.")
    tm.sleep(1)
    print("If I pull rock and you pull scissors, who wins? (Y)ou or (M)e?")

    users_response = input("").lower()
    if users_response == "y":
        print("Yes, that's correct. I win in that scenario.")
    elif users_response == "m":
        print("You wish! I'd win.\n")

    print("Regardless of how you did, we're going to play now.\n")

def play_game():
    playing = True
    rounds = 3
    users_score = 0
    computers_score = 0

    print("Simple directions here: Either choose rock, paper, or scissors. There's nothing more to it than that. Here we go!")

    while playing:
        users_choice = input("1) Rock, 2) Paper, 3) Scissors: ").strip()
        if users_choice == "1": users_choice = "rock"
        elif users_choice == "2": users_choice = "paper"
        else: users_choice = "scissors"

        computers_choice = rn.choice(("rock", "paper", "scissors"))
        rounds -= 1

        if users_choice == "rock":
            if computers_choice == "paper":
                print("Computer wins a round.")
                computers_score += 1
            elif computers_choice == "scissors":
                print("You win a round.")
                users_score += 1
            else: pass # don't do anything, it's a tie
        elif users_choice == "paper":
            if computers_choice == "scissors":
                print("Computer wins a round.")
                computers_score += 1
            elif computers_choice == "rock":
                print("You win a round.")
                users_score += 1
            else: pass
        elif users_choice == "scissors":
            if computers_choice == "rock":
                print("Computer wins a round.")
                computers_score += 1
            elif computers_choice == "paper":
                print("You win a round.")
                users_score += 1
            else: pass

        if rounds < 1:
            playing = False

    if users_score > computers_score:
        print("You won!")
    elif users_score < computers_score:
        print("You lost!")
    else:
        print("It was a tie!")

if __name__ == "__main__":
    welcome_message()
    
    play_game()
