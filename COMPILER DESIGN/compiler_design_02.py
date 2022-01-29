# https://www.hackerrank.com/contests/02-nfa-sec-a/challenges/help-nfa/problem

def verify(sequences, available_passes, final_player):
    current_position = [0]
    ans = "miss"

    for j in sequences:
        current_position_new = list()
        value = list(available_passes[j].keys())
        value2 = list(set(value).intersection(current_position))
        for k in value2:
            current_position_new += available_passes[j][k]
        current_position = current_position_new

    if final_player in current_position:
        ans = "goal"

    return ans


total_number_of_player = int(input())
jersey_numbers_of_the_each_player = input().split(' ')
jersey_numbers_of_the_each_player = [int(i) for i in jersey_numbers_of_the_each_player]
total_types_of_passes_players_can_give = int(input())
name_of_the_pass_types = input().split(' ')
total_number_of_passes_available_between_players = int(input())

available_passes = dict()
for i in range(total_number_of_passes_available_between_players):
    value = input().split(' ')
    value[0], value[1] = int(value[0]), int(value[1])

    if value[2] not in available_passes:
        available_passes[value[2]] = {value[0]: [value[1]]}
    elif value[0] not in available_passes[value[2]]:
        available_passes[value[2]][value[0]] = [value[1]]
    else:
        available_passes[value[2]][value[0]].append(value[1])

# print(available_passes)
value = input().split(' ')
start_player = int(value[0])
final_player = int(value[1])

number_of_pass_sequeces_to_test = int(input())
for i in range(number_of_pass_sequeces_to_test):
    sequences = input()
    ans = verify(sequences, available_passes, final_player)
    print(ans)


# 4
# 0 1 2 3
# 2
# a b
# 5
# 0 0 a
# 0 0 b
# 0 1 a
# 1 2 b
# 2 3 b
# 0 3
# 3
# ababbb
# aaba
# abba