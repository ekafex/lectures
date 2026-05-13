# Udhëzues laboratori

## Variacioni i kohës së ekzekutimit: ndikimi i Python-it, CPU-së, memories dhe sistemit operativ

### Qëllimi i laboratorit

Qëllimi i këtij laboratori është të kuptohet pse koha e ekzekutimit e një kodi nuk është gjithmonë e njëjtë, edhe kur kodi dhe input-i mbahen të pandryshuara.

Në këtë laborator nuk synohet të gjendet kompleksiteti kohor $O(N)$, $O(N^2)$ ose $O(N^3)$. Këto i përkasin një laboratori tjetër. Këtu fokusi është te **variacioni i kohës së ekzekutimit** dhe te faktorët që e shkaktojnë atë.

Studentët duhet të matin kohën shumë herë për të njëjtin eksperiment dhe të analizojnë:

* mesataren e kohës;
* devijimin standard;
* minimumin dhe maksimumin;
* histogramën e kohëve;
* koeficientin e variacionit.

---

## 1. Modeli bazë i kohës së matur

Koha që matim në kompjuter nuk është vetëm koha e algoritmit. Në praktikë:

$$
T_{\text{matur}} =
T_{\text{kodi}} +
T_{\text{Python}} +
T_{\text{memoria}} +
T_{\text{OS}} +
T_{\text{I/O}} +
T_{\text{zhurma}}
$$

ku:

* $T_{\text{kodi}}$ është koha e llogaritjeve që duam të studiojmë;
* $T_{\text{Python}}$ është kostoja shtesë e interpretuesit Python;
* $T_{\text{memoria}}$ lidhet me aksesin në RAM dhe cache;
* $T_{\text{OS}}$ lidhet me sistemin operativ dhe procese të tjera;
* $T_{\text{I/O}}$ lidhet me printim, lexim/shkrim skedarësh, diskun etj.;
* $T_{\text{zhurma}}$ përfaqëson luhatje të vogla të pakontrolluara.

Prandaj, një matje e vetme nuk është e mjaftueshme. Koha duhet matur disa herë dhe duhet analizuar statistikisht.



## 2. Rregulla të përgjithshme për matjen

Për matjen e kohës përdorni:

```python
import time

start = time.perf_counter()

# kodi që matet

end = time.perf_counter()

T = end - start
```

Mos përfshini në zonën e matur:

```python
print(...)
```

as:

* vizatim grafikësh;
* ruajtje në skedar;
* importim librarish;
* gjenerim të të dhënave, përveç rasteve kur pikërisht atë doni të matni.

Për çdo eksperiment bëni të paktën 50–100 përsëritje. Për secilin rast llogaritni:

$$
T_{\text{mean}} = \frac{1}{M}\sum_{i=1}^{M} T_i
$$

$$
T_{\text{std}} = \sqrt{\frac{1}{M-1}\sum_{i=1}^{M}(T_i - T_{\text{mean}})^2}
$$

Gjithashtu llogaritni koeficientin e variacionit:

$$
CV = \frac{T_{\text{std}}}{T_{\text{mean}}}
$$

Një $CV$ më i madh do të thotë se matjet kanë variacion relativisht më të madh.



## 3. Linux dhe Windows

Kodi Python është pothuajse i njëjtë në Linux dhe Windows. Ndryshimi kryesor është mënyra si krijohet ngarkesa në sfond dhe si kontrollohet sistemi gjatë matjeve.

### Në Linux

Ekzekutoni programin nga terminali:

```bash
python eksperimenti.py
```

Gjatë matjeve mbyllni programe të panevojshme si browser, video player, programe komunikimi dhe procese të rënda.

Për të krijuar ngarkesë artificiale në CPU, në një terminal tjetër mund të përdorni:

```bash
yes > /dev/null
```

Për ta ndalur:

```bash
Ctrl + C
```

Komanda `yes` prodhon vazhdimisht output, ndërsa `/dev/null` e hedh poshtë këtë output. Kjo krijon ngarkesë të vazhdueshme në CPU.

### Në Windows

Ekzekutoni programin nga PowerShell, Command Prompt, VS Code ose terminali:

```powershell
python eksperimenti.py
```

Për matje më të pastra, mbyllni browser-in, Teams, video player, update tasks dhe programe të tjera të rënda.

Për të krijuar ngarkesë artificiale në CPU, hapni një skript tjetër Python me përmbajtjen:

```python
while True:
    pass
```

Ndalojeni me:

```text
Ctrl + C
```



## 4. Struktura e përbashkët e analizës

Për çdo eksperiment duhet të ruani të gjitha kohët individuale:

