import yogi
from dataclasses import dataclass
from functools import cmp_to_key


@dataclass
class Song:
    name: str
    artist: str
    times_listened: int
    duration_in_sec: int


def read_song() -> Song:
    """Funcio per llegir una cançó."""

    name = yogi.read(str)
    artist = yogi.read(str)
    times_listened = yogi.read(int)
    duration_in_sec = yogi.read(int)
    return Song(name, artist, times_listened, duration_in_sec)


def read_songs(n: int) -> list[Song]:
    """Funcio per llegir una llista d'n cançons."""

    return [read_song() for _ in range(n)]


def comp_by_two_keys(t1: tuple[int, str], t2: tuple[int, str]) -> int:
    """Aquesta funcio compara t1 i t2. Primer compara l'enter, en cas
    d'empat compara per string. Diem que t1 > t2 si l'enter de t1 és més gran
    o (en cas d'empat) si l'string va abans en ordre lexicogràfic.
    Retorna:
        Nombre positiu si t1 > t2
        0              si t1 == t2
        Nombre negatiu si t1 < t2
    """
    if t1[0] == t2[0]:
        if t1[1] > t2[1]:
            return -1
        elif t1[1] < t2[1]:
            return 1
        else:
            return 0
    else:
        return t1[0] - t2[0]


def sum_minutes(songs: list[Song]) -> int:
    """Funcio que calcula quants minuts s'han escoltat en total, donada una llista de cancons"""

    return sum([song.duration_in_sec * song.times_listened for song in songs]) // 60


def compute_top_artists(songs: list[Song]) -> list[str]:
    """Aquesta funcio calcula els 5 artistes mes escoltats dins la llista de
    cancons.
      * Precondicio hi ha mes de 5 artistes diferents.
    """

    pre_result: list[tuple[int, str]] = list()
    sort_by_artist = sorted(songs, key=lambda x: x.artist)
    current_artist = sort_by_artist[0].artist
    current_total = 0
    for song in sort_by_artist:
        if current_artist == song.artist:
            current_total += song.times_listened * song.duration_in_sec
        else:
            pre_result.append((current_total, current_artist)
                              )  # guardar el que teniem
            # inicialitzar el seguent
            current_artist = song.artist
            current_total = song.times_listened * song.duration_in_sec
    pre_result.append((current_total, current_artist))  # append l'ultim

    sort_by_times_listened = sorted(
        pre_result, key=cmp_to_key(comp_by_two_keys), reverse=True)
    artist_list = [sort_by_times_listened[i][1] for i in range(5)]

    return artist_list


def compute_top_songs(songs: list[Song]) -> list[str]:
    """Calcula les 5 cancons que mes cops s'han escoltat de la llista de cancons.
      * Precondicio: hi ha mes de 5 cancons diferents
    """

    time_song_pairs = [(song.times_listened, song.name) for song in songs]
    sorted_songs = sorted(time_song_pairs, key=cmp_to_key(
        comp_by_two_keys), reverse=True)
    song_list = [sorted_songs[i][1] for i in range(5)]

    return song_list


def main():
    n = yogi.read(int)
    songs = read_songs(n)
    for order in yogi.tokens(str):
        if order == "minutes":
            total_minutes = sum_minutes(songs)
            print("Total de minuts escoltats:", total_minutes)
        elif order == "artists":
            top_artists = compute_top_artists(songs)
            print("Top 5 artists:", *top_artists)
        elif order == "songs":
            top_songs = compute_top_songs(songs)
            print("Top 5 songs:", *top_songs)
        else:
            assert False


if __name__ == "__main__":
    main()
