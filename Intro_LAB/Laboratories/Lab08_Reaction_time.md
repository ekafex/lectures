# **LAB 08 — Koha e Reagimit: Të Dhëna, Shpërndarje dhe Probabilitet**

## **Qëllimi**

Qëllimi i këtij laboratori është të tregojë se rezultatet eksperimentale nuk përshkruhen gjithmonë nga një vlerë e vetme, por nga një **shpërndarje probabilitare**.

Studentët do të:

-   mbledhin një numër të madh të dhënash
-   ndërtojnë histogramin e tyre
-   krahasojnë shpërndarjen me një funksion probabiliteti



## **Koncepti i Eksperimentit**

Koha e reagimit është një madhësi **statistikore** që ndryshon nga matja në matje.
Rezultati nuk është një numër i vetëm, por një bashkësi vlerash që ndjek një shpërndarje.



## **Metoda (Rënia e Vizores)**

Koha e reagimit përcaktohet nga distanca e rënies:
$$
t = \sqrt{\frac{2d}{g}}
$$
ku:

-   $d$ është distanca e rënies
-   $g \approx 9.81,\mathrm{m/s^2}$



## **Procedura**

### **1. Mbledhja e të dhënave**

-   Punoni në çifte
-   Kryeni të paktën **30–50 matje për person**
-   Regjistroni distancën (d) për çdo provë
-   Konvertoni të gjitha matjet në kohë (t)

Numri i madh i matjeve është i domosdoshëm për analizën statistikore.



### **2. Organizimi i të dhënave**

Ndërtoni një dataset:
$$
t_1, t_2, ..., t_N
$$
Të dhënat duhet të jenë të pastra dhe të strukturuara qartë.



## **Analiza e të Dhënave**

### **1. Histogrami**

-   Ndërtoni histogramin e kohës (t)
-   Zgjidhni ndarje të përshtatshme (bins)

Histogrami përfaqëson një përafrim të funksionit të densitetit të probabilitetit.



### **2. Madhësitë statistikore**

Llogaritni:

Mesataren:
$$
\bar{t} = \frac{1}{N}\sum t_i
$$
Devijimin standard:
$$
\sigma = \sqrt{\frac{1}{N-1}\sum (t_i - \bar{t})^2}
$$


### **3. Normalizimi**

Histogrami duhet të normalizohet në mënyrë që sipërfaqja totale të jetë afërsisht 1.
Kjo e kthen histogramin në një densitet probabiliteti.



### **4. Krahasimi me shpërndarjen normale**

Krahasoni të dhënat me një shpërndarje Gaussiane:
$$
f(t) \sim \exp\left(-\frac{(t - \bar{t})^2}{2\sigma^2}\right)
$$
Vizualisht, kjo bëhet duke vendosur kurbën mbi histogram.



## **Çfarë duhet të vërehet**

-   Matjet nuk janë konstante
-   Ekziston një shpërndarje e qartë
-   Shpesh ajo i afrohet një shpërndarjeje normale
-   Ka variacion të dukshëm midis matjeve



## **Rezultati Final**

Rezultati duhet të jepet në formën:
$$
t = (\bar{t} \pm \sigma)
$$
së bashku me histogramin dhe interpretimin përkatës.



## **Pyetje për Diskutim**

-   Pse koha e reagimit nuk është konstante?
-   Çfarë përcakton gjerësinë e shpërndarjes?
-   A përmirësohet rezultati me rritjen e numrit të matjeve?
-   Sa mirë përputhet shpërndarja me modelin Gaussian?



## **Gabime të Zakonshme**

-   Numër i vogël matjesh
-   Mungesë histogrami
-   Raportim vetëm i mesatares
-   Mungesë interpretimi statistik



## **Mesazhi Kryesor**

Ky laborator thekson një ide themelore:

Matjet eksperimentale mund të jenë në thelb statistikore dhe përshkruhen nga një shpërndarje probabilitare, jo vetëm nga një vlerë e vetme.

