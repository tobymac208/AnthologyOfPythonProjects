import string
import random as rn

def generate_passwords(number_of_passwords, length_of_passwords):
    # contains the list that will be returned to the caller
    passwords_list = []

    # "password bank" is a large string of possible characters for the password
    password_bank = string.ascii_lowercase + string.ascii_uppercase + "0123456789@#$&"

    # run through all of the passwords that need to be created
    for i in range(number_of_passwords):
        current_password = ""
        # generate a password
        for i in range(length_of_passwords):
            # append a random uppercase letter to the password
            current_password += rn.choice(password_bank)
        passwords_list.append(current_password)
    return passwords_list


if __name__ == "__main__":
    users_name = input("Hello there. Can I get a name to know who I'm talking to? ")
    print(f"Hello there, {users_name}.")

    # number of passwords
    passwords_n = int(input(f"Now {users_name}, I'll need to know how many passwords you'd like. "))

    # lengths for passwords
    length_of_passwords = int(input(f"Ok {users_name}, now I'll just need see know the length of all of those passwords. "))

    # generate the user's passwords, using the generate_passwords() function above. 
    users_passwords = generate_passwords(passwords_n, length_of_passwords)

    print("Here are your passwords!")
    # give the user their passwords
    for password in users_passwords:
        print(f"-> {password}")
