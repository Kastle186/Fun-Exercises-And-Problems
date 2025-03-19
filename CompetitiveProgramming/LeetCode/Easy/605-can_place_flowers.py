#!/usr/bin/env python3

# Name: 605. Can Place Flowers
# Topics: Array, Greedy
# Companies:
# - LinkedIn
# - Agoda

def can_place_flowers(flowerbed: list[int], to_plant: int) -> bool:
    if len(flowerbed) < to_plant:
        return False
    
    planted = 0
    flowerbed = [0] + flowerbed + [0]  # Add borders to simplify edge checking
    
    for i in range(1, len(flowerbed) - 1):
        if flowerbed[i] == 0 and flowerbed[i - 1] == 0 and flowerbed[i + 1] == 0:
            flowerbed[i] = 1
            planted += 1

        if planted >= to_plant:
            return True

    return False


def can_place_flowers(flowerbed: list[int], to_plant: int) -> bool:
    # Clown case from the problem. Of course the answer is "true" is we actually
    # don't need to plant anything.
    if to_plant == 0:
        return True

    # If we have more flowers than slots, then we can just be sure it is not
    # physically possible for there to be a planting solution.
    if len(flowerbed) < to_plant:
        return False

    # With the unfittable cases out of the way, we can begin our official search
    # for the available patches. To account for the possibility of planting flowers
    # at the edges, we symbolically add an extra slot to each, so that we can use
    # the same checking criteria we'll be using for the rest of the slots.

    planted = 0
    flowerbed = [0] + flowerbed + [0]

    for i in range(1, len(flowerbed) - 1):
        patch = flowerbed[i-1:i+2]

        if all(slot == 0 for slot in patch):
            flowerbed[i] = 1
            planted += 1
            i += 1

        if planted >= to_plant:
            return True

    # No available patches were found sadly :(
    return False


def main():
    flowerbed_1 = can_place_flowers([1, 0, 0, 0, 1], 1)
    flowerbed_2 = can_place_flowers([1, 0, 0, 0, 1], 2)
    flowerbed_3 = can_place_flowers([1, 0, 0, 0, 0, 1], 2)

    print("true" if flowerbed_1 else "false")
    print("true" if flowerbed_2 else "false")
    print("true" if flowerbed_3 else "false")


if __name__ == '__main__':
    main()
