import { promises } from "node:fs";
import { performance } from "node:perf_hooks";

function Sort(array) {

    const size = array.length - 1;
    let i, j;
    let swapped;

    for (i = 0; i < size; ++i) {

        swapped = false;

        for (j = 0; j < size - i; ++j) {

            if (array[j] > array[j + 1]) {

                let temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                swapped = true;

            }

        }

        if (!swapped) break;

    }

    return array;

};

async function main() {

    try {

        const data = await promises.readFile('./arr.txt', 'utf-8');

        const numberList = data.trim().split(/\s+/).map(Number);

        const start = performance.now();

        Sort(numberList);

        const end = performance.now();
        const time = (end - start).toFixed(2);

        console.log(`Time : ${time} ms`);

        await promises.writeFile('./sortedArray.txt', numberList.join('\n'), 'utf-8');

    } catch (error) {

        throw new Error(error.message);

    }

};

main();