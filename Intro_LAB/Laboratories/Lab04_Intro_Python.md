# Python për Analizë Shkencore në Jupyter Notebook

### Udhëzues i shkurtër për laboratorë



## 1. Pse përdorim Python në laborator?

Në laborator shpesh duhet të:

-   analizojmë **të dhëna eksperimentale**
-   bëjmë **grafikë**
-   përshtatim modele matematikore
-   nxjerrim **rezultate numerike**

Python është shumë i përdorur në shkencë sepse:

-   është **i thjeshtë për t’u mësuar**
-   ka biblioteka shumë të fuqishme
-   përdoret gjerësisht në **fizikë, matematikë dhe inxhinieri**

Në laboratorët tanë do të përdorim kryesisht tre biblioteka:

| Biblioteka     | Qëllimi                         |
| -------------- | ------------------------------- |
| **NumPy**      | operacione numerike dhe vektorë |
| **Matplotlib** | grafikë                         |
| **SciPy**      | analiza dhe fitting             |



# 2. Struktura e një Programi Python në Notebook

Shembull minimal:

```python
import numpy as np
import matplotlib.pyplot as plt

x = np.array([1,2,3,4])
y = np.array([2,4,6,8])

plt.plot(x,y)
plt.show()
```

Ky kod:

1.  importon bibliotekat
2.  krijon të dhëna
3.  vizaton grafikun



# 3. Variablat

Variablat përdoren për të ruajtur vlera.

```python
a = 5
b = 3
c = a + b

print(c)
```

Rezultati:

```
8
```



# 4. Lista dhe Vektorë

Në analizë shkencore përdorim shpesh **vektorë të dhënash**.

### Lista Python

```python
data = [1,2,3,4]
```

### NumPy array (më i përshtatshëm për shkencë)

```python
import numpy as np

data = np.array([1,2,3,4])
```

Avantazhi:

```python
data * 2
```

rezulton:

```
[2 4 6 8]
```



# 5. Operacione Matematikore me NumPy

```python
import numpy as np

x = np.linspace(0,10,100)

y = np.sin(x)
```

Kjo krijon:

-   100 pika nga 0 deri në 10
-   vlerat e funksionit sinus



# 6. Krijimi i Grafikëve

Biblioteka standarde është **Matplotlib**.

```python
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0,10,100)
y = np.sin(x)

plt.plot(x,y)
plt.xlabel("x")
plt.ylabel("sin(x)")
plt.title("Funksioni sinus")
plt.grid()

plt.show()
```

Praktikë e mirë:

✔ gjithmonë vendos **etiketa të boshtit**
✔ vendos **titullin**
✔ aktivizo **grid**



# 7. Leximi i të Dhënave Eksperimentale

Shpesh të dhënat ruhen në **file CSV**.

Shembull:

```python
import numpy as np

data = np.loadtxt("data.csv", delimiter=",")

time = data[:,0]
position = data[:,1]
```



# 8. Fitting i të Dhënave

Shpesh duam të përshtatim një model teorik me të dhënat.

Shembull: **fit linear**

```python
import numpy as np

x = np.array([1,2,3,4])
y = np.array([2,4,6,8])

coeff = np.polyfit(x,y,1)

slope = coeff[0]
intercept = coeff[1]
```

Modeli linear:

```
y = slope * x + intercept
```



# 9. Grafik me të Dhëna dhe Model

```python
import numpy as np
import matplotlib.pyplot as plt

x = np.array([1,2,3,4])
y = np.array([2.1,4.2,6.1,8.0])

coeff = np.polyfit(x,y,1)

fit = coeff[0]*x + coeff[1]

plt.scatter(x,y,label="Data")
plt.plot(x,fit,label="Fit")

plt.xlabel("x")
plt.ylabel("y")

plt.legend()
plt.show()
```



# 10. Workflow Tipik i Analizës së të Dhënave

Në laborator zakonisht ndiqet kjo procedurë:

```
1. Ngarkimi i të dhënave
2. Përpunimi i tyre
3. Vizualizimi me grafik
4. Përshtatja e modelit teorik
5. Interpretimi fizik
```



# 11. Praktika të Mira

Studentët duhet të:

✔ përdorin **emra variablash kuptimplotë**
✔ të komentojnë kodin
✔ të vizatojnë grafikë të qartë
✔ të interpretojnë rezultatet

Shembull i mirë:

```python
time = np.array([0,1,2,3])
position = np.array([0,5,20,45])
```

jo:

```python
a = [0,1,2,3]
b = [0,5,20,45]
```



# 12. Burime të Dobishme

### Scientific Python Cheat Sheet

https://ipgp.github.io/scientific_python_cheat_sheet/

Përfshin:

-   NumPy
-   SciPy
-   Matplotlib
-   analizë shkencore



### Dokumentacioni zyrtar i Python

[https://python.org](https://python.org/)



# Përmbledhje

Në laborator përdorim Python për:

-   manipulimin e të dhënave (**NumPy**)
-   grafikët (**Matplotlib**)
-   analiza dhe modele (**SciPy**)

Në **Jupyter Notebook** kombinojmë:

-   **Markdown → dokumentim**
-   **Python → analiza**

kështu krijojmë një **raport laboratorik të plotë dhe të riprodhueshëm**.

