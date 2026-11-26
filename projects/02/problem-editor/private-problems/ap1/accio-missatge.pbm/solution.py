
def missatge(qui: str, verb: str, cops: int, fem: bool) -> None:
    if cops == 0:
        if fem:
            text = f'Na {qui} no ha {verb}.'
        else:
            text = f'En {qui} no ha {verb}.'
    elif cops == 1:
        if fem:
            text = f'Na {qui} ha {verb} 1 cop.'
        else:
            text = f'En {qui} ha {verb} 1 cop.'
    else:
        if fem:
            text = f'Na {qui} ha {verb} {cops} cops.'
        else:
            text = f'En {qui} ha {verb} {cops} cops.'
    print(text)
