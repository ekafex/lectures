# Git & GitHub – Udhëzues Minimal

Ky dokument është një **hyrje shumë e shkurtër në Git dhe GitHub**, e mjaftueshme për të menaxhuar dhe dorëzuar raportet laboratorike.

Qëllimi nuk është të mësoni Git në thellësi, por të kuptoni **workflow minimal të kontrollit të versioneve (version controll)**.

Për dokumentacion të plotë referohuni burimeve zyrtare të Git.

------

# 1. Çfarë është Git?

**Git** është një sistem për **kontrollin e versioneve (version control system)** që ruan historinë e ndryshimeve të skedarëve të një projekti.

Ai përdoret gjerësisht në:

-   zhvillimin e software
-   projekte kërkimore
-   analiza të të dhënave
-   bashkëpunim shkencor

Git ju lejon të:

-   ruani historinë e punës suaj
-   riktheheni në versione të mëparshme
-   bashkëpunoni me të tjerë në një projekt

Për përshkrimin zyrtar shihni:

https://git-scm.com/about



# 2. Instalimi i Git

Git mund të shkarkohet nga faqja zyrtare:

https://git-scm.com/

Instaloni versionin për sistemin tuaj operativ.

Pas instalimit kontrolloni nga terminali:

```bash
git --version
```

Nëse Git është instaluar saktë do të shfaqet versioni.

Pastaj konfiguroni identitetin tuaj (bëhet vetëm një herë):

```bash
git config --global user.name "Emri Juaj"
git config --global user.email "email@example.com"
```

Kontrolloni konfigurimin:

```bash
git config --global --list
```



# 3. Si të mësoni Git

Git është një sistem i fuqishëm dhe ka shumë komanda.

Dokumentacioni zyrtar për fillestarët:

**Git Learning Resources**

https://git-scm.com/learn

Një përmbledhje e komandave më të zakonshme:

**Git Cheat Sheet**

https://git-scm.com/cheat-sheet

Në këtë kurs ne do të përdorim **vetëm një numër shumë të vogël komandash**.



# 4. Çfarë është një Repository

Një **repository (repo)** është një dosje projekti e ndjekur nga Git.

Repository përmban:

-   kodin ose dokumentet
-   historinë e ndryshimeve
-   versionet e mëparshme

Një repository mund të jetë:

-   **lokal** (në kompjuterin tuaj)
-   **online** në një platformë hosting.



# 5. Git Hosting

Git është një mjet lokal, por zakonisht projektet ruhen edhe online.

Platforma të njohura për **Git hosting** janë:

-   GitHub
-   GitLab
-   Bitbucket

Në këtë kurs ne do të përdorim **GitHub**, një nga platformat më të përdorura në botë për projekte software dhe kërkimore.

GitHub lejon:

-   ruajtjen e projekteve online
-   bashkëpunimin
-   dorëzimin e punëve laboratorike



# 6. Krijimi i një llogarie GitHub

Shkoni në:

