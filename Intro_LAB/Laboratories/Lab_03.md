# 📘 Java 3 – Hyrje në Analizën Numerike me NumPy


# 1. Qëllimi i Javës 3

Në këtë javë do të mësoni:

* Si të përdorni NumPy për analiza numerike
* Si të përpunoni një seri matjesh
* Si të llogaritni mesataren dhe devijimin standard
* Si të paraqisni të dhënat grafikisht
* Si të interpretoni shpërndarjen e matjeve

Nga kjo javë fillojmë analizën reale të të dhënave eksperimentale.



# 2. Çfarë është NumPy?

NumPy është një bibliotekë për:

* Llogaritje numerike
* Vektorë dhe matrica
* Operacione matematikore të optimizuara

Në laborator, NumPy do të përdoret për:

* Analizë statistikore
* Përpunim të të dhënave
* Llogaritje të pasigurive


# 3. Importimi i Bibliotekave

Në çdo notebook laboratorik, filloni me:

```python
import numpy as np
import matplotlib.pyplot as plt
```



# 4. Futja e të Dhënave

Supozoni se keni matur diametrin e një cilindri 15 herë.

```python
data = np.array([
    10.1, 10.2, 9.9, 10.0, 10.3,
    10.1, 10.2, 10.0, 9.8, 10.1,
    10.2, 10.1, 10.0, 9.9, 10.2
])
```

Këto janë të dhëna bruto.
Në këtë fazë nuk bëjmë interpretim.



# 5. Mesatarja Aritmetike

Mesatarja llogaritet me:

```python
mean = np.mean(data)
mean
```

Matematikisht:

$$
\bar{x} = \frac{1}{N} \sum_{i=1}^{N} x_i
$$



# 6. Devijimi Standard

Devijimi standard për kampion (sample standard deviation):

```python
std = np.std(data, ddof=1)
std
```

Formula:

$$
s = \sqrt{\frac{1}{N-1} \sum_{i=1}^{N} (x_i - \bar{x})^2}
$$

Parametri `ddof=1` është i domosdoshëm për të marrë devijimin standard të kampionit.



# 7. Gabimi i Mesatares (Standard Error)

Gabimi i mesatares:

```python
N = len(data)
sem = std / np.sqrt(N)
sem
```

Formula:

$$
\sigma_{\bar{x}} = \frac{s}{\sqrt{N}}
$$



# 8. Paraqitja Grafike – Histogrami

Histogrami tregon shpërndarjen e matjeve.

```python
plt.hist(data, bins=6)
plt.xlabel("Diametri (mm)")
plt.ylabel("Frekuenca")
plt.title("Histogrami i Matjeve")
plt.grid(True)
plt.show()
```

Çdo grafik duhet të ketë:

* Etiketa boshtesh
* Njësi
* Titull
* Rrjetë (grid)



# 9. Grafiku i Matjeve sipas Rendit

```python
plt.plot(data, 'o-')
plt.xlabel("Numri i Matjes")
plt.ylabel("Diametri (mm)")
plt.title("Variacioni i Matjeve")
plt.grid(True)
plt.show()
```

Ky grafik ndihmon për të identifikuar:

* Tendenca sistematike
* Matje të jashtëzakonshme (outliers)
* Stabilitetin e procesit



# 10. Raportimi i Rezultatit

Rezultati përfundimtar duhet të paraqitet si:

$$
x = \bar{x} \pm \sigma_{\bar{x}}
$$

Shembull në Python:

```python
print(f"Rezultati: {mean:.3f} ± {sem:.3f} mm")
```

Mos raportoni më shumë shifra domethënëse se sa justifikon pasiguria.



# 11. Interpretimi

Në seksionin "Diskutimi" duhet të përgjigjeni:

* A është shpërndarja afërsisht simetrike?
* A ka matje të dyshimta?
* Cili është raporti mes devijimit standard dhe mesatares?
* A është pasiguria statistikore e vogël apo e madhe?

Analiza pa interpretim nuk konsiderohet e plotë.



# 12. Ushtrim i Drejtuar

Matni një objekt (p.sh. gjatësinë e një lapsi) të paktën 20 herë.

Notebook-u duhet të përmbajë:

* Tabelën e matjeve
* Llogaritjen e mesatares
* Devijimin standard
* Gabimin e mesatares
* Histogramin
* Grafikun sipas rendit
* Një paragraf interpretimi



# 13. Gabime që Duhet të Shmangen

* Mos përdorni Excel
* Mos llogaritni me kalkulator
* Mos lini grafikë pa etiketa
* Mos raportoni vetëm mesataren pa pasiguri

Nga kjo javë, çdo analizë bëhet me NumPy.



# 14. Qëllimi Pedagogjik

Java 3 vendos bazën për:

* Mendimin statistik në laborator
* Kuptimin e shpërndarjes së matjeve
* Dallimin mes vlerës së matur dhe pasigurisë
* Disiplinën e analizës numerike

Nga Java 4 do të fillojmë përdorimin e instrumenteve reale (p.sh. kalliper) dhe aplikimin e analizës në matje fizike konkrete.
