# LAB11 — Saktësia e GPS/GNSS dhe Variacioni i Pozicionit

## 1. Qëllimi i laboratorit

Qëllimi i këtij laboratori është të studiohet se si ndryshon pozicioni i matur nga një smartphone edhe kur telefoni qëndron i palëvizur. Studentët do të regjistrojnë të dhëna GPS/GNSS në kohë, do të analizojnë shpërndarjen e koordinatave dhe do të vlerësojnë saktësinë praktike të matjes së pozicionit.

Në këtë laborator, pozicioni nuk trajtohet si një numër i vetëm “i saktë”, por si një madhësi eksperimentale me variacion, devijim dhe pasiguri.



## 2. Objektivat

Në fund të laboratorit studenti duhet të jetë në gjendje të:

1. Shpjegojë në mënyrë të thjeshtë parimin bazë të përcaktimit të pozicionit me GPS/GNSS.
2. Regjistrojë të dhëna pozicioni me smartphone.
3. Përpunojë koordinatat gjeografike: gjerësi gjeografike, gjatësi gjeografike, lartësi dhe kohë.
4. Konvertojë ndryshimet e koordinatave nga gradë në metra.
5. Ndërtojë grafikë të tipit:

   * pozicioni në kohë,
   * shpërndarja 2D e pikave,
   * histogrami i devijimit radial,
   * krahasimi brënda/jashtë (indoor/outdoor).
6. Llogarisë madhësi statistikore si mesatarja, devijimi standard dhe gabimi radial.
7. Diskutojë burimet kryesore të pasaktësisë: gjeometria e satelitëve, bllokimi i sinjalit, ndërtesat, reflektimet dhe cilësia e marrësit.



## 3. Bazat teorike (shkurtimisht)

GPS është pjesë e familjes më të gjerë **GNSS** — Global Navigation Satellite Systems. GNSS përfshin sisteme si GPS (Amerikan), Galileo (Europian), GLONASS (Rus) dhe BeiDou (Kinez), të cilat transmetojnë sinjale nga satelitët drejt marrësve në Tokë. Marrësi përdor kohën e mbërritjes së sinjaleve për të llogaritur largësinë nga disa satelitë dhe, prej tyre, pozicionin. Për përcaktimin e pozicionit dhe kohës nevojiten zakonisht sinjale nga të paktën katër satelitë. ([GPS.gov][1])

Saktësia e pozicionit nuk është konstante. Sipas GPS.gov, telefonat inteligjentë me GPS janë zakonisht të saktë brenda një rrezeje rreth **4.9 m** në qiell të hapur, por saktësia përkeqësohet pranë ndërtesave, urave, pemëve dhe pengesave të tjera. Faktorë të rëndësishëm janë gjeometria e satelitëve, bllokimi i sinjalit, atmosfera dhe cilësia e marrësit. ([GPS.gov][2])

Në këtë laborator nuk kërkohet të arrihet saktësi gjeodezike. Qëllimi është të studiohet **sjellja statistikore e matjeve të pozicionit** me pajisje të zakonshme.



## 4. Pajisjet dhe programet e nevojshme

### Pajisje

* Telefon inteligjent me GPS/GNSS.
* Laptop me Python/Jupyter.
* Akses në një hapësirë të hapur jashtë ndërtesës.
* Mundësisht: një pikë referimi fikse, p.sh. qoshe godine, stol, shtyllë, shenjë në tokë.

### Aplikacione të rekomanduara

Përdorni një nga këto:

1. **phyphox** — i përshtatshëm për laboratorë mësimorë, i disponueshëm në Android dhe iOS. Mund të lexojë sensorët e telefonit dhe të eksportojë të dhënat për analizë. Eksperimenti “Location (GPS)” jep të dhëna nga sensori GPS/lokacionit të telefonit. ([App Store][3])
2. **GPSLogger for Android** — aplikacion open-source për Android që mund të ruajë të dhëna në formate GPX, KML, CSV dhe NMEA. Është shumë praktik për eksportimin e të dhënave në CSV/GPX. ([F-Droid][4])
3. **Google GNSSLogger** — përdoret për matje më të avancuara, sidomos për të dhëna GNSS të papërpunuara. Kërkon që telefoni të mbështesë raw GNSS measurements; jo të gjithë telefonat e mbështesin këtë. ([GitHub][5])

