import json
import time
from typing import List
from arr import unsortedList

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

start = time.time()
result = bubbleSort(unsortedList)
end = time.time()

execTime = end - start

print(result)
print(f"Tempo de execução: {execTime:.4f} segundos")
