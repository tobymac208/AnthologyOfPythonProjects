import time as tm

timers_seconds = int(input("Seconds for your timer: "))
reminder = "Go for a run now!"

while timers_seconds > 0:
    days = int(timers_seconds/86400)
    hours = int( (timers_seconds % 86400) / 3600 )
    # calculate the number of minutes remaining after we remove the hours portion.
    minutes = int( (timers_seconds % 3600) / 60)
    # calculates the number of seconds remaining
    seconds = int( (timers_seconds % 3600) % 60 )

    print(f"{days}:{hours}:{minutes}:{seconds}")

    tm.sleep(1)
    
    timers_seconds -= 1

# Give the user some encouragement for the break time.
print(reminder)