Për këtë laborator rekomandohet **phyphox** ose **GPSLogger**, sepse janë më të thjeshta për studentët.



## 5. Struktura e laboratorit

Laboratori ndahet në tre eksperimente kryesore:

1. **Eksperimenti A:** Telefoni i palëvizur në qiell të hapur.
2. **Eksperimenti B:** Telefoni i palëvizur pranë ndërtesës ose brenda ndërtesës.
3. **Eksperimenti C:** Lëvizje e ngadaltë përgjatë një rruge të shkurtër të njohur.

Eksperimenti A është eksperimenti bazë. Eksperimentet B dhe C shërbejnë për krahasim.



# 6. Procedura eksperimentale

## Eksperimenti A — Variacioni i pozicionit në qiell të hapur

### Qëllimi

Të matet se si ndryshon pozicioni i raportuar nga GPS/GNSS kur telefoni qëndron i palëvizur.

### Procedura

1. Dilni në një hapësirë të hapur, larg ndërtesave të larta.
2. Vendoseni telefonin në një pozicion fiks mbi një sipërfaqe të qëndrueshme.
3. Hapni aplikacionin e regjistrimit GPS.
4. Prisni 1–2 minuta që sinjali të stabilizohet.
5. Regjistroni të dhëna për **5–10 minuta**.
6. Intervali i regjistrimit duhet të jetë rreth **1 s**.
7. Eksportoni të dhënat në format **CSV** ose **GPX**.
8. Ruani skedarin me emër të qartë, p.sh.:

```text
data/gps_outdoor_stationary.csv
```

### Të dhënat minimale që duhen ruajtur

* Koha
* Gjërësia gjeografike (Latitude)
* Gjatësia gjeografike (Longitude)
* Lartësia (Altitude), nëse jepet
* Saktësia (Accuracy), nëse jepet nga aplikacioni
* Numri i satelitëve, nëse jepet



## Eksperimenti B — Krahasimi me kushte të këqija sinjali

### Qëllimi

Të krahasohet saktësia në qiell të hapur me saktësinë pranë pengesave.

### Procedura

Përsëritni Eksperimentin A në një nga këto kushte:

* pranë një ndërtese të lartë,
* në oborr të ngushtë,
* pranë pemëve,
* brenda ndërtesës, nëse telefoni ende jep pozicion.

Regjistroni përsëri të dhëna për **5–10 minuta** dhe ruajini si:

```text
data/gps_near_building.csv
```

ose

```text
data/gps_indoor.csv
```



## Eksperimenti C — Lëvizje përgjatë një rruge të shkurtër

### Qëllimi

Të shihet si duket trajektorja GPS kur telefoni lëviz përgjatë një rruge të thjeshtë.

### Procedura

1. Zgjidhni një rrugë të shkurtër, p.sh. një vijë të drejtë 30–50 m.
2. Filloni regjistrimin.
3. Ecni ngadalë dhe me shpejtësi sa më konstante.
4. Ndaloni regjistrimin në fund të rrugës.
5. Eksportoni të dhënat si:

```text
data/gps_walk.csv
```

Ky eksperiment është më cilësor sesa sasior. Qëllimi është të shihen devijimet e trajektores së matur nga rruga reale.



# 7. Përgatitja e të dhënave në Python

Nëse të dhënat janë në CSV, përdorni kodin më poshtë. Emrat e kolonave mund të ndryshoni sipas aplikacionit, prandaj studentët duhet t’i kontrolloni me `df.columns`.

```python
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Lexo skedarin CSV
df = pd.read_csv("data/gps_outdoor_stationary.csv")

# Shfaq emrat e kolonave
print(df.columns)

# Shembull: përshtatni këto emra sipas skedarit tuaj
lat_col = "latitude"
lon_col = "longitude"
time_col = "time"

df = df.dropna(subset=[lat_col, lon_col])

lat = df[lat_col].to_numpy()
lon = df[lon_col].to_numpy()

print("Numri i matjeve:", len(df))
print("Latitude mesatare:", np.mean(lat))
print("Longitude mesatare:", np.mean(lon))
```

