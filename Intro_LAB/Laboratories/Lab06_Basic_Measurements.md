# **LAB 06 — Matja e Madhësive Bazë: Gjatësia, Masa dhe Koha**

## **Qëllimi i Laboratorit**

Ky laborator synon të ndërtojë bazën e matjes eksperimentale përmes:

-   Matjes së **gjatësisë, masës dhe kohës**
-   Kuptimit të **pasigurisë dhe precizionit**
-   Identifikimit të **gabimeve sistematike dhe rastësore**
-   Regjistrimit dhe analizës së të dhënave në mënyrë shkencore



------



## **Konceptet Kryesore**

### 1. Matja si proces fizik

Çdo matje është një krahasim me një njësi standarde dhe **gjithmonë përmban pasiguri**.

$$ x = x_{\text{mat}} \pm \Delta x $$



### 2. Precizioni dhe rezolucioni

-   **Rezolucioni**: ndarja më e vogël e instrumentit
-   **Precizioni**: sa afër janë matjet mes tyre

Rregull praktik:
Pasiguria instrumentale ≈ **gjysma e ndarjes më të vogël**



### 3. Llojet e gabimeve

-   **Sistematik** → zhvendosje konstante (kalibrim i gabuar)
-   **Rastësor** → shpërndarje statistikore
-   **Trashanik** → gabime njerëzore (duhen eliminuar)



## **Pajisjet**

-   Vizore, **kalibër vernier**, mikrometër
-   Peshore (mekanike ose dixhitale)
-   Kronometër (ose smartphone)
-   Objekte të thjeshta (cilindër, kub, etj.)



Simulime për praktikë:

-   [Kalibër (simulator)](https://www.stefanelli.eng.br/en/virtual-vernier-caliper-simulator-02-millimeter/)
-   [Mikrometër (simulator)](https://www.stefanelli.eng.br/en/simulator-virtual-micrometer-hundredths-millimeter/)
-   [Vizore (simulator)](https://www.stefanelli.eng.br/en/simulator-use-reading-ruler-fractional-inch/)
-   [Peshore (simulator)](https://gizmos.explorelearning.com/find-gizmos/launch-gizmo?resourceId=385)



------



## **Pjesa A — Matja e Gjatësisë**

### **Procedura**

1.  Mat një objekt me:
    -   Vizore
    -   Kalibër
    -   Mikrometër (nëse është e aplikueshme)
2.  Kryej **≥5 matje** për çdo instrument
3.  Regjistro të dhënat në tabelë



### **Analiza**

-   Llogarit:
    $$ \bar{x} = \frac{1}{N} \sum x_i $$
-   Vlerëso pasigurinë:
    -   Instrumentale
    -   Statistikore (nëse ka variacion)
-   Krahaso instrumentet:
    -   Cili është më preciz?
    -   A ka zhvendosje sistematike?



## **Pjesa B — Matja e Masës**

### **Procedura**

1.  Mat masën e të njëjtit objekt:
    -   ≥5 herë
2.  Nëse është e mundur:
    -   Mat edhe objekte të ndryshme



### **Analiza**

-   Mesatarja dhe shpërndarja
-   Kontrollo stabilitetin e peshës
-   Diskuto:
    -   A ka drift?
    -   A ndikon vendosja e objektit?



## **Pjesa C — Matja e Kohës**

### **Procedura**

1.  Mat kohën e një procesi të thjeshtë:
    -   p.sh. rënia e një objekti të lehtë (nga lartësi e vogël)
    -   ose interval i kontrolluar (start/stop manual)
2.  Kryej ≥10 matje



### **Analiza**

-   Llogarit mesataren dhe devijimin
-   Diskuto ndikimin e:
    -   **kohës së reagimit njerëzor**
    -   sinkronizimit start/stop

Ky është një shembull tipik i **gabimeve rastësore + sistematike njerëzore**



## **Struktura e të Dhënave**

| Madhësia | Matja 1 | Matja 2 | ...  | Mesatarja | Pasiguria |
| -------- | ------- | ------- | ---- | --------- | --------- |
|          |         |         |      |           |           |



## **Diskutim (kritik)**

Studenti duhet të përgjigjet:

-   A përputhen matjet nga instrumente të ndryshme?
-   Cili është burimi dominues i pasigurisë?
-   A ka evidencë për gabim sistematik?
-   Sa i besueshëm është rezultati final?



## **Gabime të Zakonshme (që duhen shmangur)**

-   Mosshënimi i njësive
-   Mbivlerësimi i saktësisë (shumë shifra)
-   Mosndarja e pasigurisë nga vlera
-   Moskryerja e matjeve të përsëritura



## **Rezultati Final**

Çdo madhësi duhet raportuar në formën:

$$ x = {\rm (vlera \pm pasiguria), njësi} $$



## **Mesazhi Kryesor i Laboratorit**

-   Matja nuk është “lexim numri”
-   Është **proces fizik + analizë kritike**
-   Qëllimi nuk është numri, por **besueshmëria e tij**

## **In Jupyter Notebook**

Përfshini:

-   Tabela të dhënash
-   Llogaritje automatike (NumPy)
-   Grafiqe (nëse ka kuptim)
-   Interpretoni dhe komentoni rezultatet (jo vetëm rezultate numerike)

