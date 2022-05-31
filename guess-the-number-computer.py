import random as rn

def play():
    guessing_range = 1000

    # generate the correct number
    computers_choice = rn.randint(1, guessing_range)

    # set flag for whether the game is going or not
    playing = True

    # set counter for the number of guesses
    number_of_guesses = 3

    print("Guess the number I'm thinking of. You'll have three guesses. Ready? Begin.")

    while playing:
        guess = int(input(f"Your guess (1-{guessing_range}): "))

        # the user gave odd input
        if guess < 0 or guess > guessing_range:
            print("Invalid input. This guess won't be counted.")
            continue

        # remove one guess
        number_of_guesses -= 1
    
        # no more guesses?
        if number_of_guesses < 1:
            playing = False

        # logic for determining user's accuracy
        if guess < computers_choice:
            print("Your guess is too low.")
        elif guess > computers_choice:
            print("Your guess is too high!")
        else:
            print(f"{guess} was the correct number! Game over.")
            playing = False

if __name__ == "__main__":
    play()