```python
times = []
```

Pastaj llogaritni:

```python
import numpy as np

times = np.array(times)

T_mean = times.mean()
T_std  = times.std(ddof=1)
T_min  = times.min()
T_max  = times.max()
CV     = T_std / T_mean
```

Për histogramën:

```python
import matplotlib.pyplot as plt

plt.hist(times, bins=20)
plt.xlabel("T [s]")
plt.ylabel("Numri i matjeve")
plt.grid(True)
plt.show()
```

Në raport, për çdo eksperiment jepni një tabelë të tillë:

| Rasti | $T_{\text{mean}}$ [s] | $T_{\text{std}}$ [s] | $T_{\min}$ [s] | $T_{\max}$ [s] | $CV$ |
| ----- | --------------------: | -------------------: | -------------: | -------------: | ---: |
| ...   |                   ... |                  ... |            ... |            ... |  ... |



# Eksperimentet

## Eksperimenti 1: variacioni natyror i kohës për të njëjtin kod

### Qëllimi

Të tregohet se edhe kur kodi dhe input-i janë të njëjta, koha e ekzekutimit nuk del gjithmonë identike.

### Kodi

```python
import time
import numpy as np
import matplotlib.pyplot as plt

M = 100
N = 200_000

times = []

for r in range(M):
    s = 0

    start = time.perf_counter()
    for i in range(N):
        s += i
    end = time.perf_counter()

    times.append(end - start)

times = np.array(times)

print("T_mean =", times.mean())
print("T_std  =", times.std(ddof=1))
print("T_min  =", times.min())
print("T_max  =", times.max())
print("CV     =", times.std(ddof=1) / times.mean())

plt.hist(times, bins=20)
plt.xlabel("T [s]")
plt.ylabel("Numri i matjeve")
plt.grid(True)
plt.show()
```

### Çfarë të analizoni

Analizoni histogramën e kohëve. Shpjegoni pse kohët nuk janë të gjitha identike. Diskutoni kuptimin e $T_{\text{std}}$ dhe $CV$.



## Eksperimenti 2: matje shumë e shkurtër kundrejt matjes më të gjatë

### Qëllimi

Të tregohet se matjet shumë të shkurtra janë më të ndjeshme ndaj overhead-it dhe zhurmës së sistemit.

### Kodi

```python
import time
import numpy as np

M = 100
N_values = [100, 1_000, 10_000, 100_000, 1_000_000]

for N in N_values:
    times = []

    for r in range(M):
        s = 0

        start = time.perf_counter()
        for i in range(N):
            s += i
        end = time.perf_counter()

        times.append(end - start)

    times = np.array(times)

    T_mean = times.mean()
    T_std  = times.std(ddof=1)
    CV     = T_std / T_mean

    print(N, T_mean, T_std, CV)
```

### Çfarë të analizoni

Krahasoni $CV$ për vlera të vogla dhe të mëdha të $N$. Për vlera shumë të vogla të $N$, koha reale e kodit është aq e shkurtër sa overhead-i dhe zhurma bëhen relativisht të rëndësishme.

Ky eksperiment nuk synon të gjejë kompleksitetin kohor. Synimi është të kuptohet pse matjet shumë të shkurtra janë më pak të besueshme.



## Eksperimenti 3: overhead-i i Python-it kundrejt NumPy

### Qëllimi

Të krahasohet një cikël i shkruar në Python me një operacion të optimizuar në NumPy. Të dyja kryejnë një punë të ngjashme, por me kosto shumë të ndryshme.

### Kodi

```python
import time
import numpy as np

M = 50
N = 1_000_000

# Të dhënat për NumPy krijohen jashtë matjes
a = np.arange(N)

# Python loop
times_python = []

for r in range(M):
    s = 0

    start = time.perf_counter()
    for i in range(N):
        s += i
    end = time.perf_counter()

    times_python.append(end - start)

# NumPy sum
times_numpy = []

for r in range(M):
    start = time.perf_counter()
    s = np.sum(a)
    end = time.perf_counter()

    times_numpy.append(end - start)


times_python = np.array(times_python)
times_numpy  = np.array(times_numpy)

print("Python mean/std/CV:", times_python.mean(), times_python.std(ddof=1), times_python.std(ddof=1)/times_python.mean())
print("NumPy  mean/std/CV:", times_numpy.mean(),  times_numpy.std(ddof=1),  times_numpy.std(ddof=1)/times_numpy.mean())
```

### Çfarë të analizoni