Nëse aplikacioni përdor emra si `Latitude`, `Longitude`, `lat`, `lon`, ose `location_latitude`, ndryshoni rreshtat:

```python
lat_col = "latitude"
lon_col = "longitude"
```

sipas rastit.



# 8. Konvertimi i koordinatave në metra

Latitude dhe longitude janë në gradë, por për analizë eksperimentale duam devijime në metra. Për zona të vogla, mund të përdoret përafrimi lokal:

$$x = R \cos(\bar{\phi}) (\lambda - \bar{\lambda}) $$

$$ y = R(\phi - \bar{\phi}) $$

ku:

* $R = 6371000 , \text{m}$ është rrezja mesatare e Tokës,
* $\phi$ është latitude në radianë,
* $\lambda$ është longitude në radianë,
* $\bar{\phi}$, $\bar{\lambda}$ janë vlerat mesatare.

```python
R = 6371000  # rrezja mesatare e Tokës në metra

lat_rad = np.deg2rad(lat)
lon_rad = np.deg2rad(lon)

lat0 = np.mean(lat_rad)
lon0 = np.mean(lon_rad)

x = R * np.cos(lat0) * (lon_rad - lon0)
y = R * (lat_rad - lat0)

r = np.sqrt(x**2 + y**2)

print("Devijimi standard në x [m]:", np.std(x, ddof=1))
print("Devijimi standard në y [m]:", np.std(y, ddof=1))
print("Devijimi radial mesatar [m]:", np.mean(r))
print("Devijimi radial maksimal [m]:", np.max(r))
print("68% e pikave brenda [m]:", np.percentile(r, 68))
print("95% e pikave brenda [m]:", np.percentile(r, 95))
```



# 9. Grafikët kryesorë

## 9.1 Shpërndarja 2D e pozicioneve

```python
plt.figure(figsize=(6, 6))
plt.scatter(x, y, s=10)
plt.axhline(0, linestyle="--", linewidth=1)
plt.axvline(0, linestyle="--", linewidth=1)
plt.xlabel("x [m]")
plt.ylabel("y [m]")
plt.title("Shpërndarja 2D e pozicionit GPS")
plt.axis("equal")
plt.grid(True)
plt.show()
```

Ky grafik tregon “renë” e pikave të matura rreth pozicionit mesatar. Nëse telefoni ishte i palëvizur, përhapja e pikave përfaqëson variacionin e matjes.



## 9.2 Histogrami i devijimit radial

```python
plt.figure(figsize=(7, 4))
plt.hist(r, bins=30)
plt.xlabel("Devijimi radial nga pozicioni mesatar [m]")
plt.ylabel("Numri i matjeve")
plt.title("Histogrami i gabimit radial")
plt.grid(True)
plt.show()
```

Kjo histogram tregon sa shpesh pozicioni i matur bie brenda një distance të caktuar nga pozicioni mesatar.



## 9.3 Pozicioni në funksion të kohës

```python
plt.figure(figsize=(8, 4))
plt.plot(x, label="x")
plt.plot(y, label="y")
plt.xlabel("Indeksi i matjes")
plt.ylabel("Devijimi [m]")
plt.title("Ndryshimi i pozicionit në kohë")
plt.legend()
plt.grid(True)
plt.show()
```

Ky grafik tregon nëse pozicioni ka drift gradual, kërcime të papritura ose luhatje rreth mesatares.



## 9.4 Krahasimi i dy kushteve

Përdorni këtë funksion për të analizuar dy skedarë, p.sh. jashtë dhe pranë ndërtesës.