[https://github.com](https://github.com/)

dhe krijoni një llogari personale.

Rekomandohet:

-   username serioz
-   email real
-   verifikim i email-it



# 7. Krijimi i një Repository në GitHub

Në GitHub:

1.  klikoni **+**
2.  zgjidhni **New repository**

Plotësoni:

**Repository name**

``` 
Hyrje_Laborator
```

**Description**

opsionale, p.sh.

```
Raportet e përjavshme për kursin hyrje në laborator
```

**Visibility**

-   Public
-   Private

Për raportet laboratorike zakonisht përdoret **Private**.

Pastaj klikoni:

**Create repository**



# 8. Krijimi i projektit lokalisht (në kompjuter)

Në terminal:

```bash
cd path/te/folderi
git init
```

Kjo e kthen folderin në një **local Git repository**.



# 9. Workflow minimal i Git-it

Në këtë kurs do të përdorim vetëm këtë workflow:

```bash
git status
git add .
git commit -m "mesazh konciz cfare ndryshimesh keni bere"
git push
```

Kuptimi:

| komanda | Kupimi |
| -------------- | ----------- |
| `git status` | tregon çfarë ka ndryshuar në projekt. |
| `git add .` | përgatit ndryshimet për commit. |
| `git commit` | ruan një version të projektit. |
| `git push` | ngarkon versionin në GitHub. |



# 10. Lidhja e projektit lokal me GitHub

Pasi krijoni repository në GitHub:

```bash
git remote add origin https://github.com/USERNAME/REPOSITORY.git
```

Pastaj:

```bash
git branch -M main
git push -u origin main
```



# 11. Workflow tipik për raportet laboratorike

Pas çdo përditësimi (update) të raportit:

```bash
git status
git add .
git commit -m "Përditësim i raportit"
git push
```

>   **Në mesazh është e rekomandueshme të specifikoni me saktësi se cfarë ndryshimesh keni bvrë në këtë version. Kjo ju mundëson juve apo ndonjë bashkëpunëtorin tuaj që të kuptojnë me saktësi rëndësinë e ndryshimeve që keni bërë në kod dhe cfarë realisht është updated në këtë version. Ky mesazh duhet të jetë informues edhe kur ta lexoni pas një farë kohe të gjatë.**



Para dorëzimit:

```bash
git commit -m "Versioni final i raportit"
git push
```



# 12. Komandat minimale që duhet të mbani mend

```bash
git init
git status
git add .
git commit -m "mesazh"
git push
git pull


# ========================================
# -----------------------------
# Shtesa per ato qe jane kurioz
# -----------------------------
git log  #shiko historikun e ndryshimeve
git switch --detach <commit-hash> #per te shkuar mbrapa ne kohe ne historikun e commit
git switch -c new-branch <commit-hash> # per te ndertuar nje branch te ri ne ate commit
git log --oneline # gjen commit-hash (numrin unik "hash" qe i korespondon commit)
#------
# krijo branches
git switch -c feature-x # create a new branch with branch name "feature-x"
git checkout -b feature-x # equivalent to git switch -c feature-x
git branch feature-x # zhvendosu te branch feature-x (git switch main)
#------
# merge branches
git switch main # ndiqe me komanden "git merge feature-x"
git merge feature-x # merge feature-x ne main
#-----
# delete branch
git branch -d feature-x
git branch -D feature-x # force delete ne rast se branch nuk eshte merge

```



---

> <h3> Me një fjali </h3>
>
> **Git ruan historinë e punës suaj, ndërsa GitHub e ruan atë online dhe ju lejon ta dorëzoni ose ta ndani me të tjerë.**

---






# 14. Dorëzimi i Raporteve përmes GitHub Classroom

Në këtë kurs raportet laboratorike dorëzohen përmes **GitHub Classroom**.

GitHub Classroom krijon automatikisht një **repository personal për çdo student**, ku do të ngarkoni raportin tuaj.

#### 1. Pranimi i Assignment-it

Instruktori do të publikojë një **link për assignment-in**.

Studentët duhet të:

1. hapin linkun e GitHub Classroom
2. të bëjnë **Accept assignment**

Pas këtij veprimi GitHub do të krijojë automatikisht një repository personal për studentin.

Shembull emri repository:

```
raport-LAB-01-username
```

Ky repository është vendi ku duhet të dorëzohet raporti.



#### 2. Shkarkimi i Repositorit në kompjuter

Pas krijimit të repository, kopjoni **URL-në e repository**.

Në terminal psh:

```bash
git clone https://github.com/ORG/assignment-repository.git
```

Kjo komandë shkarkon projektin në kompjuterin tuaj.

Pastaj hyni në dosjen e projektit:

```bash
cd assignment-repository
```



#### 3. Shtimi i raportit laboratorik

Vendosni brenda repository:

* notebook (.ipynb)
* figura
* të dhëna (nëse ka)
* skedarë të tjerë të nevojshëm



#### 4. Ruajtja e ndryshimeve me Git

Pasi të përditësoni raportin:

```bash
git status
git add .
git commit -m "Update lab report"
```



#### 5. Ngarkimi në GitHub

Ngarkoni ndryshimet në repository:

```bash
git push
```

Pas kësaj raporti juaj është **dorëzuar në GitHub Classroom**.

Instruktori mund të shohë versionin tuaj direkt nga repository.



#### 6. Përditësimi i raportit

Nëse vazhdoni të punoni mbi raportin mund të bëni përsëri:

```bash
git add .
git commit -m "Improve analysis"
git push
```

Versioni i fundit në GitHub do të konsiderohet **versioni i dorëzuar**.



#### 7. Kontrolli i dorëzimit

Për të verifikuar dorëzimin:

1. hapni repository në GitHub
2. kontrolloni që skedarët janë ngarkuar
3. kontrolloni commit-in e fundit



#### 8. Gabime të zakonshme

##### Nuk bëhet push

Commit-i në kompjuter **nuk është dorëzim** derisa të bëni:

```bash
git push
```

##### Ngarkohet notebook pa output

Sigurohuni që notebook të jetë **ekzekutuar dhe ruajtur** para dorëzimit.

##### Repository i gabuar

Dorëzimi duhet të bëhet **vetëm në repository të GitHub Classroom**.



#### Workflow i plotë i dorëzimit

```bash
git clone REPOSITORY_URL
cd repository

# punoni mbi raportin

git status
git add .
git commit -m "Complete lab report"
git push
```





# 15. Struktura e Repository për Raportet Laboratorike

Për të mbajtur projektet të organizuara dhe të lexueshme, raportet laboratorike duhet të ndjekin një **strukturë të qartë të repository**.

Një strukturë e mirë e skedarëve e bën më të lehtë:

-   leximin e raportit
-   riprodhimin e analizës
-   vlerësimin nga instruktori
-   organizimin e të dhënave dhe figurave



# Struktura e rekomanduar

Repository duhet të ketë strukturën e mëposhtme:

```
raport-LAB-01/
│
├── raport.ipynb
│
├── data/
│   └── matjet.csv
│
├── figures/
│   ├── fig1.png
│   └── fig2.png
│
└── README.md
```



# Përshkrimi i dosjeve

### raport.ipynb

Notebook kryesor që përmban:

-   përshkrimin e eksperimentit
-   analizën e të dhënave
-   grafiqet
-   përfundimet

Ky është **dokumenti kryesor i raportit**.



### data/

Folderi për të dhënat eksperimentale.

Shembuj:

```
data/
matjet.csv
temperature_data.csv
raw_measurements.txt
```

Të dhënat duhet të jenë:

-   të organizuara
-   të lexueshme
-   në formate standarde (CSV, TXT)



### figures/

Folder për figurat dhe grafiqet.

Shembuj:

```
figures/
foto_setup.jpg
diagrama_eksperimentit.png
grafik_rezultatesh.png
```

Grafiqet mund të:

-   gjenerohen nga notebook

-   ose mund të jenë të ruajtura si file

    

### README.md

Një përshkrim i shkurtër i projektit.

Shembull minimal:

```
# Raport LAB 01

Eksperiment: Matjet dhe Gabimet

Ky repository përmban raportin laboratorik dhe analizën e të dhënave.

Student: Emri Mbiemri
Kursi: Hyrje ne Laborator - Fizikë dhe Shkenca Kompjuterike

```



# Çfarë nuk duhet të përfshihet

Mos përfshini në repository:

-   file të përkohshëm
-   file shumë të mëdhenj të panevojshëm
-   versione të shumta të njëjtit dokument

Shmangni struktura të çrregullta si:

```
final.ipynb
final2.ipynb
final_real.ipynb
new_final.ipynb
```

Përdorni vetëm:

```
raport.ipynb
```



# Praktika e mirë për Notebook

Para dorëzimit:

1.  Ekzekutoni të gjitha qelizat
2.  Sigurohuni që grafiqet shfaqen
3.  Ruani notebook

Në Jupyter beni `Run ALL` dhe pastaj `Save`:

```
Kernel → Restart & Run All
File → Save
```

Pastaj bëni commit dhe push ashtu sic e sqaruam me lart.



# Workflow përfundimtar për dorëzim

```bash
git status
git add .
git commit -m "Final version of lab report"
git push
```



>   ### Parimi kryesor
>
>   **Repository duhet të jetë i organizuar në mënyrë që një person tjetër, të mund të kuptojë dhe riprodhojë analizën tuaj.**

