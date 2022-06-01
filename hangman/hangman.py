import random as rn
import string
from words import words

# Returns a valid (lowercase) word from a list of words. "Valid" is defined as "a word having no hyphens or spaces."
def get_valid_word():
    word = rn.choice(words)

    while '-' in word or ' ' in word:
        word = rn.choice(words)

    return word.lower()

def hangman():
    # the word itself
    word = get_valid_word()
    # the correct letters for the word
    word_letters = set(word)
    # all letters the user could use
    alphabet = set(string.ascii_lowercase)
    # the letters the user has used
    used_letters = set()

    lives = 6

    while len(word_letters) > 0 and lives > 0:
        word_letters = [letter if letter in used_letters else '-' for letter in word]
        print(" ".join(word_letters))

        # grabbing 0th item to force only one letter at a time.
        guess = input("Next letter: ")[0].lower()

        # check used letter against the alphabet, forcing only usable characters to be used
        if guess in alphabet - used_letters:
            used_letters.add(guess)
            # the user has guessed a letter!
            if guess in word_letters:
                # force lowercase. This avoids a KeyError
                word_letters.remove(guess)
            else:
                # You lost a life!
                lives -= 1

        elif guess in used_letters:
            print("You've already guessed {0}".format(guess))
        else:
            print("Invalid input. {0} is not a character you can guess.".format(guess))

        print("You've used these letters: ", " ".join(used_letters))
    
    if lives < 1:
        print("You hung the man.")
    else:
        print(f"You guessed the word \"{word}\"!")

if __name__ == '__main__':
    hangman()
