def bubblesort(array)

    size = array.size - 1
    swapped = false

    (0...size).each do |i|

        swapped = false

        (0...(size - i)).each do |j|

            if array[j] > array[j + 1]


                array[j], array[j + 1] = array[j + 1], array[j]

                swapped = true

            end

        end

        break unless swapped

    end

    return array

end

numberList = []

File.open("./arr.txt", "r") do |f|

    f.each_line do |line|

        numberList << line.to_i

    end

end

tStart = Time.now
sortedList = bubblesort(numberList)
tEnd = Time.now

time = tEnd - tStart

puts "Execution time: #{time.round(2)}"

File.open("./sortedArray.txt", "w") do |f|

    sortedList.each do |number|

        f.write "#{number}\n"

    end

end