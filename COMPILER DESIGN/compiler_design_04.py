
road = dict()
state = input().split(' ')
parameter = input().split(' ')

for i in state:
    temp = dict()
    for j in parameter:
        print(f'{i} {j}:', end=' ')
        value = input()
        temp[j] = value
    road[i] = temp

roadmap = [state[0]]
str = input()

for i in str:
    try:
        current = roadmap[-1]
        next = road[current][i]
        roadmap.append(next)
    except:
        print("not valid")

if roadmap[-1] == state[-1]:
    print(roadmap)
else:
    print('reject')


# road = {
#     0: {'a': 1, 'b': 0},
#     1: {'a': 1, 'b': 2},
#     2: {'a': 1, 'b': 3},
#     3: {'a': 1, 'b': 0}
# }

# 0 1 2 3
# a b
# 0 a: 1
# 0 b: 0
# 1 a: 1
# 1 b: 2
# 2 a: 1
# 2 b: 3
# 3 a: 1
# 3 b: 0
# aabb