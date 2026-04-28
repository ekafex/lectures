# **LAB09 — Eksperiment Kompjuterik: Koha e Ekzekutimit të Algoritmeve**

**Kategoria:** Kompjuter
**Qëllimi:** Të matet koha e ekzekutimit të algoritmeve të thjeshta dhe të studiohet si ndryshon ajo në varësi të madhësisë së të dhënave hyrëse.



## **1. Çfarë është koha e ekzekutimit?**

Koha e ekzekutimit është **koha reale që i duhet një programi për të përfunduar** një detyrë.

-   Matet zakonisht në **sekonda (s)** ose **milisekonda (ms)**
-   Varet nga:
    -   algoritmi
    -   madhësia e input-it
    -   kompjuteri (CPU, RAM, OS)

Në këtë laborator, ne fokusohemi në lidhjen: 

$\text{Koha e ekzekutimit} \; T(n) \;\; \text{vs} \;\; \text{madhësia e input-it} \; n$



## **2. Ideja kryesore**

Sa më shumë të dhëna të përpunojë një algoritëm, aq më shumë kohë kërkon.

Shembuj tipikë:

| Algoritmi          | Sjellja e pritshme  |
| ------------------ | ------------------- |
| Cikël i thjeshtë   | $T(n) \propto n$    |
| Dy cikle të futura | $T(n) \propto n^2$  |
| Renditje (sorting) | varet nga algoritmi |

Qëllimi është të verifikohet kjo **empirikisht** me matje reale. 



---

Matjet qe do beni:

1.   **Fiksoni algoritmin dhe madhësinë e inputit dhe bëni $10^5 - 10^6$ përsëritje dhe regjistroni kohën e ekzekutimit. Ndërtoni histrogramën e saj për të parë si shpërndahet zhurma.** (Kjo do kryhet më me rigorozitet në LAB10).
2.   **Zgjidhni një algoritëm dhe matni kohën mesatare të ekzekutimit për madhësi të ndryshme inputi $n$ (zgjidhni rreth 10 $n$ të ndryshme). Ndërtoni grafikun e kohës mesatare nga madhësia e inputit në shkallën log-log dhe bëni fit polinomial**.
3.   **Zgjidhni një algoritëm tjetër dhe kryeni të njejtat veprime sic bëtë me pikën 2.**

---

>    Një algoritëm nuk është vetëm matematikë —
>   është një proces fizik që ekzekutohet në hardware real.



## **3. Pajisjet dhe mjetet**

-   Kompjuter me Python (Jupyter Notebook)
-   Librarite:
    -   `time` ose `timeit`
    -   `numpy`
    -   `matplotlib`



## **4. Metodologjia**

### **Hapi 1 — Zgjedhja e algoritmit**

Zgjidh një algoritëm të thjeshtë:

-   Numërim me cikël (psh `for` loop)
-   Shuma e elementeve
-   Kërkim në listë (searching algorithm)
-   Renditje (p.sh. bubble sort)

### **Hapi 2 — Gjenerimi i të dhënave**

Krijo input me madhësi të ndryshme:

$$ n = 10^2,\; 10^3,\; 10^4,\; \dots $$

### **Hapi 3 — Matja e kohës**

Përdor funksione si:

```python
import time

start = time.time()
# kodi i algoritmit qe do ekzekutohet
end = time.time()

T = end - start
```

më mirë se kjo zgjidh:

```python
import time

start = time.perf_counter()
# kodi i algoritmit qe do ekzekutohet
end = time.perf_counter()

T = end - start
```

### **Hapi 4 — Përsëritja**

-   Kryej matjen disa herë
-   Merr mesataren

### **Hapi 5 — Analiza grafike**

Ndërto grafikun:

-   boshti x: madhësia e input-it $n$
-   boshti y: koha $T(n)$
-   ndërto grafikët në shkallë logaritmike log-log



## **5. Rezultatet e pritshme**

Studenti duhet të vërejë:

-   Rritje të kohës me rritjen e $n$
-   Forma e kurbës:
    -   lineare
    -   kuadratike
    -   më komplekse

## **6. Diskutim**

Pyetje udhëzuese:

-   A është lidhja lineare apo jo?
-   A përputhen rezultatet me pritjet teorike?
-   Pse ka devijime nga forma ideale?
-   Sa e saktë është matja?

## **7. Përfundime**

Ky laborator demonstron që:

-   Koha e ekzekutimit është një **madhësi fizike e matshme**
-   Sjellja e algoritmeve mund të studiohet **eksperimentalisht**
-   Ekziston një lidhje e fortë midis:
    -   strukturës së algoritmit
    -   dhe kompleksitetit të tij në kohë

## **8. Zgjerime**

-   Krahaso dy algoritme të ndryshme
-   Studio efektin e strukturës së të dhënave
-   Provo madhësi shumë të mëdha dhe kufizimet e sistemit (performanca)



## **Mbani Mënd**

Ky laborator duhet të kuptohet në kontekstin e funksionimit të kompjuterit:
- Programi ruhet në disk
- Ngarkohet në RAM
- Ekzekutohet nga CPU (fetch–decode–execute)
- Menaxhohet nga sistemi operativ

Performanca që matim është rezultat i këtij sistemi fizik.

> Ky nuk është vetëm programim — është **matje eksperimentale** në një sistem kompjuterik.



---

# **Appendix — Matja e kohës së ekzekutimit**

## **1. Çfarë matim realisht?**

Ne masim: $T = t_{\text{fund}} - t_{\text{fillim}}$

Por kjo përfshin: kohën e CPU, vonesat nga OS dhe aksesin në memorie



## **2. Mjetet kryesore në Python**

#### **a) `time` (më i thjeshti)**

```python
import time
start = time.time()
# kodi qe do ekzekutohet ketu (ose e therret ketu)
end = time.time()
T = end - start
```

*   **Si funksionon:** lexon orën e sistemit (wall-clock time)

*   **Avantazh:** i thjeshtë

*   **Kufizim:** jo shumë i saktë për matje të vogla



#### **b) `time.perf_counter()` (rekomandohet)**

```python
import time
start = time.perf_counter()
# kodi qe do ekzekutohet ketu (ose e therret ketu)
end = time.perf_counter()
T = end - start
```

*   **Si funksionon:** përdor një orë me rezolucion të lartë (high-resolution timer)

*   **Avantazh:** shumë më i saktë



#### **c) `timeit` (më profesional)**

```python
import timeit
# T = timeit.timeit("kodi i ekzekutueshem", number=1000)
# shembul shuma e numrave 1-1000
T = timeit.timeit("sum(range(1000))", number=1000)
```

*   **Si funksionon:** ekzekuton kodin shumë herë dhe llogarit mesataren

*   **Avantazh:** redukton zhurmën (noise) per shkak te ekzekutimit nga memoria & OS



## **3. Pse duhet përsëritja?**

Matjet ndryshojnë për shkak të:

-   OS (scheduler & interrupts)
-   procese të tjera (që janë duke u bërë run momentalisht)
-   cache CPU (lëvizjes së memories nga RAM në cache në regjistra dhe anasjelltas)

Prandaj përdorim shumë përsëritje dhe gjejme mesataren ose medianin



## **4. Gabime të zakonshme**

-   Matje e një operacioni shumë të vogël
-   Mos përsëritja e eksperimenteve
-   Përfshirja e I/O (print, file) në matje



Matja e kohës është një **eksperiment fizik në kompjuter**:

-   ka zhurmë
-   ka pasiguri
-   kërkon metodologji të saktë

