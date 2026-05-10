## Udhëzues i shkurtër për LAB09: Matja eksperimentale e kompleksitetit kohor

### Qëllimi

Qëllimi i këtij laboratori është të matet eksperimentalisht koha e ekzekutimit $T$ e disa algoritmeve për madhësi të ndryshme të hyrjes $N$, dhe të studiohet si ndryshon $T$ kur $N$ rritet.

Në fund duhet të përcaktohet nëse koha e ekzekutimit sillet afërsisht si:

$$
T(N) \sim N^p
$$

ku $p$ është eksponenti i kompleksitetit kohor.

Për shembull:

* nëse $p \approx 1$, algoritmi është linear: $T(N) \sim N$
* nëse $p \approx 2$, algoritmi është kuadratik: $T(N) \sim N^2$
* nëse $p \approx 3$, algoritmi është kubik: $T(N) \sim N^3$


# 1. Matja e kohës

Për çdo algoritëm, koha matet me:

```python
import time

start = time.perf_counter()

# kodi që do të matet

end = time.perf_counter()

T = end - start
```

Duhet matur vetëm pjesa kryesore e algoritmit, jo krijimi i figurave, ruajtja e skedarëve, printimet, ose importimi i librarive.


# 2. Eksperimenti 1 — Një cikël `for`

Matni kohën që i duhet programit për të llogaritur shumën:

```python
s = 0

start = time.perf_counter()
for i in range(N):
    s += i
end = time.perf_counter()

T = end - start
```

Përdorni vlera të ndryshme të $N$, për shembull:

```python
N_values = [10, 100, 1000, 10000, 100000, 1000000]
```

Për çdo vlerë të $N$ matni kohën $T$ 10 herë.

Pastaj llogaritni:

$$
T_{\text{mean}} = \text{mesatarja e kohëve}
$$

dhe

$$
T_{\text{std}} = \text{devijimi standard i kohëve}
$$

Rezultatet ruhen ne folderin `data/` në skedarin:

```text
eksperimenti1.dat
```

me formatin:

```text
N    T_mean    T_std
10   ...
100  ...
1000 ...
```

Kompleksiteti i pritshëm:

$$
T(N) \sim N
$$

pra pritet $p \approx 1$.



# 3. Eksperimenti 2 — Dy cikle të futura brenda njëri-tjetrit

Përdorni një algoritëm me dy cikle:

```python
s = 0

start = time.perf_counter()
for i in range(N):
    for j in range(N):
        s += i * j
end = time.perf_counter()

T = end - start
```

Edhe këtu, për çdo $N$, matni kohën 10 herë dhe ruani:

```text
N    T_mean    T_std
```

në skedarin:

```text
eksperimenti2.dat
```

Përdorni vlera më të vogla të $N$ sesa në eksperimentin 1, sepse dy cikle rrisin shumë kohën e ekzekutimit. Për shembull:

```python
N_values = [10, 30, 100, 300, 1000, 3000]
```

Kompleksiteti i pritshëm:

$$
T(N) \sim N^2
$$

pra pritet $p \approx 2$.



# 4. Eksperimenti 3 — Tre cikle të futura brenda njëri-tjetrit

Përdorni një algoritëm me tre cikle:

```python
s = 0

start = time.perf_counter()
for i in range(N):
    for j in range(N):
        for k in range(N):
            s += i * j * k
end = time.perf_counter()

T = end - start
```

Për çdo $N$, matni kohën 10 herë dhe ruani rezultatet në:

```text
eksperimenti3.dat
```

Përdorni vlera edhe më të vogla të $N$, për shembull:

```python
N_values = [5, 10, 20, 30, 50, 80, 100]
```

Kompleksiteti i pritshëm:

$$
T(N) \sim N^3
$$

pra pritet $p \approx 3$.



# 5. Eksperimenti 4 — Renditja e një vargu me NumPy

Krijoni një varg të rastësishëm me $N$ elemente dhe renditeni me `numpy.sort`:

