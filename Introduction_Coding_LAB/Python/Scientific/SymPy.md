# `SymPy` Tutorial: Essential Methods for Symbolic Computation

SymPy is a Python library for symbolic mathematics, providing tools to perform algebraic operations, solve equations, compute derivatives, and much more. This tutorial introduces key features of SymPy and practical examples for symbolic computation.

---

## 1. **Basic Symbolic Operations**

### 1.1 Defining Symbols
```python
from sympy import symbols

# Define symbols
x, y = symbols('x y')
```

### 1.2 Simplification
```python
from sympy import simplify

# Simplify an expression
expr = (x**2 + 2*x + 1) / (x + 1)
simplified_expr = simplify(expr)
print(simplified_expr)  # x + 1
```

---

## 2. **Calculus with SymPy**

### 2.1 Differentiation
```python
from sympy import diff

# Differentiate a function
f = x**3 + 3*x**2 + 2*x
f_prime = diff(f, x)
print(f_prime)  # 3*x**2 + 6*x + 2
```

### 2.2 Integration
```python
from sympy import integrate

# Indefinite Integral
indef_integral = integrate(x**2, x)
print(indef_integral)  # x**3 / 3

# Definite Integral
def_integral = integrate(x**2, (x, 0, 2))
print(def_integral)  # 8/3
```

---

## 3. **Equation Solving**

### 3.1 Algebraic Equations
```python
from sympy import Eq, solve

# Solve x^2 - 4 = 0
equation = Eq(x**2 - 4, 0)
solutions = solve(equation, x)
print(solutions)  # [-2, 2]
```

### 3.2 Systems of Equations
```python
# Solve a system: x + y = 5, x - y = 1
from sympy import solve

eq1 = Eq(x + y, 5)
eq2 = Eq(x - y, 1)
solutions = solve((eq1, eq2), (x, y))
print(solutions)  # {x: 3, y: 2}
```

---

## 4. **Expanding and Factoring**

### 4.1 Expansion
```python
from sympy import expand

# Expand an expression
expr = (x + y)**3
expanded_expr = expand(expr)
print(expanded_expr)  # x**3 + 3*x**2*y + 3*x*y**2 + y**3
```

### 4.2 Factoring
```python
from sympy import factor

# Factor an expression
expr = x**3 + 3*x**2 + 3*x + 1
factored_expr = factor(expr)
print(factored_expr)  # (x + 1)**3
```

---

## 5. **Substitution**
```python
# Substitute a value into an expression
expr = x**2 + y
result = expr.subs(x, 3)
print(result)  # 9 + y
```

---

## 6. **Series Expansion**
```python
from sympy import series

# Taylor Series Expansion of sin(x) around x=0
from sympy import sin
expr = sin(x)
taylor_series = series(expr, x, 0, 5)
print(taylor_series)  # x - x**3/6 + O(x**5)
```

---

## 7. **Matrix Operations**
```python
from sympy import Matrix

# Define a matrix
A = Matrix([[1, 2], [3, 4]])

# Compute determinant
det = A.det()
print("Determinant:", det)  # -2

# Compute inverse
inv = A.inv()
print("Inverse:", inv)
```

---

## 8. **Exercises with Solutions**

### Exercise 1: Simplify an Expression
**Task**: Simplify \( \frac{x^3 - x}{x} \).

**Solution**:
```python
expr = (x**3 - x) / x
simplified_expr = simplify(expr)
print(simplified_expr)  # x**2 - 1
```

### Exercise 2: Solve an Equation
**Task**: Solve \( 2x^2 + 3x - 5 = 0 \).

**Solution**:
```python
equation = Eq(2*x**2 + 3*x - 5, 0)
solutions = solve(equation, x)
print(solutions)
```

### Exercise 3: Compute a Definite Integral
**Task**: Compute the integral of \( x^2 \) from 1 to 3.

**Solution**:
```python
def_integral = integrate(x**2, (x, 1, 3))
print(def_integral)  # 26/3
```

---

By mastering these techniques, you can efficiently solve a variety of symbolic mathematics problems using SymPy.