import time


def bubbleSort(array: list[int]) -> list[int]:

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


numberList: list[int] = []

with open("./arr.txt", "r") as f:

    for line in f:

        numberList.append(int(line.strip()))

start: float = time.time()
_ = bubbleSort(numberList)
end: float = time.time()

execTime: float = (end - start) * 1000

print(f"Execution time: {execTime:.2f} ms")

with open("./sortedArray.txt", "w") as f:

    _ = f.write("\n".join(str(num) for num in numberList))