Krahasoni kohën mesatare dhe variacionin relativ për Python dhe NumPy. Shpjegoni që cikli `for` në Python ka overhead të madh sepse çdo hap interpretohet nga Python, ndërsa NumPy e kryen ciklin në kod të optimizuar të kompiluara.



## Eksperimenti 4: krijimi i të dhënave brenda dhe jashtë matjes

### Qëllimi

Të tregohet se matja mund të kontaminohet nëse përfshijmë edhe krijimin e të dhënave në zonën e matur.

### Kodi

```python
import time
import numpy as np

M = 50
N = 1_000_000

# Rasti A: krijimi i të dhënave brenda matjes
times_inside = []

for r in range(M):
    start = time.perf_counter()
    a = np.random.rand(N)
    s = np.sum(a)
    end = time.perf_counter()

    times_inside.append(end - start)

# Rasti B: krijimi i të dhënave jashtë matjes
times_outside = []

for r in range(M):
    a = np.random.rand(N)

    start = time.perf_counter()
    s = np.sum(a)
    end = time.perf_counter()

    times_outside.append(end - start)


times_inside = np.array(times_inside)
times_outside = np.array(times_outside)

print("Brenda matjes:", times_inside.mean(), times_inside.std(ddof=1), times_inside.std(ddof=1)/times_inside.mean())
print("Jashtë matjes:", times_outside.mean(), times_outside.std(ddof=1), times_outside.std(ddof=1)/times_outside.mean())
```

### Çfarë të analizoni

Shpjegoni pse rasti A është më i gjatë. Në rastin A matet:

$$
T_{\text{total}} = T_{\text{krijimit të të dhënave}} + T_{\text{llogaritjes}}
$$

Në rastin B matet kryesisht vetëm:

$$
T_{\text{llogaritjes}}
$$



## Eksperimenti 5: qasja sekuenciale dhe qasja e rastësishme në memorie

### Qëllimi

Të shihet ndikimi i memories, cache dhe lokalitetit të të dhënave.

### Kodi

```python
import time
import numpy as np

M = 30
N = 5_000_000

a = np.random.rand(N)
idx = np.random.permutation(N)

# Qasje sekuenciale
times_seq = []

for r in range(M):
    start = time.perf_counter()
    s = np.sum(a)
    end = time.perf_counter()

    times_seq.append(end - start)

# Qasje e rastësishme
times_rand = []

for r in range(M):
    start = time.perf_counter()
    s = np.sum(a[idx])
    end = time.perf_counter()

    times_rand.append(end - start)


times_seq = np.array(times_seq)
times_rand = np.array(times_rand)

print("Sekuenciale:", times_seq.mean(), times_seq.std(ddof=1), times_seq.std(ddof=1)/times_seq.mean())
print("Rastësore:  ", times_rand.mean(), times_rand.std(ddof=1), times_rand.std(ddof=1)/times_rand.mean())
```

### Çfarë të analizoni

Qasja sekuenciale zakonisht është më e shpejtë sepse procesori shfrytëzon cache dhe prefetching. Qasja e rastësishme prish lokalitetin e memories dhe mund të jetë më e ngadaltë.



## Eksperimenti 6: ndikimi i ngarkesës në sfond

### Qëllimi

Të studiohet ndikimi i sistemit operativ dhe proceseve të tjera në kohën e ekzekutimit.

### Procedura

Bëni të njëjtën matje në dy kushte:

1. kompjuteri pa ngarkesë të dukshme;
2. kompjuteri me një proces të rëndë në sfond.

### Kodi i matjes

```python
import time
import numpy as np

M = 50
N = 2_000_000

times = []

for r in range(M):
    s = 0

    start = time.perf_counter()
    for i in range(N):
        s += i * i
    end = time.perf_counter()

    times.append(end - start)

times = np.array(times)

print("T_mean =", times.mean())
print("T_std  =", times.std(ddof=1))
print("CV     =", times.std(ddof=1) / times.mean())
```

### Ngarkesa në sfond

Në Linux përdorni në një terminal tjetër:

```bash
yes > /dev/null
```

Në Windows përdorni në një proces tjetër Python:

```python
while True:
    pass
```

### Çfarë të analizoni

Krahasoni rezultatet pa ngarkesë dhe me ngarkesë. Shihni nëse rritet $T_{\text{mean}}$, $T_{\text{std}}$ ose $CV$.



## Eksperimenti 7: ndikimi i printimit dhe I/O

### Qëllimi

Të tregohet se `print` dhe operacionet I/O janë të ngadalta dhe mund ta prishin matjen e kohës së një algoritmi.

### Kodi

