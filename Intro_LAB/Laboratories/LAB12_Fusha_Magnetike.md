# LAB12 — Hartëzimi i Fushës Magnetike

## 1. Qëllimi i laboratorit

Qëllimi i këtij laboratori është të matet fusha magnetike në pika të ndryshme të hapësirës dhe të ndërtohet një hartë 2D e intensitetit të saj. Studentët do të përdorin magnetometrin e telefonit për të matur komponentët $B_x$, $B_y$, $B_z$, do të përpunojnë të dhënat në Python dhe do të vizualizojnë ndryshimin hapësinor të fushës magnetike.

Ky laborator nuk ka si qëllim matje magnetometrike me saktësi profesionale. Qëllimi kryesor është të kuptohet se si një madhësi fizike që varet nga pozicioni mund të matet, organizohet në rrjetë dhe vizualizohet si hartë.



## 2. Objektivat mësimore

Në fund të laboratorit studenti duhet të jetë në gjendje të:

1.  Shpjegojë kuptimin e fushës magnetike si madhësi vektoriale.
2.  Përdorë magnetometrin e telefonit për të matur komponentët $B_x$, $B_y$, $B_z$.
3.  Llogarisë intensitetin total të fushës:

​	$$ B = \sqrt{B_x^2 + B_y^2 + B_z^2} $$

1.  Ndërtojë një rrjetë matjeje 2D.
2.  Organizojë të dhënat në tabelë me koordinata hapësinore ($x,y$).
3.  Vizualizojë hartën e fushës magnetike me `scatter plot`, `heatmap` dhe `contour plot`.
4.  Diskutojë burimet e pasigurisë dhe kufizimet e magnetometrit të telefonit.
5.  Krahasojë fushën magnetike ambientale me perturbimet pranë objekteve magnetike ose metalike.



## 3. Bazë teorike

### 3.1 Fusha magnetike

Fusha magnetike është një madhësi vektoriale. Në çdo pikë të hapësirës ajo ka drejtim dhe madhësi. Në sistemin SI matet në **tesla** ($\text{T}$). Në aplikacionet me smartphone zakonisht përdoret njësia:

$$ 1 \, \mu\text{T} = 10^{-6} \, \text{T} $$

Magnetometri i telefonit zakonisht raporton tre komponentë:

$$ B_x, \quad B_y, \quad B_z $$

