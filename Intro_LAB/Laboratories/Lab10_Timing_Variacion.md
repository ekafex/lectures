# **LAB10 — Variacioni i Performancës së Kompjuterit**

**Kategoria:** Kompjuter
**Objektivi:**
Të studiohet variacioni i kohës së ekzekutimit duke përsëritur matjet dhe duke analizuar burimet fizike dhe sistemore të ndryshimeve.



## **1. Ideja kryesore**

Në LAB09 supozuam se për një input të dhënë kemi një kohë $T(n)$.
Në realitet:

$$T(n) \;\; \text{nuk është konstante} \;\; \Rightarrow \;\; T(n) \sim \text{shpërndarje}$$

I njëjti program, me të njëjtin input, jep kohë të ndryshme ekzekutimi.



## **2. Pse ekziston variacioni? (model fizik)**

Koha e ekzekutimit ndikohet nga:

### **CPU**

-   ndryshime në frekuencë (turbo boost)
-   ndarje midis proceseve

### **Memoria**

-   cache hit / miss
-   lokaliteti i të dhënave

### **Sistemi Operativ**

-   scheduler (ndërprerje)
-   procese të tjera në sfond

### **I/O dhe faktorë të jashtëm**

-   akses në disk
-   temperatura / power management

Pra, matja ka **zhurmë (noise)** reale.



## **3. Qasja eksperimentale**

Ndryshe nga LAB09:

-   **fiksojmë input-in $n$**
-   **përsërisim matjen shumë herë**

$$ T_1, T_2, T_3, \dots, T_N $$



## **4. Metodologjia**

### **Hapi 1 — Zgjedhja e kodit**

Përdor një algoritëm të thjeshtë nga LAB09:

-   p.sh. shuma e një liste
-   kërkim linear
-   një cikël i madh

### **Hapi 2 — Fiksimi i input-it**

Zgjidh një madhësi fikse:

$$n = 10^5 \;\; \text{(ose tjetër e përshtatshme)}$$

### **Hapi 3 — Matja e përsëritur**

```python
import time

def measure():
    start = time.perf_counter()
    # kodi
    end = time.perf_counter()
    return end - start

times = [measure() for _ in range(100)]
```

### **Hapi 4 — Analiza statistikore**

Llogarit:

-   mesataren: $\bar{T}$
-   devijimin standard: $\sigma$
-   minimum / maksimum

### **Hapi 5 — Vizualizimi**

Ndërto:

-   histogramën e $T$
-   densitetin probabilitarë (pdf)



## **5. Interpretimi i rezultateve**

Vëreni se kemi:

-   shpërndarje rreth një vlere mesatare
-   jo një vlerë fikse
-   forma shpesh afërsisht “normale” (gausiane)



## **6. Diskutim**

Pyetje udhëzuese:

-   Sa i madh është variacioni ($\sigma$)?
-   A është shpërndarja simetrike?
-   A ka outliers? (vlera që largohen shumë nga pritshmëritë apo mesatarja)
-   Çfarë ndodh nëse:
    -   rritet $n$?
    -   sistemi është i ngarkuar? (kemi shume përdorues apo e ngarkojmë artificialisht sistemin duke futur procesorin, memorien apo edhe I/O). A shihet ndryshim në performancë kur sitemi është i ngarkuar krahasuar me atë kur është i lirë.



## **7. Lidhja me matjet fizike**

Ky laborator është analog me çdo matje fizike:

| Fizikë         | Kompjuter         |
| -------------- | ----------------- |
| matje me gabim | kohë me variacion |
| zhurmë         | OS + hardware     |
| përsëritje     | eksperimente      |

Koha e ekzekutimit është një **madhësi statistikore**



## **8. Gabime të zakonshme**

-   shumë pak përsëritje
-   përfshirje e `print()` në matje
-   përdorimi i input-eve shumë të vogla
-   mos përdorimi i `perf_counter()`



## **9. Shtojca**

-   krahaso variacionin për algoritme të ndryshme
-   testo nën ngarkesë (psh hap programe të tjera)
-   krahaso laptop vs desktop



## **Mesazhi qëndror i laboratorit**

Ky laborator tregon që:

>   Performanca e kompjuterit nuk është deterministe në praktikë —
>   ajo duhet trajtuar si një fenomen statistik.