```python
import time
import numpy as np

M = 20
N = 10_000

# Pa printim
times_no_print = []

for r in range(M):
    s = 0

    start = time.perf_counter()
    for i in range(N):
        s += i
    end = time.perf_counter()

    times_no_print.append(end - start)

# Me printim të kufizuar
times_with_print = []

for r in range(M):
    s = 0

    start = time.perf_counter()
    for i in range(N):
        s += i
        if i % 1000 == 0:
            print(i)
    end = time.perf_counter()

    times_with_print.append(end - start)


times_no_print = np.array(times_no_print)
times_with_print = np.array(times_with_print)

print("Pa printim:", times_no_print.mean(), times_no_print.std(ddof=1), times_no_print.std(ddof=1)/times_no_print.mean())
print("Me printim:", times_with_print.mean(), times_with_print.std(ddof=1), times_with_print.std(ddof=1)/times_with_print.mean())
```

### Çfarë të analizoni

Krahasoni kohën me dhe pa printim. Shpjegoni pse nuk duhet vendosur `print` brenda zonës së matur, përveç rasteve kur qëllimi është të matet vetë I/O.



## Eksperimenti 8: ndryshimi i performancës gjatë një ekzekutimi të gjatë

### Qëllimi

Të shihet nëse koha e ekzekutimit ndryshon gjatë shumë përsëritjeve radhazi për shkak të frekuencës së CPU-së, ngrohjes ose proceseve të sistemit.

### Kodi

```python
import time
import numpy as np
import matplotlib.pyplot as plt

M = 100
N = 1_000_000

times = []

for r in range(M):
    s = 0

    start = time.perf_counter()
    for i in range(N):
        s += i * i
    end = time.perf_counter()

    times.append(end - start)

plt.plot(times, "o-")
plt.xlabel("Numri i përsëritjes")
plt.ylabel("T [s]")
plt.grid(True)
plt.show()
```

### Çfarë të analizoni

Shihni nëse koha mbetet afërsisht konstante apo ndryshon gjatë ekzekutimit. Nëse rritet ose ulet sistematikisht, mund të lidhet me ndryshim frekuence të CPU-së, ngrohje, power management ose procese të tjera të sistemit.



# 5. Çfarë duhet të dorëzohet në raport

Raporti duhet të jetë i shkurtër dhe i qartë. Për çdo eksperiment përfshini:

1. qëllimin e eksperimentit;
2. kodin kryesor ose përshkrimin e tij;
3. tabelën me $T_{\text{mean}}$, $T_{\text{std}}$, $T_{\min}$, $T_{\max}$ dhe $CV$;
4. histogramën e kohëve, kur kërkohet;
5. krahasimin midis rasteve, kur eksperimenti ka dy kushte;
6. interpretimin e shkurtër fizik/kompjuterik.

Tabela përmbledhëse përfundimtare duhet të ketë këtë formë:

| Eksperimenti | Çfarë studiohet                           | Madhësia kryesore për krahasim     |
| ------------ | ----------------------------------------- | ---------------------------------- |
| 1            | Variacioni natyror i kohës                | $T_{\text{std}}$, $CV$, histogramë |
| 2            | Matje të shkurtra kundrejt të gjata       | $CV$ për vlera të ndryshme të $N$  |
| 3            | Python kundrejt NumPy                     | $T_{\text{mean}}$, $CV$            |
| 4            | Krijimi i të dhënave brenda/jashtë matjes | ndryshimi i $T_{\text{mean}}$      |
| 5            | Qasje sekuenciale/rastësishme në memorie  | ndryshimi i kohës dhe $CV$         |
| 6            | Ngarkesa në sfond                         | rritja e $T_{\text{std}}$ dhe $CV$ |
| 7            | Printim dhe I/O                           | rritja e kohës dhe variacionit     |
| 8            | Ekzekutim i gjatë                         | trendi i kohës gjatë përsëritjeve  |



# 6. Përfundimi

Në përfundim përgjigjuni shkurt:

* Pse koha e ekzekutimit nuk është gjithmonë e njëjtë?
* Cili eksperiment pati $CV$ më të madh?
* Si ndikon overhead-i i Python-it?
* Si ndikon krijimi i të dhënave brenda matjes?
* Si ndikon qasja në memorie?
* Si ndikon ngarkesa në sfond?
* Pse printimi dhe I/O nuk duhet të përfshihen në matjen e një algoritmi?

Ideja kryesore është:

> Koha e ekzekutimit është një madhësi eksperimentale. Ajo duhet matur disa herë, duhet analizuar statistikisht dhe duhet interpretuar duke marrë parasysh gjuhën e programimit, CPU-në, memorien, sistemin operativ dhe operacionet I/O.

