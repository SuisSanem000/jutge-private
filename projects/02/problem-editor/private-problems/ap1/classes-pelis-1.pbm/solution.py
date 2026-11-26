from dataclasses import dataclass


@dataclass
class Movie:
    title: str
    year: int
    stars: int
    earnings: float


def compare_movies(m1: Movie, m2: Movie) -> int:
    if m1.stars > m2.stars:
        return -1
    elif m1.stars < m2.stars:
        return 1
    elif m1.earnings > m2.earnings:
        return -1
    elif m1.earnings < m2.earnings:
        return 1
    elif m1.year > m2.year:
        return -1
    elif m1.year < m2.year:
        return 1
    else:
        return 0
