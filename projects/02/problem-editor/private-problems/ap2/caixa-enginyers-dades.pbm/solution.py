from typing import Final
from yogi import *

CardInfo = tuple[int, float, int]  # count, amount, last_date
CardStats = dict[str, CardInfo]

MIN_COUNT: Final[int] = 3
MIN_AMOUNT: Final[float] = 200.0
MIN_LAST_DATE: Final[int] = 20240301

def accumulate_statistics(card_stats: CardStats) -> None:
    for date in tokens(int):
        card_number = read(str)
        amount = read(float)
        if card_number in card_stats:
            count, total_amount, last = card_stats[card_number]
            card_stats[card_number] = (
                count + 1,
                total_amount + amount,
                max(last, date),
            )
        else:
            card_stats[card_number] = (1, amount, date)


def print_candidate_cards(card_stats: CardStats) -> None:
    for card_number, stats in sorted(card_stats.items()):
        count, total_amount, last_date = stats
        if (
            count >= MIN_COUNT
            and total_amount >= MIN_AMOUNT
            and last_date >= MIN_LAST_DATE
        ):
            print(card_number)


card_stats: CardStats = {}
accumulate_statistics(card_stats)
print_candidate_cards(card_stats)
