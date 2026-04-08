# LAB05 – Gjenerimi dhe Analiza e të Dhënave (Përshtatje Lineare)

## Qëllimi i laboratorit

Në këtë laborator, çdo student do të:

-   Gjenerojë një dataset **unik dhe të riprodhueshëm**
-   Analizojë të dhënat
-   Kryejë një **përshtatje lineare (linear regression)**
-   Vlerësojë cilësinë e modelit përmes **mbetjeve (residuals)**



## RREGULLA TË RËNDËSISHME

### Identifikimi i studentit

-   Skripti përdor një listë **të mbyllur (whitelist)** të GitHub accounts
-   Vetëm këto ID lejohen të përdoren

Duhet të përdorni:

```
GITHUB USERNAME tuaj EXACT (pa asnjë ndryshim)
```

-   Case-sensitive (p.sh. `Ergi110` ≠ `ergi110`)
-   Pa hapësira shtesë
-   Pa modifikime



### Kufizime të sistemit

-   Nëse përdorni një ID të pasaktë → skripti **nuk do të ekzekutohet**
-   Nuk mund të përdorni ID të një studenti tjetër



### Uniciteti i të dhënave

Për çdo student:

-   Parametrat e modelit linear (**a dhe b**) janë unikë
-   Zhurma (**noise**) është unike (nga `sigma` dhe `seed`)
-   Dataset-i është:
    -   **unik**
    -   **i riprodhueshëm** (nëse përdoret e njëjta ID)

Nëse dy studentë kanë të njëjtat të dhëna → konsiderohet shkelje serioze



## Hapi 1 – Gjenerimi i të dhënave

Ekzekutoni skriptin:

```bash
python generate_data.py GITHUB_USERNAME
```

Shembull:

```bash
python generate_data.py Ergi110
```



## Hapi 2 – Organizimi i file-it

Pas ekzekutimit krijohet file-i:

```
model.dat
```

Vendoseni në strukturën:

```
LAB05/
 └── data/
     └── model.dat
```



## Hapi 3 – Ngarkimi i të dhënave

```python
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("data/model.dat", delimiter=",", skiprows=1)

x_Data = data[:, 0]
y_Data = data[:, 1]
```



## Hapi 4 – Përshtatja lineare

```python
a, b = np.polyfit(x_Data, y_Data, 1)

print(f"Pjerresia e drejtezes a = {a : .2f}")
print(f"Prerja me boshtin b = {b : .2f}")
```



## Hapi 5 – Vizualizimi i të dhënave dhe modelit

```python
xfit = np.linspace(1,10,100)
yfit = a*xfit + b

plt.figure(1,(8,6))
plt.plot(x_Data, y_Data, 'ok', label='Te Dhenat')
plt.plot(xfit, yfit, '-r', lw=2, label=f'y={a: .2f}*x + {b: .2f}')
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.show()
```



## Hapi 6 – Analiza e mbetjeve (residuals)

```python
plt.figure(2,(8,6))
plt.stem(x_Data, y_Data - (a*x_Data + b), '-r')
plt.hlines(0,0,11,ls='--',color='k',lw=1)
plt.xlabel("x")
plt.ylabel("mbetjet")
plt.xlim(0.8,10.2)
plt.show()
```



## Interpretimi i rezultateve

-   **a (pjerresia)** → lidhja lineare mes x dhe y
-   **b (prerja)** → vlera e y kur x = 0
-   **Mbetjet**:
    -   duhet të shpërndahen rreth zeros
    -   tregojnë cilësinë e modelit



## Çfarë duhet të përmbajë raporti juaj

Raporti laboratorik duhet të përfshijë:

1.  **Përshkrimi i metodës**
    -   Si u gjeneruan të dhënat
    -   Roli i ID-së në proces
2.  **Grafiku i të dhënave + fit-it**
3.  **Vlerat e a dhe b**
4.  **Grafiku i mbetjeve**
5.  **Interpretimi fizik/statistik i rezultateve**



## Integriteti akademik

-   Çdo dataset është i lidhur me GitHub ID tuaj
-   Nuk lejohet:
    -   ndarja e të dhënave
    -   përdorimi i dataset-it të një studenti tjetër
    -   modifikimi manual i file-it

Çdo ngjashmëri e pajustifikuar → konsiderohet plagjiaturë



## Përmbledhje

1.  Ekzekuto `generate_data.py` me GitHub ID
2.  Vendos `model.dat` në `data/`
3.  Ngarko dhe analizo të dhënat
4.  Kryej përshtatjen lineare
5.  Vizualizo rezultatet
6.  Shkruaj raportin



Suksese!