```python
def load_gps_csv(filename, lat_col="latitude", lon_col="longitude"):
    df = pd.read_csv(filename)
    df = df.dropna(subset=[lat_col, lon_col])

    lat = df[lat_col].to_numpy()
    lon = df[lon_col].to_numpy()

    R = 6371000
    lat_rad = np.deg2rad(lat)
    lon_rad = np.deg2rad(lon)

    lat0 = np.mean(lat_rad)
    lon0 = np.mean(lon_rad)

    x = R * np.cos(lat0) * (lon_rad - lon0)
    y = R * (lat_rad - lat0)
    r = np.sqrt(x**2 + y**2)

    return x, y, r


x1, y1, r1 = load_gps_csv("data/gps_outdoor_stationary.csv")
x2, y2, r2 = load_gps_csv("data/gps_near_building.csv")

plt.figure(figsize=(7, 4))
plt.hist(r1, bins=30, alpha=0.6, label="Qiell i hapur")
plt.hist(r2, bins=30, alpha=0.6, label="Pranë ndërtesës")
plt.xlabel("Devijimi radial [m]")
plt.ylabel("Numri i matjeve")
plt.title("Krahasimi i saktësisë GPS")
plt.legend()
plt.grid(True)
plt.show()

print("Qiell i hapur: 95% brenda", np.percentile(r1, 95), "m")
print("Pranë ndërtesës: 95% brenda", np.percentile(r2, 95), "m")
```



# 10. Çfarë duhet të raportoni studentët

Raporti në Jupyter duhet të përmbajë:

## 10.1 Përshkrimi i eksperimentit

* Ku u krye matja?
* Çfarë telefoni u përdor?
* Çfarë aplikacioni u përdor?
* Sa zgjati matja?
* Cili ishte intervali i regjistrimit?
* A ishte telefoni i palëvizur apo në lëvizje?
* A kishte ndërtesa, pemë ose pengesa pranë?

## 10.2 Tabela përmbledhëse

Shembull:

| Kushti          | Numri i pikave | $\sigma_x$ [m] | $\sigma_y$ [m] | $r_{68}$ [m] | $r_{95}$ [m] | $r_{max}$ [m] |
| --------------- | -------------: | -------------: | -------------: | -----------: | -----------: | ------------: |
| Qiell i hapur   |            ... |            ... |            ... |          ... |          ... |           ... |
| Pranë ndërtesës |            ... |            ... |            ... |          ... |          ... |           ... |
| Brenda          |            ... |            ... |            ... |          ... |          ... |           ... |

ku:

* $r_{68}$ është rrezja brenda së cilës bien 68% e matjeve,
* $r_{95}$ është rrezja brenda së cilës bien 95% e matjeve.

## 10.3 Grafikët

Raporti duhet të përfshijë minimalisht:

1. Shpërndarjen 2D për matjen në qiell të hapur.
2. Histogramin e devijimit radial.
3. Krahasimin outdoor/near-building ose outdoor/indoor.
4. Nëse bëhet Eksperimenti C: trajektoren e ecjes.

## 10.4 Diskutim

Studentët duhet të diskutojnë:

* A është pozicioni konstant kur telefoni qëndron i palëvizur?
* Sa është përhapja tipike e pikave?
* A përputhet rezultati me saktësinë e pritshme të GPS në telefon?
* Si ndryshon matja pranë ndërtesave?
* A ka drift në kohë?
* A ka pika shumë larg mesatares?
* Pse nuk duhet interpretuar një matje e vetme GPS si “pozicion absolutisht i saktë”?



# 11. Pyetje për analizë

1. Pse duhen të paktën katër satelitë për të përcaktuar pozicionin dhe kohën?
2. Pse pozicioni ndryshon edhe kur telefoni është i palëvizur?
3. Cili është ndryshimi midis saktësisë dhe precizionit në këtë eksperiment?
4. Pse sinjali GPS përkeqësohet pranë ndërtesave?
5. Çfarë kuptimi ka $r_{95}$?
6. A është mesatarja e pozicioneve gjithmonë pozicioni “i vërtetë”? Pse?
7. Çfarë do të ndryshonte nëse do të përdornim një marrës GNSS profesional me RTK?



# 12. Kujdes praktik