sipas boshteve të telefonit. Në Android, sensori i fushës magnetike raporton komponentët e fushës magnetike në boshtet $x,y,z$, në njësi **microtesla** ($\mu\text{T}$). ([Android Open Source Project](https://source.android.com/docs/core/interaction/sensors/sensor-types?utm_source=chatgpt.com))

Intensiteti total i fushës llogaritet si:

$$ B = \sqrt{B_x^2 + B_y^2 + B_z^2} $$

Ky është numri që do të përdorim kryesisht për hartëzim.



### 3.2 Fusha magnetike e Tokës

Në mungesë të objekteve magnetike pranë, magnetometri mat kryesisht fushën magnetike të Tokës. Kjo fushë është e rendit disa dhjetëra $\mu\text{T}$, por vlera lokale varet nga vendndodhja gjeografike. Modele si **World Magnetic Model** përdoren për navigim dhe referencë të fushës gjeomagnetike; versioni aktual WMM2025 u publikua më 17 dhjetor 2024 dhe është i vlefshëm deri në fund të vitit 2029. ([NCEI](https://www.ncei.noaa.gov/products/world-magnetic-model?utm_source=chatgpt.com))

Në këtë laborator nuk kërkohet krahasim i saktë me modelin gjeomagnetik. Fusha e Tokës përdoret vetëm si sfond mbi të cilin shfaqen ndryshimet lokale.



### 3.3 Magnetometri i telefonit

Telefonat inteligjentë kanë magnetometër për funksione si busulla dhe orientimi. Aplikacioni **phyphox** ka një eksperiment “Magnetic field” që jep të dhënat e papërpunuara nga magnetometri i telefonit. Dokumentimi i phyphox thekson se magnetometri është i ndjeshëm, por vlerat absolute nuk duhet të besohen verbërisht, sepse ato ndikohen nga magnetizime të brendshme të telefonit dhe nga rikalibrimi automatik i sensorit. ([phyphox](https://phyphox.org/wiki/index.php/Sensor%3A_Magnetic_field?utm_source=chatgpt.com))

Prandaj, në këtë laborator do të përdorim magnetometrin për:

-   ndryshime relative,
-   harta hapësinore,
-   krahasime midis pikave,
-   identifikim anomalish magnetike.

Nuk do ta përdorim si instrument absolut profesional.



## 4. Pajisjet dhe programet e nevojshme

### Pajisje

-   Telefon inteligjent me magnetometër.
-   Aplikacion për regjistrim të fushës magnetike.
-   Një magnet i vogël permanent.
-   Letër A3/A2, karton ose tavolinë me rrjetë të vizatuar.
-   Vizore ose metër.
-   Laptop me Python/Jupyter.
-   Opsionale: objekt metalik, spirë/solenoid, tel me rrymë të ulët DC.

### Aplikacion i rekomanduar

Rekomandohet:

**phyphox — Magnetic field**

Ky aplikacion lexon komponentët e magnetometrit dhe lejon eksportimin e të dhënave. Eksperimenti “Magnetic field” përdor magnetometrin dhe jep komponentët e fushës magnetike në kohë. ([phyphox](https://phyphox.org/wiki/index.php/Sensor%3A_Magnetic_field?utm_source=chatgpt.com))



## 5. Paralajmërime praktike

1.  **Mos e afroni telefonin shumë pranë magneteve të fortë.** Magnetet e fortë mund të ndikojnë te sensori ose te komponentë të tjerë të telefonit. Edhe dokumentimi i phyphox paralajmëron që telefoni të mos ekspozohet ndaj fushave shumë të forta magnetike. ([phyphox](https://phyphox.org/wiki/index.php/Sensor%3A_Magnetic_field?utm_source=chatgpt.com))
2.  Përdorni magnetë të vegjël laboratorikë ose magnetë të zakonshëm të dobët.
3.  Mos përdorni magnetë neodymium shumë të fuqishëm shumë pranë telefonit.
4.  Mbani telefonin gjithmonë në të njëjtin orientim gjatë hartëzimit.
5.  Mos bëni matje pranë laptopit, altoparlantëve, çelësave, tavolinave metalike ose kabllove me rrymë, përveç nëse këto janë pjesë e eksperimentit.
6.  Përpara matjeve, largoni objekte metalike nga zona e punës.



## 6. Struktura e laboratorit

Laboratori ndahet në katër pjesë:

1.  **Eksperimenti A:** Matja e fushës magnetike ambientale.
2.  **Eksperimenti B:** Hartëzimi 1D i fushës pranë një magneti.
3.  **Eksperimenti C:** Hartëzimi 2D i fushës pranë një magneti.
4.  **Eksperimenti D:** Hartëzimi i anomalive magnetike në ambient, opsional.

Për një laborator 3-orësh, rekomandohet që të gjithë studentët të bëjnë A, B dhe C. Eksperimenti D mund të jetë detyrë shtesë ose pjesë e raportit për grupe më të shpejta.



## 7. Metodologjia e përgjithshme

### 7.1 Parimi i matjes

Në çdo pikë të rrjetës matet:

$$ B_x, \quad B_y, \quad B_z $$

Pastaj llogaritet:

$$ B = \sqrt{B_x^2 + B_y^2 + B_z^2} $$

Nëse duam të shohim vetëm perturbimin nga magneti, mund të zbresim vlerën e sfondit:

$$ \Delta B = B - B_{\text{background}} $$

ku $B_{\text{background}}$ merret si vlera mesatare larg magnetit.



### 7.2 Rrjeta e matjes

Për hartëzim 2D përdoret një rrjetë e thjeshtë, p.sh.:

-   madhësia: $20 \, \text{cm} \times 20 \, \text{cm}$,
-   hapi i rrjetës: $2 \, \text{cm}$ ose $4 \, \text{cm}$,
-   koordinatat: $x$ dhe $y$ në centimetra.

Shembull:

$$ x = -10, -8, -6, \ldots, 8, 10 , \text{cm} $$

$$ y = -10, -8, -6, \ldots, 8, 10 , \text{cm} $$

Magneti vendoset në qendër të rrjetës, në ($0,0$).



### 7.3 Vendosja e telefonit

Kjo është shumë e rëndësishme.

Studentët duhet të zgjedhin një pikë referimi në telefon, p.sh.:

-   qendra e telefonit,
-   cepi i poshtëm i majtë,
-   ose pozicioni i përafërt i magnetometrit.

Në praktikë, magnetometri nuk është gjithmonë në qendër të telefonit. Për këtë laborator mjafton të përdoret **e njëjta pikë referimi gjatë gjithë matjeve**.

Telefoni duhet të mbahet:

-   me ekranin lart,
-   me të njëjtin orientim,
-   në të njëjtën lartësi mbi tavolinë,
-   pa rrotullim gjatë matjeve.



## 8. Eksperimenti A — Matja e fushës magnetike ambientale

### Qëllimi

Të matet fusha magnetike në një vend ku nuk ka magnet të afërt dhe të vlerësohet stabiliteti i leximit të sensorit.

### Procedura

1.  Vendoseni telefonin mbi tavolinë, larg magneteve dhe objekteve metalike.
2.  Hapni phyphox → **Magnetic field**.
3.  Filloni regjistrimin.
4.  Mos e prekni telefonin për 30–60 sekonda.
5.  Eksportoni të dhënat në CSV.
6.  Ruajeni skedarin si:

```text
data/B_background.csv
```

### Analiza

Llogaritni:

$$ B = \sqrt{B_x^2 + B_y^2 + B_z^2} $$

pastaj mesataren dhe devijimin standard:

$$ \bar{B}, \quad \sigma_B $$

Kjo matje përdoret si sfond për eksperimentet e tjera.



## 9. Eksperimenti B — Hartëzimi 1D pranë një magneti

### Qëllimi

Të studiohet si ndryshon fusha magnetike me largësinë nga një magnet.

### Procedura

1.  Vendosni një magnet të vogël në qendër të tavolinës.
2.  Vizato një vijë të drejtë përgjatë boshtit $x$.
3.  Zgjidhni pika matjeje, p.sh.:

$$ x = 2, 4, 6, 8, 10, 12, 14, 16 \, \text{cm} $$

1.  Në çdo pikë vendoseni telefonin me të njëjtin orientim.
2.  Regjistroni për 5–10 sekonda në çdo pikë.
3.  Për çdo pikë shënoni mesataren e komponentëve $B_x, B_y, B_z$.
4.  Ruani të dhënat në një tabelë:

```text
data/B_1D.csv
```

### Format i rekomanduar i tabelës

```text
x_cm,y_cm,Bx_uT,By_uT,Bz_uT
2,0,...
4,0,...
6,0,...
8,0,...
10,0,...
```

### Analiza

Llogaritni:

$$ B(x) = \sqrt{B_x^2 + B_y^2 + B_z^2} $$

dhe:

$$ \Delta B(x) = B(x) - B_{\text{background}} $$

Pastaj paraqitni $B$ ose $\Delta B$ si funksion i largësisë nga magneti.

Për një magnet të vogël, larg magnetit fusha ka sjellje të përafërt si dipol magnetik, pra bie afërsisht si:

$$ B \propto \frac{1}{r^3} $$

Kjo nuk do të dalë perfekt me telefon, sepse magneti nuk është dipol ideal, pozicioni i sensorit nuk dihet saktë dhe sfondi magnetik nuk është zero. Por forma e përgjithshme duhet të tregojë rënie të fushës me largësinë.



## 10. Eksperimenti C — Hartëzimi 2D i fushës magnetike

### Qëllimi

Të ndërtohet një hartë 2D e intensitetit të fushës magnetike pranë një magneti.

### Procedura

1.  Vendosni një fletë me rrjetë mbi tavolinë.
2.  Vendosni magnetin në qendër të rrjetës.
3.  Zgjidhni një hap rrjete, p.sh. $2 \, \text{cm}$ ose $4 \, \text{cm}$.
4.  Në çdo pikë të rrjetës vendosni telefonin me të njëjtin orientim.
5.  Matni $B_x, B_y, B_z$.
6.  Për çdo pikë regjistroni vlerën mesatare.
7.  Plotësoni tabelën:

```text
data/B_map_2D.csv
```

### Format i rekomanduar i tabelës

```text
x_cm,y_cm,Bx_uT,By_uT,Bz_uT
-10,-10,...
-8,-10,...
-6,-10,...
...
10,10,...
```

Për kursim kohe, secili grup mund të bëjë një rrjetë $7 \times 7$ ose $9 \times 9$. Një rrjetë shumë e dendur është më e bukur, por kërkon më shumë kohë dhe rrit mundësinë për gabime.



## 11. Eksperimenti D — Hartëzimi i anomalive magnetike në ambient, opsional

### Qëllimi

Të shihet si ndryshon fusha magnetike në një dhomë ose korridor për shkak të objekteve metalike, kabllove, pajisjeve elektrike ose strukturave të ndërtesës.

### Procedura

1.  Zgjidhni një zonë të vogël, p.sh. $2 \, \text{m} \times 2 \, \text{m}$.
2.  Ndani zonën në rrjetë, p.sh. çdo $0.5 \, \text{m}$.
3.  Në çdo pikë matni $B_x, B_y, B_z$.
4.  Ndërtoni hartën e $B$ ose $\Delta B$.
5.  Diskutoni nëse shihen zona me anomali magnetike.

Ky eksperiment lidhet me idenë se hartat magnetike mund të përdoren edhe për lokalizim të brëndëshëm, sepse strukturat lokale krijojnë ndryshime të matshme në fushën magnetike. Studime mbi hartëzimin magnetik të brëndëshëm përdorin variacionet lokale të intensitetit magnetik si “shenja” hapësinore për lokalizim. ([ScienceDirect](https://www.sciencedirect.com/science/article/abs/pii/S0005109814004993?utm_source=chatgpt.com))



## 12. Përgatitja e të dhënave në Python

### 12.1 Leximi i të dhënave

Nëse skedari ka kolonat:

```text
x_cm, y_cm, Bx_uT, By_uT, Bz_uT
```

atëherë përdorni:

```python
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_csv("data/B_map_2D.csv")

print(df.head())
print(df.columns)
```

Nëse kolonat nga phyphox kanë emra të ndryshëm, kontrolloni me:

```python
print(df.columns)
```

dhe përshtatni emrat.



### 12.2 Llogaritja e intensitetit total

```python
Bx = df["Bx_uT"].to_numpy()
By = df["By_uT"].to_numpy()
Bz = df["Bz_uT"].to_numpy()

df["B_uT"] = np.sqrt(Bx**2 + By**2 + Bz**2)

print(df[["x_cm", "y_cm", "B_uT"]].head())
```



### 12.3 Zbritja e sfondit magnetik

Nëse keni matur sfondin në Eksperimentin A:

```python
df_bg = pd.read_csv("data/B_background.csv")

# Përshtatni emrat e kolonave sipas skedarit tuaj
Bx_bg = df_bg["Bx_uT"].to_numpy()
By_bg = df_bg["By_uT"].to_numpy()
Bz_bg = df_bg["Bz_uT"].to_numpy()

B_bg = np.sqrt(Bx_bg**2 + By_bg**2 + Bz_bg**2)
B_background = np.mean(B_bg)

df["DeltaB_uT"] = df["B_uT"] - B_background

print("B_background =", B_background, "uT")
```

Nëse nuk keni skedar sfondi, mund të përdorni si vlerë sfondi mesataren e pikave më larg magnetit. Kjo është më pak e pastër, por e pranueshme për këtë laborator.



## 13. Vizualizimi i hartës magnetike

### 13.1 Scatter plot me ngjyrë

Ky është vizualizimi më i thjeshtë dhe më i sigurt.

```python
plt.figure(figsize=(6, 5))

plt.scatter(df["x_cm"], df["y_cm"], c=df["B_uT"], s=120)

plt.colorbar(label="B [uT]")
plt.xlabel("x [cm]")
plt.ylabel("y [cm]")
plt.title("Harta 2D e intensitetit të fushës magnetike")
plt.axis("equal")
plt.grid(True)

plt.show()
```

Nëse doni të paraqisni vetëm perturbimin ndaj sfondit:

```python
plt.figure(figsize=(6, 5))

plt.scatter(df["x_cm"], df["y_cm"], c=df["DeltaB_uT"], s=120)

plt.colorbar(label="Delta B [uT]")
plt.xlabel("x [cm]")
plt.ylabel("y [cm]")
plt.title("Harta 2D e perturbimit magnetik")
plt.axis("equal")
plt.grid(True)
plt.show()
```



### 13.2 Heatmap për rrjetë të rregullt

Nëse të dhënat janë marrë në rrjetë të rregullt, mund të përdoret `pivot`.

```python
grid = df.pivot(index="y_cm", columns="x_cm", values="B_uT")

plt.figure(figsize=(7, 5))
plt.imshow(grid.values, origin="lower",
    extent=[df["x_cm"].min(), df["x_cm"].max(), df["y_cm"].min(), df["y_cm"].max()],
    aspect="equal")

plt.colorbar(label="B [uT]")
plt.xlabel("x [cm]")
plt.ylabel("y [cm]")
plt.title("Heatmap i fushës magnetike")
plt.show()
```

Për perturbimin:

```python
grid_delta = df.pivot(index="y_cm", columns="x_cm", values="DeltaB_uT")

plt.figure(figsize=(7, 5))
plt.imshow(grid_delta.values, origin="lower",
    extent=[df["x_cm"].min(), df["x_cm"].max(), df["y_cm"].min(), df["y_cm"].max()],
    aspect="equal")

plt.colorbar(label="Delta B [uT]")
plt.xlabel("x [cm]")
plt.ylabel("y [cm]")
plt.title("Heatmap i perturbimit magnetik")
plt.show()
```



### 13.3 Contour plot

```python
X = grid.columns.to_numpy()
Y = grid.index.to_numpy()
Z = grid.values

plt.figure(figsize=(7, 5))
cs = plt.contourf(X, Y, Z, levels=20)
plt.colorbar(cs, label="B [uT]")
plt.xlabel("x [cm]")
plt.ylabel("y [cm]")
plt.title("Contour plot i fushës magnetike")
plt.axis("equal")
plt.show()
```



### 13.4 Paraqitja e komponentëve $B_x$, $B_y$, $B_z$

Për të parë nëse një komponent dominon:

```python
fig_data = [
    ("Bx_uT", "Bx [uT]"),
    ("By_uT", "By [uT]"),
    ("Bz_uT", "Bz [uT]")
]

for col, label in fig_data:
    grid_comp = df.pivot(index="y_cm", columns="x_cm", values=col)

    plt.figure(figsize=(7, 5))
    plt.imshow(
        grid_comp.values,
        origin="lower",
        extent=[
            df["x_cm"].min(),
            df["x_cm"].max(),
            df["y_cm"].min(),
            df["y_cm"].max()
        ],
        aspect="equal"
    )

    plt.colorbar(label=label)
    plt.xlabel("x [cm]")
    plt.ylabel("y [cm]")
    plt.title(f"Harta e komponentit {col}")
    plt.show()
```



## 14. Analiza 1D e rënies së fushës me largësinë

Për Eksperimentin B:

```python
df1 = pd.read_csv("data/B_1D.csv")

df1["B_uT"] = np.sqrt(df1["Bx_uT"]**2 + df1["By_uT"]**2 + df1["Bz_uT"]**2)

# Nëse keni matur sfondin:
df1["DeltaB_uT"] = df1["B_uT"] - B_background

plt.figure(figsize=(7, 4))
plt.plot(df1["x_cm"], df1["B_uT"], "o-")
plt.xlabel("Largësia x [cm]")
plt.ylabel("B [uT]")
plt.title("Fusha magnetike si funksion i largësisë")
plt.grid(True)
plt.show()
```

Nëse përdorni $\Delta B$:

```python
plt.figure(figsize=(7, 4))
plt.plot(df1["x_cm"], df1["DeltaB_uT"], "o-")
plt.xlabel("Largësia x [cm]")
plt.ylabel("Delta B [uT]")
plt.title("Perturbimi magnetik si funksion i largësisë")
plt.grid(True)
plt.show()
```



### 14.1 Grafik log-log, opsional

Nëse duam të shohim nëse fusha bie afërsisht si fuqi e largësisë:

$$ \Delta B \propto r^{-n}$$

atëherë:

```python
# Përdor vetëm pika ku DeltaB është pozitive
mask = df1["DeltaB_uT"] > 0

r_cm = df1.loc[mask, "x_cm"].to_numpy()
DeltaB = df1.loc[mask, "DeltaB_uT"].to_numpy()

plt.figure(figsize=(6, 4))
plt.loglog(r_cm, DeltaB, "o-")
plt.xlabel("r [cm]")
plt.ylabel("Delta B [uT]")
plt.title("Grafik log-log i fushës magnetike")
plt.grid(True, which="both")
plt.show()
```

Për të vlerësuar eksponentin:

```python
log_r = np.log(r_cm)
log_B = np.log(DeltaB)

coeff = np.polyfit(log_r, log_B, 1)
slope = coeff[0]
intercept = coeff[1]

print("slope =", slope)
print("Eksponenti i përafërt n =", -slope)
```

Për një dipol ideal pritet afërsisht $n \approx 3$, por në eksperiment me smartphone rezultati mund të devijojë ndjeshëm. Kjo duhet diskutuar si pjesë e raportit.



## 15. Analiza statistikore e matjeve në një pikë

Nëse në çdo pikë regjistrohen disa sekonda të dhëna, mund të llogaritet mesatarja dhe devijimi standard.

Shembull për një pikë:

```python
df_point = pd.read_csv("data/point_x4_y0.csv")

df_point["B_uT"] = np.sqrt(df_point["Bx_uT"]**2 + df_point["By_uT"]**2 + df_point["Bz_uT"]**2)

print("B mesatare:", df_point["B_uT"].mean())
print("Devijimi standard:", df_point["B_uT"].std(ddof=1))

plt.figure(figsize=(7, 4))
plt.plot(df_point["B_uT"])
plt.xlabel("Indeksi i matjes")
plt.ylabel("B [uT]")
plt.title("Stabiliteti i matjes në një pikë")
plt.grid(True)
plt.show()
```

Kjo ndihmon studentët të shohin nëse sensori jep vlera të qëndrueshme ose nëse ka luhatje të mëdha.



## 16. Çfarë duhet të raportojnë studentët

Raporti në Jupyter duhet të përmbajë:

### 16.1 Përshkrimi i eksperimentit

-   Çfarë telefoni u përdor?
-   Çfarë aplikacioni u përdor?
-   Çfarë magneti u përdor?
-   Sa ishte madhësia e rrjetës?
-   Sa ishte hapi i rrjetës?
-   Ku u vendos magneti?
-   Si u mbajt telefoni?
-   A u mat sfondi magnetik?
-   A kishte objekte metalike pranë?



### 16.2 Tabela përmbledhëse

Shembull:

| Eksperimenti | $B_{\text{min}}$ [$\mu\text{T}$] | $B_{\text{max}}$ [$\mu\text{T}$] | $B_{\text{mean}}$ [$\mu\text{T}$] | $\Delta B_{\text{max}}$ [$\mu\text{T}$] |
| ------------ | -------------------------------- | -------------------------------- | --------------------------------- | --------------------------------------- |
| Sfondi       | ...                              | ...                              | ...                               | ...                                     |
| Magneti 1D   | ...                              | ...                              | ...                               | ...                                     |
| Harta 2D     | ...                              | ...                              | ...                               | ...                                     |



### 16.3 Grafikët minimalë

Raporti duhet të përfshijë:

1.  $B(t)$ për matjen e sfondit.
2.  $B(x)$ ose $\Delta B(x)$ për matjen 1D.
3.  Hartën 2D të $B(x,y)$.
4.  Hartën 2D të $\Delta B(x,y)$, nëse është matur sfondi.
5.  Opsionale: komponentët $B_x$, $B_y$, $B_z$ veçmas.
6.  Opsionale: grafik log-log për rënien e fushës me largësinë.



### 16.4 Diskutimi

Studentët duhet të diskutojnë:

-   Ku është fusha më e madhe?
-   A është harta simetrike?
-   A ndikon orientimi i telefonit?
-   A vërehet qartë ndikimi i magnetit mbi fushën e Tokës?
-   Sa të qëndrueshme janë matjet në kohë?
-   A është më e kuptueshme harta e $B$ apo e $\Delta B$?
-   Cilat janë burimet kryesore të gabimit?
-   Pse nuk duhet t’i besojmë verbërisht vlerës absolute të magnetometrit të telefonit?
-   A duket sjellja 1D e fushës e ngjashme me rënien $1/r^3$?



## 17. Burimet kryesore të pasigurisë

Në këtë laborator burimet më të rëndësishme të pasigurisë janë:

1.  **Pozicioni i panjohur i magnetometrit brenda telefonit.**
    Sensori nuk ndodhet domosdoshmërisht në qendër të telefonit.
2.  **Orientimi i telefonit.**
    Nëse telefoni rrotullohet, komponentët $B_x$, $B_y$, $B_z$ ndryshojnë edhe kur fusha fizike nuk ndryshon.
3.  **Rikalibrimi automatik.**
    Telefoni mund të korrigjojë bias-in e magnetometrit gjatë matjes.
4.  **Objektet metalike pranë.**
    Tavolinat metalike, laptopët, altoparlantët, kabllot dhe çelësat mund të ndryshojnë fushën lokale.
5.  **Magneti nuk është dipol ideal.**
    Afër magnetit fusha është komplekse dhe nuk ndjek saktësisht modelin $1/r^3$.
6.  **Lartësia e telefonit mbi planin e rrjetës.**
    Nëse lartësia ndryshon nga pika në pikë, matja ndryshon.
7.  **Zhurma dhe drift-i i sensorit.**
    Leximet mund të ndryshojnë në kohë edhe kur telefoni nuk lëviz.



## 18. Strukturë e rekomanduar e folderit

```text
LAB12_Magnetic_Field/
│
├── data/
│   ├── B_background.csv
│   ├── B_1D.csv
│   └── B_map_2D.csv
│
├── figs/
│   ├── B_background_time.png
│   ├── B_vs_distance.png
│   ├── B_map_2D.png
│   └── DeltaB_map_2D.png
│
└── Raport_LAB12.ipynb
```



## 19. Pyetje për studentët

1.  Pse fusha magnetike është madhësi vektoriale?
2.  Çfarë përfaqësojnë $B_x$, $B_y$, $B_z$?
3.  Pse përdorim $B = \sqrt{B_x^2+B_y^2+B_z^2}$?
4.  Pse duhet matur sfondi magnetik?
5.  Çfarë ndryshon nëse telefoni rrotullohet gjatë matjes?
6.  Pse harta e fushës pranë magnetit nuk është domosdoshmërisht simetrike?
7.  Pse magnetometri i telefonit është i mirë për demonstrim, por jo për matje absolute profesionale?
8.  Pse fusha bie me largësinë nga magneti?
9.  Çfarë kufizimesh ka modeli $B \propto 1/r^3$?
10.  Si mund të përmirësohej eksperimenti nëse do të kishim një magnetometër profesional?



## 20. Referenca të rekomanduara

1.  **phyphox — Magnetic field sensor**
    Dokumentim i eksperimentit “Magnetic field” dhe kufizimet praktike të magnetometrit në telefon. ([phyphox](https://phyphox.org/wiki/index.php/Sensor%3A_Magnetic_field?utm_source=chatgpt.com))
2.  **Android Open Source Project — Sensor types: Magnetic field sensor**
    Përshkruan sensorin magnetik në Android dhe njësitë e matjes në $\mu\text{T}$. ([Android Open Source Project](https://source.android.com/docs/core/interaction/sensors/sensor-types?utm_source=chatgpt.com))
3.  **NOAA/NCEI — World Magnetic Model**
    Burim zyrtar për modelimin e fushës magnetike të Tokës dhe përdorimin e saj në navigim. ([NCEI](https://www.ncei.noaa.gov/products/world-magnetic-model?utm_source=chatgpt.com))
4.  **NOAA/NCEI — Geomagnetism**
    Për informacion më të gjerë mbi fushën gjeomagnetike dhe të dhënat magnetike. ([NCEI](https://www.ncei.noaa.gov/products/geomagnetic-data?utm_source=chatgpt.com))
5.  **Arribas et al., “Measurement of the magnetic field of small magnets with a smartphone”**
    Shembull i përdorimit të smartphone për matjen e fushës së magneteve të vegjël në laborator hyrës të fizikës. ([ResearchGate](https://www.researchgate.net/publication/281427984_Measurement_of_the_magnetic_field_of_small_magnets_with_a_smartphone_A_very_economical_laboratory_practice_for_introductory_physics_courses?utm_source=chatgpt.com))



## 21. Përfundimi i pritshëm

Ky laborator duhet t’u tregojë studentëve se fusha magnetike mund të trajtohet si një madhësi fizike e matshme në hapësirë. Duke përdorur një sensor të thjeshtë si magnetometri i telefonit, ata mund të ndërtojnë një hartë 2D, të vizualizojnë ndryshimet hapësinore dhe të diskutojnë burimet reale të pasigurisë.

Mesazhi kryesor është:

**një sensor i thjeshtë mund të japë të dhëna shumë interesante, por interpretimi fizik kërkon kujdes, kontroll të kushteve eksperimentale dhe analizë kritike të kufizimeve të instrumentit.**
