# Learning Basics of Python

### 1. Introduction to Python

Python is a versatile, easy-to-learn programming language widely used in data science, web development, automation, and more. Its simplicity makes it a great starting point for beginners.

#### Key Features:

- Simple and readable syntax.
- Large standard library with prebuilt tools.
- Supports multiple programming paradigms (object-oriented, procedural, functional).

------

### 2. Setting Up Python

#### Install Anaconda

1. **Download Anaconda:**

   - Visit [Anaconda's website](https://www.anaconda.com/) and download the version for your operating system (Windows, macOS, or Linux).
   - Follow the installation instructions.

2. **Verify Installation:**

   - Open a terminal or Command Prompt and type:

     ```bash
     conda --version
     ```

   - You should see the Conda version number.

3. **Install Required Libraries:**

   ```bash
   $ conda install numpy scipy sympy matplotlib cython jupyterlab
   ```

4. **Launch JupyterLab:**

   ```bash
   $ jupyter lab
   ```

------

### 3. Python Syntax Cheat Sheet

#### **Comments**

- Single-line: `# This is a comment`

- Multi-line:

  ```python
  """
  This is a multi-line comment.
  """
  ```

#### **Variables**

- Python is dynamically typed (no need to declare types).

  ```python
  name = "Alice"  # String
  age = 25         # Integer
  height = 5.6     # Float
  is_student = True  # Boolean
  ```

#### **Print and Input**

- Print:

  ```python
  print("Hello, World!")
  ```

- Input:

  ```python
  name = input("What's your name? ")
  print(f"Hello, {name}!")
  ```

#### **Indentation**

- Python uses indentation (4 spaces recommended) to define blocks of code.

  ```python
  if age >= 18:
      print("You're an adult!")
  ```

#### **Conditionals**

- Used for decision-making:

  ```python
  if condition:
      # code if condition is True
  elif another_condition:
      # code if another_condition is True
  else:
      # code if no conditions are True
  ```

  Example:

  ```python
  age = 20
  if age < 18:
      print("Minor")
  elif age == 18:
      print("Just turned adult")
  else:
      print("Adult")
  ```

#### **Loops**

- **For Loop:** Used to iterate over a sequence.

  ```python
  for element in iterable:
      # code to execute
  ```

  Example:

  ```python
  for number in [1, 2, 3]:
      print(number)
  ```

- **While Loop:** Repeats as long as a condition is True.

  ```python
  while condition:
      # code to execute
  ```

  Example:

  ```python
  count = 0
  while count < 5:
      print(count)
      count += 1
  ```

#### **Basic Data Types and Operations**

| **Data Type** | **Example**       | **Operations**                           |
| ------------- | ----------------- | ---------------------------------------- |
| `int`         | `x = 10`          | `+, -, *, /, // (floor div), % (mod)`    |
| `float`       | `y = 3.14`        | `** (power), round()`                    |
| `str`         | `name = "Alice"`  | `+ (concat), len(), slicing [start:end]` |
| `bool`        | `is_valid = True` | `and, or, not`                           |

------

### 4. Data Structures and Operators (Cheat Sheet)

#### **Lists**

- Ordered, mutable collections.

  ```python
  fruits = ["apple", "banana", "cherry"]
  fruits.append("orange")  # Add element
  fruits.pop(1)             # Remove element by index
  print(fruits[0])          # Access element
  ```

| **Operation**  | **Syntax**                | **Description**             |
| -------------- | ------------------------- | --------------------------- |
| Add element    | `fruits.append("orange")` | Adds to the end of the list |
| Remove element | `fruits.pop(1)`           | Removes element at index 1  |
| Iterate        | `for fruit in fruits:`    | Loops through each element  |
| Slice          | `fruits[1:3]`             | Extracts a sublist          |

#### **Dictionaries**

- Key-value pairs, mutable.

  ```python
  student = {"name": "Bob", "age": 21}
  student["grade"] = "A"  # Add new key-value pair
  print(student["name"])   # Access value by key
  ```

| **Operation**           | **Syntax**                    | **Description**                 |
| ----------------------- | ----------------------------- | ------------------------------- |
| Add key-value pair      | `student["grade"] = "A"`      | Adds new entry                  |
| Access value            | `student["name"]`             | Fetches value for the given key |
| Iterate keys and values | `for k, v in student.items()` | Loops through all pairs         |

#### **Tuples**

- Ordered, immutable collections.

  ```python
  coords = (10, 20)
  print(coords[0])  # Access element
  ```

| **Operation**  | **Syntax**             | **Description**            |
| -------------- | ---------------------- | -------------------------- |
| Access element | `coords[0]`            | Fetches element at index   |
| Iterate        | `for coord in coords:` | Loops through all elements |

#### **Sets**

- Unordered, unique elements.

  ```python
  numbers = {1, 2, 3}
  numbers.add(4)  # Add element
  numbers.remove(2)  # Remove element
  ```

| **Operation**  | **Syntax**          | **Description**       |
| -------------- | ------------------- | --------------------- |
| Add element    | `numbers.add(4)`    | Adds a unique element |
| Remove element | `numbers.remove(2)` | Removes an element    |
| Union          | `set1               | set2`                 |

------

### 5. Functions

- Define reusable blocks of code.

  ```python
  def greet(name):
      return f"Hello, {name}!"
  
  print(greet("Alice"))
  ```

| **Operation**   | **Syntax**                 | **Description**                      |
| --------------- | -------------------------- | ------------------------------------ |
| Define function | `def greet(name):`         | Defines a new function               |
| Return value    | `return f"Hello, {name}!"` | Returns a result                     |
| Call function   | `greet("Alice")`           | Executes the function with arguments |

------

### 6. Solved Problems

* **Simple Calculator:** Write a Python program to add, subtract, multiply, or divide two numbers based on user input.

**Solution:**

```python
# Input numbers and operation

num1 = float(input("Enter the first number: "))
num2 = float(input("Enter the second number: "))
operation = input("Choose an operation (+, -, *, /): ")

# Perform calculation

if operation == '+':
    result = num1 + num2
elif operation == '-':
    result = num1 - num2
elif operation == '*':
    result = num1 * num2
elif operation == '/':
    result = num1 / num2 if num2 != 0 else "Undefined (division by zero)"
else:
    result = "Invalid operation"

print("Result:", result)
```



* **FizzBuzz Game:** Write a program that prints numbers from 1 to 100. For multiples of 3, print "Fizz"; for multiples of 5, print "Buzz"; and for multiples of both 3 and 5, print "FizzBuzz."

**Solution:**

```python
for i in range(1, 101):
    if i % 3 == 0 and i % 5 == 0:
        print("FizzBuzz")
    elif i % 3 == 0:
        print("Fizz")
    elif i % 5 == 0:
        print("Buzz")
    else:
        print(i)
```



* **Check Palindrome:** Write a function to check if a string is a palindrome (reads the same forward and backward).

**Solution:**

```python
def is_palindrome(s):
    s = s.lower().replace(" ", "")
    return s == s[::-1]

# Example
word = input("Enter a word: ")
if is_palindrome(word):
    print(f"'{word}' is a palindrome!")
else:
    print(f"'{word}' is not a palindrome.")
```



* **Find the Largest Number:** Write a Python function that takes a list of numbers and returns the largest number.

**Solution:**

```python
def find_largest(numbers):
    return max(numbers)

# Example
nums = [3, 5, 7, 2, 8]
print("Largest number:", find_largest(nums))
```



* **Prime Number Checker:** Write a function to check if a given number is prime.

**Solution:**

```python
def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

# Example
number = int(input("Enter a number: "))
if is_prime(number):
    print(f"{number} is a prime number.")
else:
    print(f"{number} is not a prime number.")
```



* **Count Vowels in a String:** Write a program to count the number of vowels in a given string.

**Solution:**

```python
def count_vowels(s):
    vowels = "aeiou"
    return sum(1 for char in s.lower() if char in vowels)

# Example
text = input("Enter a string: ")
print("Number of vowels:", count_vowels(text))
```



* Guess the Number: Create a number-guessing game where the program generates a random number, and the user has to guess it.

Solution:

```python
import random

number = random.randint(1, 100)
print("Guess the number (between 1 and 100):")

while True:
    guess = int(input("Your guess: "))
    if guess < number:
        print("Too low!")
    elif guess > number:
        print("Too high!")
    else:
        print("Congratulations! You guessed it!")
        break
```



* **Sum of Digits:** Write a function that calculates the sum of digits of a given number.

**Solution:**

```python
def sum_of_digits(n):
    return sum(int(digit) for digit in str(n))

# Example
number = int(input("Enter a number: "))
print("Sum of digits:", sum_of_digits(number))
```



* **Create a Multiplication Table:** Write a program to generate a multiplication table for a given number.

**Solution:**

```python
num = int(input("Enter a number: "))
print(f"Multiplication table for {num}:")
for i in range(1, 11):
    print(f"{num} x {i} = {num * i}")
```



* **Sort a List:** Write a program to sort a list of numbers in ascending order without using the sorted() function.

**Solution:**

```python
def bubble_sort(numbers):
    for i in range(len(numbers)):
        for j in range(0, len(numbers) - i - 1):
            if numbers[j] > numbers[j + 1]:
                numbers[j], numbers[j + 1] = numbers[j + 1], numbers[j]
    return numbers

# Example
nums = [64, 34, 25, 12, 22, 11, 90]
print("Sorted list:", bubble_sort(nums))
```



---

### 7. Practice Problems

1. Write a program to check if a number is even or odd.
2. Create a function that takes two numbers and returns their sum.
3. Write a program to find the largest number in a list.
4. Create a dictionary to store student names and their grades. Print all students with grades above 80.

------



### 8. Learning Resources

Here is a collection of references and resources for learning Python, ranging from official documentation to beginner-friendly books.

#### **Official Python Resources**

1. **[Python Official Documentation](https://docs.python.org/3/)**
   - The most comprehensive and up-to-date reference for Python.
   - Includes tutorials, library references, and advanced topics.
   - Suitable for all levels, especially intermediate and advanced learners.

2. **[The Python Software Foundation Website](https://www.python.org/)**
   - Offers downloads, news, and links to Python-related events and resources.
   - Includes an introductory tutorial to get started with Python.

3. **[PEP 8 – Style Guide for Python Code](https://peps.python.org/pep-0008/)**
   - Essential for writing clean and readable Python code.
   - Covers conventions for naming, indentation, and formatting.

4. **[Real Python](https://realpython.com/)**
   - Offers high-quality Python tutorials, courses, and learning paths.
   - Focuses on practical examples and applications.

---

#### **Books for Beginners**

1. **"Automate the Boring Stuff with Python" by Al Sweigart**
   - Great for absolute beginners.
   - Focuses on practical projects like automating tasks, working with files, and web scraping.
   - [Website with free chapters](https://automatetheboringstuff.com/)

2. **[Python Crash Course: A Hands-On, Project Based Introduction to Programming](https://ehmatthes.github.io/pcc_3e/): by Eric Matthes** *(Highly recommend)* 
   - A hands-on guide to Python programming with examples and projects.
   - Covers basics and moves into intermediate concepts like web apps and data visualization.

3. **"Think Python" by Allen B. Downey**
   - Free online book ideal for beginners with no programming experience.
   - Emphasizes understanding Python concepts and solving problems.
   - [Free PDF](https://greenteapress.com/wp/think-python-2e/)

---

#### **Books for Intermediate Learners**

1. **"Fluent Python" by Luciano Ramalho**
   - A deep dive into Python’s advanced features and idiomatic use.
   - Best suited for learners with a basic understanding of Python.

2. **"Effective Python" by Brett Slatkin**
   - A collection of 90 tips and techniques for writing better Python code.
   - Focuses on best practices and performance.

3. **"Python Cookbook" by David Beazley and Brian K. Jones**
   - A problem-solution approach to intermediate and advanced Python concepts.
   - Covers a wide range of topics, including data structures, algorithms, and parallelism.

---

#### **Online Resources**

1. **[W3Schools Python Tutorial](https://www.w3schools.com/python/)**
   - Beginner-friendly interactive tutorials.
   - Covers syntax, libraries, and basic projects.

2. **[GeeksforGeeks Python Tutorial](https://www.geeksforgeeks.org/python-programming-language/)**
   - Great for quick references and explanations of concepts.

3. **[Kaggle Python Course](https://www.kaggle.com/learn/python)**
   - A beginner-friendly Python course with hands-on coding exercises.
   - Focuses on data science and machine learning.

---

#### **Interactive Platforms** 

1. **[Codecademy Python Course](https://www.codecademy.com/learn/learn-python-3)**
   - Beginner-focused interactive lessons and quizzes.
   - Covers Python fundamentals and practical applications.
2. **[LeetCode (Python Problems)](https://leetcode.com/problemset/all/?difficulty=Easy&listId=python3)**
   - Great for practicing algorithms and problem-solving with Python.
3. **[HackerRank Python Practice](https://www.hackerrank.com/domains/tutorials/10-days-of-python)** 
   - Offers problem sets to build Python skills through challenges.