* Mos e mbani telefonin në dorë gjatë matjes së palëvizshme; vendoseni mbi një sipërfaqe fikse.
* Mos e ndryshoni orientimin e telefonit gjatë matjes.
* Mos e bëni matjen shumë afër mureve metalike, makinave ose strukturave të mëdha metalike.
* Prisni pak para se të filloni regjistrimin, sepse marrësi mund të ketë nevojë për kohë stabilizimi.
* Shënoni kushtet reale të matjes; pa këto shënime, të dhënat janë të vështira për t’u interpretuar.



# 13. Strukturë e rekomanduar e folderit

```text
LAB11_GPS/
│
├── data/
│   ├── gps_outdoor_stationary.csv
│   ├── gps_near_building.csv
│   └── gps_walk.csv
│
├── figs/
│   ├── gps_scatter_outdoor.png
│   ├── gps_radial_histogram.png
│   └── gps_comparison.png
│
└── Raport_LAB11.ipynb
```



# 14. Referenca të rekomanduara

1. **GPS.gov — What is GPS?**
   Burim zyrtar për përshkrimin e sistemit GPS, segmentet e tij dhe rolin në pozicionim, navigim dhe kohë. ([GPS.gov][1])

2. **GPS.gov — GPS Accuracy**
   Shpjegon faktorët që ndikojnë në saktësinë reale të GPS dhe jep vlerën tipike për smartphone në qiell të hapur. ([GPS.gov][2])

3. **NASA Space Place — How Does GPS Work?**
   Shpjegim shumë i thjeshtë dhe vizual për studentë fillestarë. ([NASA Space Place][6])

4. **EUSPA — What is GNSS?**
   Shpjegon termin GNSS dhe sistemet kryesore globale si Galileo, GPS, GLONASS dhe BeiDou. ([EU Agency for the Space Programme][7])

5. **phyphox — Location (GPS)**
   Dokumentim i eksperimentit GPS në phyphox. I përshtatshëm për përdorim laboratorik me telefon. ([phyphox][8])

6. **GPSLogger for Android**
   Aplikacion praktik për regjistrim të koordinatave dhe eksport në GPX, KML, CSV dhe NMEA. ([F-Droid][4])

7. **Android Developers — Raw GNSS Measurements**
   Për studentë më të avancuar që duan të kuptojnë ose përdorin matje të papërpunuara GNSS në Android. ([Android Developers][9])



# 15. Përfundime

Në fund të laboratorit, studentët duhet të kuptojnë se GPS/GNSS është një instrument matës real, jo një burim koordinatash perfekte. Edhe kur telefoni nuk lëviz, pozicioni i matur formon një shpërndarje statistikore. Kjo shpërndarje mund të matet, vizualizohet dhe karakterizohet me metoda standarde të analizës së të dhënave.

Ky laborator lidh në mënyrë natyrale fizikën eksperimentale, sensorët modernë, statistikat dhe programimin në Python.



[1]: https://www.gps.gov/gps?utm_source=chatgpt.com "The Global Positioning System (GPS) is a US ..."
[2]: https://www.gps.gov/gps-accuracy-0?utm_source=chatgpt.com "GPS Accuracy"
[3]: https://apps.apple.com/no/app/phyphox/id1127319693?utm_source=chatgpt.com "phyphox - App Store"
[4]: https://f-droid.org/en/packages/com.mendhak.gpslogger/?utm_source=chatgpt.com "GPSLogger | F-Droid - Free and Open Source Android App ..."
[5]: https://github.com/Google/gps-measurement-tools?utm_source=chatgpt.com "google/gps-measurement-tools"
[6]: https://spaceplace.nasa.gov/gps/?utm_source=chatgpt.com "How Does GPS Work?"
[7]: https://www.euspa.europa.eu/eu-space-programme/galileo/what-gnss?utm_source=chatgpt.com "What is GNSS | EU Agency for the Space Programme"
[8]: https://phyphox.org/experiment/location-gps/?utm_source=chatgpt.com "Location (GPS)"
[9]: https://developer.android.com/develop/sensors-and-location/sensors/gnss?utm_source=chatgpt.com "Raw GNSS Measurements | Sensors and location"

