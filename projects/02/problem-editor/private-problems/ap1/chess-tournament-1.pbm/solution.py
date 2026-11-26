from yogi import read, scan


def add(dic, player):
    if player in dic:
        dic[player] += 1
    else:
        dic[player] = 1


def value(name, dic):
    if name in dic:
        return dic[name]
    return 0


def write_results(names, dic_wins, dic_draws, dic_defeats):
    names.sort()
    for nom in names:
        print(nom, value(nom, dic_wins), value(nom, dic_draws),
              value(nom, dic_defeats))


n = read(int)
names = []
for i in range(n):
    names.append(read(str))
dic_wins, dic_draws, dic_defeats = {}, {}, {}
player1 = scan(str)
while player1 is not None:
    player2 = read(str)
    result = read(str)
    if result == '1-0':
        add(dic_wins, player1)
        add(dic_defeats, player2)
    elif result == '0-1':
        add(dic_wins, player2)
        add(dic_defeats, player1)
    else:
        add(dic_draws, player1)
        add(dic_draws, player2)
    player1 = scan(str)
write_results(names, dic_wins, dic_draws, dic_defeats)
