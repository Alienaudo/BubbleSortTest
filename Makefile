all: BubbleSortC

BubbleSortC: ./C/BubbleSortC.c
	gcc -o ./BubbleSortC ./C/BubbleSortC.c

clean:
	rm BubbleSortC