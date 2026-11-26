import random

random.seed(0)

n = 1000
print(n)
for i in range(n - 1, -1, -1):
    print('name' + str(i))
for i in range(5000):
    player_1 = 'name' + str(random.randint(0, n - 1))
    player_2 = 'name' + str(random.randint(0, n - 1))
    if player_1 != player_2:
        result = random.choice(['1-0', '0-1', '1/2-1/2'])
        print(player_1, player_2, result)
