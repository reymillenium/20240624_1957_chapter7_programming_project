# COP 1334 Assignment - Introduction to C++

## Chapter 7: Programming Project

## Title: Rainfalls

### Exercise Description:


Write a program that lets the user enter the total rainfall for each of 12 months (starting with January) into an array of doubles.

Once the user has entered the rainfall for all the months, the program should calculate and display (in this order):

* The total rainfall for the year
* The average monthly rainfall
* The months with the highest and lowest amounts

**Note:** Numeric values should be displayed using default precision. Do not use format specifiers to specify precision.

**Input Validation:** Do not accept a negative number for any of the monthly rainfall amounts. If the user enters a negative value, the program should print the following string (exactly as it is shown here):

"_invalid data (negative rainfall) -- retry_"

and then immediately read the value again as input.

The following sample run shows how your program's output must appear. The user's input is shown in bold.

**Sample Run:**
```terminal
Enter rainfall for January: 1
Enter rainfall for February: 2
Enter rainfall for March: 3
Enter rainfall for April: 4
Enter rainfall for May: 5
Enter rainfall for June: 6
Enter rainfall for July: 7
Enter rainfall for August: 8
Enter rainfall for September: 9
Enter rainfall for October: 10
Enter rainfall for November: 11
Enter rainfall for December: 12
Total rainfall: 78
Average rainfall: 6.5
Least rainfall in: January
Most rainfall in: December
```

## Execution from the Terminal (Alternative way without an IDE):

We must provide to the Compiler the same switches that we usually do in the IDE:

```terminal
g++ -Wall -std=c++17 main.cpp
```

That will create a file named 'a.out' if you are working in MacOS or a .exe file if you are on Windows. That's the default executable file's name when we don't provide a name.

But we can also specify the name of the resulting executable file:

```terminal
g++ -Wall -std=c++17 main.cpp -o your_prefered_executable_file_name
```

And in order to run that a.out file, we must execute on the terminal:

```terminal
 % ./a.out
```

## Result of Execution on the Terminal (MacOS example):

```terminal
reinier@reinier % ./your_prefered_executable_file_name


  
Process finished with exit code 0
reinier@reinier % 
```

### Author

**Reinier Garcia**

* [Github](https://github.com/reymillenium)
* [Twitter](https://twitter.com/ReinierGarciaR)
* [Linkedin](https://www.linkedin.com/in/reiniergarcia/)
* [Website](https://www.reiniergarcia.dev/)
* [Stack Overflow](https://stackoverflow.com/users/9616949/reinier-garcia)

### License

Copyright © 2024, [Reinier Garcia](https://github.com/reymillenium).


