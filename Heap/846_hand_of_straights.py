from collections import Counter
import heapq
from typing import List


def isNStraightHand(hand: List[int], groupSize: int) -> bool:
    hand_size = len(hand)

    if hand_size % groupSize != 0:
        return False

    # Counter to store the count of each card value
    card_count = Counter(hand)

    # Min-heap to process the cards in sorted order
    min_heap = list(card_count.keys())
    heapq.heapify(min_heap)

    # Process the cards until the heap is empty
    while min_heap:
        current_card = min_heap[0]  # Get the smallest card value

        # Check each consecutive sequence of groupSize cards
        for i in range(current_card, current_card + groupSize):
            if i not in card_count:
                return False
            card_count[i] -= 1
            if card_count[i] == 0 and i != heapq.heappop(min_heap):
                return False
    return True


if __name__ == "__main__":
    assert isNStraightHand([1, 2, 3, 6, 2, 3, 4, 7, 8], 3) is True
    assert isNStraightHand([1, 2, 9, 6, 2, 3, 4, 7, 8], 3) is False
    assert isNStraightHand([1, 2, 3, 4, 5], 4) is False
