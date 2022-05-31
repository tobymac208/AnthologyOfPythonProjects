# Rock, Paper, Scissors and the computer plays.
import random as rn

def prompt_user_for_number(maximum_value_for_the_guess):
    the_number = users_choice = int(input("I want the computer to guess "))
    if the_number < 1 or the_number > maximum_value_for_the_guess:
        # bad answer. Provide a random number.
        the_number = rn.randint(1, maximum_value_for_the_guess)
        print(f"Well, that's not going to work. I've chosen {the_number}")
    
    return the_number

def play():
    # initialize the game's variables
    guessing_range = 100
    guesses = 5
    playing = True

    # prompt a number
    print(f"Give me a number between 1 and {guessing_range}. I want to see if the computer can guess it.")
    users_choice = prompt_user_for_number(guessing_range)

    # have the computer play the game. It's not going to learn yet...
    min_value = 1
    max_value = guessing_range
    total = 0

    while playing:
        computers_guess = rn.randint(min_value, max_value)
        guesses -= 1
        total += 1

        if guesses < 1:
            print("Warning: No more guesses after this, computer.")
            playing = False

        if computers_guess < users_choice:
            # what was the number? Well, only guess between that number and the max now.
            print(f"The computer was too low. {computers_guess} total: {total}")
            # change the minimum value to be the current guess.
            min_value = computers_guess
        elif computers_guess > users_choice:
            print(f"The computer was too high. {computers_guess} total: {total}")
            # narrow the higher range down to the current guess.
            max_value = computers_guess
        else:
            print("The computer guessed it!")
            playing = False

if __name__ == "__main__":
    play()
