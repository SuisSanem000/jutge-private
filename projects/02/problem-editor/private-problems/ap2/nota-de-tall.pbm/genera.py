import random

nb_estudiants = 1000
nb_titulacions = 50
max_places = 100
max_titulacions = 8

titulacions = [f't{i}' for i in range(nb_titulacions)]

print(nb_estudiants)
for i in range(nb_estudiants):
    random.shuffle(titulacions)
    print('\t', f'e{i}', random.randint(10_000_000, 99_999_999), random.randint(
        500, 1000) / 100, ','.join(titulacions[:random.randint(1, max_titulacions)]))

print(nb_titulacions)
for titulacio in titulacions:
    print('\t', titulacio, random.randint(1, max_places))
