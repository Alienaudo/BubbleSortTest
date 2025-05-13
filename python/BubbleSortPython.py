import time
from typing import List


def bubbleSort(array: List[int]) -> List[int]:

    i: int = len(array) - 1
    isSorted: bool = False

    while not isSorted:

        isSorted = True

        for j in range(0, i):

            if array[j] > array[j + 1]:

                isSorted = False
                array[j], array[j + 1] = array[j + 1], array[j]

        i -= 1

    return array


numberList: List[int] = []

with open("../arr.txt", "r") as f:

    for line in f:

        numberList.append(int(line.strip()))

start: float = time.time()
bubbleSort(numberList)
end: float = time.time()

execTime: float = end - start

print(f"Execution time: {execTime:.4f} seconds")

with open("../sortedArray.txt", "w") as f:

    f.write("\n".join(str(num) for num in numberList))
