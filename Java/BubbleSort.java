package Java;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.Scanner;

public class BubbleSort {

    private static void sort(ArrayList<Integer> array) {

        int k, i;
        final int size = array.size() - 1;

        boolean swapped;

        for (k = 0; k < size; ++k) {

            swapped = false;

            for (i = 0; i < size - k; ++i) {

                int leftElement = array.get(i);
                int rightElement = array.get(i + 1);

                if (leftElement > rightElement) {

                    array.set(i, rightElement);
                    array.set(i + 1, leftElement);

                    swapped = true;

                }

            }

            if (!swapped)
                break;

        }

    }

    public static void main(String[] args) {

        try {

            ArrayList<Integer> unsortedList = new ArrayList<Integer>();

            File myObj = new File("arr.txt");
            Scanner myRead = new Scanner(myObj);

            while (myRead.hasNextLine()) {

                unsortedList.add(Integer.parseInt(myRead.nextLine()));

            }

            myRead.close();

            long start = System.currentTimeMillis();
            sort(unsortedList);
            long end = System.currentTimeMillis();

            long time = end - start;

            System.out.println("Execution time: " + time + " seconds!");

            File list = new File("sortedArray.txt");

            if (list.exists()) {

                System.out.println("File already exists.");

            }

            list.createNewFile();

            FileWriter writer = new FileWriter(list);

            for (Integer num : unsortedList) {
                writer.write(num + "\n");
            }

            writer.close();
            System.out.println("File created: " + list.getName());

        } catch (FileNotFoundException e) {

            System.err.println("Error: " + e.getMessage());
            e.printStackTrace();

        } catch (IOException e) {

            System.err.println("Error: " + e.getMessage());
            e.printStackTrace();

        }

    }

}