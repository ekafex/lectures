# Hyrje në Git, GitHub dhe GitHub Classroom

*(Për përdorim në Hyrje në laboratorin e Fizikës & Shkencave Kompjuterike)*



# 1. Çfarë është Git?

**Git** është një sistem për kontroll versionesh (version control system).

Ai përdoret për:

* Ruajtjen e ndryshimeve në skedarë
* Mbajtjen e historikut të punës
* Rikthimin në versione të mëparshme
* Bashkëpunimin në projekte

Në mënyrë të thjeshtë:

> Git ju lejon të ruani “fotografi” të punës suaj në momente të ndryshme.



# 2. Çfarë është GitHub?

**GitHub** është një platformë online ku ruhen repository-t Git.

Një **repository** është një dosje projekti që përmban:

* Skedarët tuaj
* Historikun e ndryshimeve
* Versionet e mëparshme

GitHub ofron:

* Ruajtje online
* Gjurmim të ndryshimeve
* Kontroll të kohës së dorëzimit
* Transparencë



# 3. Çfarë është GitHub Classroom?

**GitHub Classroom** është sistemi që përdorim për dorëzimin e laboratorëve.

Procesi është:

1. Ju pranoni detyrën (Accept Assignment).
2. Sistemi krijon një repository privat vetëm për ju.
3. Ju punoni lokalisht në kompjuter.
4. Ju e ngarkoni versionin final në GitHub.
5. Pedagogu sheh versionin e dorëzuar.


# 4. Si Funksionon Procesi i Dorëzimit

Procesi për çdo laborator është:

### Hapi 1 – Pranoni detyrën

Klikoni linkun e GitHub Classroom dhe pranoni assignment-in.

### Hapi 2 – Klononi repository-n

Shkarkoni kopjen lokale në kompjuterin tuaj.

```bash
git clone <linku-i-repository>
cd <emri-i-dosjes>
```

### Hapi 3 – Punoni në notebook

Hapni JupyterLab dhe modifikoni notebook-un.

### Hapi 4 – Dorëzoni versionin final

```bash
git add .
git commit -m "Final submission"
git push
```

Nëse ndryshimet shfaqen në GitHub → dorëzimi është i suksesshëm.



# 5. Çfarë DUHET të kuptoni (minimalisht)

Në këtë lëndë mjafton të kuptoni:

* `git clone` → shkarko projektin
* `git add .` → përgatit ndryshimet
* `git commit` → ruaj një version
* `git push` → ngarko në GitHub

Asgjë më shumë.



# 6. Çfarë NUK kërkohet nga ju

Nuk kërkohet të dini:

* Degë (branches)
* Merge
* Pull requests
* Konflikte
* Git të avancuar

Git përdoret vetëm për dorëzim dhe ruajtje të punës.



# 7. Pse e përdorim Git në këtë lëndë?

Sepse laboratorët modernë:

* Janë digjitalë
* Janë të riprodhueshëm
* Janë të gjurmueshëm
* Janë të dokumentuar profesionalisht

Git:

* Eliminon konfuzionin me versione
* Parandalon humbjen e punës
* Regjistron kohën reale të dorëzimit
* Forcon disiplinën akademike



# 8. Rregulla të Rëndësishme

* Dorëzoni vetëm versionin final.
* Sigurohuni që notebook-u ekzekutohet pa gabime.
* Mos ndryshoni strukturën e repository-t.
* Mos e dërgoni punën me email.



# 9. Filozofia e Përdorimit

Git nuk është qëllimi.

Qëllimi është:

> Të silleni si punonjës në një laborator shkencor modern.

Dokumentim.
Riprodhueshmëri.
Profesionalizëm.



# 10. Përfundim

Git dhe GitHub janë mjete.

Në këtë kurs ato përdoren për:

* Dorëzim të kontrolluar
* Menaxhim versionesh
* Kulturë profesionale laboratorike

Do të përdorni vetëm funksionet bazë.

Me kalimin e kohës, kjo do të bëhet rutinë.
