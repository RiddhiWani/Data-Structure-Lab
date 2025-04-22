def students_playing_both(cricket_players, badminton_players):
    both_sports = []
    for student in cricket_players:
        if student in badminton_players:
            both_sports.append(student)
    return both_sports

def students_playing_either(cricket_players, badminton_players):
    either_sports = []
    for student in cricket_players:
        either_sports.append(student)
    for student in badminton_players:
        if student not in cricket_players:
            either_sports.append(student)
    return either_sports

def students_playing_neither(total_students, cricket_players, badminton_players):
    playing_either = students_playing_either(cricket_players, badminton_players)
    not_playing = [student for student in total_students if student not in playing_either]
    return len(not_playing)

def students_playing_cricket_football(cricket_players, football_players):
    cricket_football = []
    for student in cricket_players:
        if student in football_players:
            cricket_football.append(student)
    return cricket_football

# Player lists
cricket_players = [1, 2, 3, 4]
badminton_players = [2, 3, 5, 6]
football_players = [7, 8, 9, 2]

# Create the total students list by merging the three lists
total_students = list(set(cricket_players + badminton_players + football_players))

# Call functions
students_both = students_playing_both(cricket_players, badminton_players)
students_either = students_playing_either(cricket_players, badminton_players)
students_neither = students_playing_neither(total_students, cricket_players, badminton_players)
students_cricket_football = students_playing_cricket_football(cricket_players, football_players)

# Output results
print("students playing both cricket and badminton:", students_both)
print("students playing either cricket or badminton (not both):", students_either)
print("Number of students playing neither cricket nor badminton:", students_neither)
print("students playing cricket and football but not badminton:", students_cricket_football)