```python
import numpy as np
import time

a = np.random.rand(N)

start = time.perf_counter()
b = np.sort(a)
end = time.perf_counter()

T = end - start
```

Për çdo $N$, matni kohën 10 herë dhe ruani rezultatet në:

```text
eksperimenti4.dat
```

Përdorni vlera të $N$ si:

```python
N_values = [100, 1000, 10000, 100000, 1000000]
```

Kompleksiteti i pritshëm për renditjen është afërsisht:

$$
T(N) \sim N \log N
$$

Kjo rritet më shpejt se $N$, por më ngadalë se $N^2$.

Pra në grafik duhet të shihet se renditja nuk është lineare, por nuk është as kuadratike.



# 6. Analiza e të dhënave

Për secilin eksperiment duhet të bëhen këto hapa.



## 6.1 Grafiku $T$ kundrejt $N$

Vizatoni grafikun:

$$
T_{\text{mean}} \text{ kundrejt } N
$$

Mund të përdoret shkallë logaritmike:

```python
plt.loglog(N, T_mean, "o-")
plt.xlabel("N")
plt.ylabel("T_mean [s]")
plt.grid(True)
```

Ky grafik tregon vizualisht si rritet koha kur rritet madhësia e hyrjes.



## 6.2 Grafiku $\log_{10}(T)$ kundrejt $\log_{10}(N)$

Nëse:

$$
T(N) = aN^p
$$

atëherë duke marrë logaritmin:

$$
\log_{10}(T) = \log_{10}(a) + p \log_{10}(N)
$$

Kjo është një vijë e drejtë:

$$
y = b + px
$$

ku:

$$
x = \log_{10}(N)
$$

dhe

$$
y = \log_{10}(T)
$$

Eksponenti $p$ merret nga pjerrësia e vijës.



## 6.3 Fitimi linear në shkallë logaritmike

Përdorni:

```python
x = np.log10(N)
y = np.log10(T_mean)

p, b = np.polyfit(x, y, 1)
```

ku:

* `p` është eksponenti i kompleksitetit
* `b` është konstante
* nëse `p ≈ 1`, sjellja është lineare
* nëse `p ≈ 2`, sjellja është kuadratike
* nëse `p ≈ 3`, sjellja është kubike



# 7. Çfarë duhet të përmbajë raporti

Raporti duhet të përmbajë:

1. Qëllimin e laboratorit.
2. Përshkrimin e shkurtër të çdo algoritmi.
3. Tabelën e rezultateve për çdo eksperiment:

   * $N$
   * $T_{\text{mean}}$
   * $T_{\text{std}}$
4. Grafikët:

   * $T$ kundrejt $N$
   * $\log_{10}(T)$ kundrejt $\log_{10}(N)$
5. Fitimin linear në grafikun log-log.
6. Vlerën e gjetur të eksponentit $p$.
7. Krahasimin me pritshmërinë teorike.

Tabela përfundimtare mund të jetë:

| Eksperimenti | Algoritmi      | Kompleksiteti i pritur | $p$ i matur |
| ------------ | -------------- | ---------------------: | ----------: |
| 1            | Një cikël      |                    $N$ |         ... |
| 2            | Dy cikle       |                  $N^2$ |         ... |
| 3            | Tre cikle      |                  $N^3$ |         ... |
| 4            | Renditje NumPy |             $N \log N$ |         ... |



# 8. Përfundimi që duhet të nxirret

Në përfundim, ju duhet të diskutoni:

* A përputhet eksponenti i matur $p$ me kompleksitetin teorik?
* Pse matjet kanë luhatje?
* Si ndikon sistemi operativ, procesori dhe ngarkesa e kompjuterit te koha e matur?
* Pse për vlera shumë të vogla të $N$ matjet mund të mos jenë të besueshme?
* Pse është më mirë të përdoren shumë matje dhe të merret mesatarja?

Rezultati kryesor i laboratorit është të kuptohet se kompleksiteti kohor nuk është vetëm një koncept teorik, por mund të shihet eksperimentalisht duke matur kohën e ekzekutimit për madhësi të ndryshme të hyrjes.

