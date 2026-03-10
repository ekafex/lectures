# Menaxhimi i Mjediseve me Conda (Miniconda)



## 1. Çfarë është Conda?

**Conda** është një **menaxhues librarishe dhe mjedisesh (environment manager)**.

Ai ju lejon të:

-   instaloni librari shkencore Python (NumPy, SciPy, etj.)
-   krijoni **mjedise të izoluara** me versione specifike software
-   shmangni konfliktet midis projekteve të ndryshme

Një **environment** është një **hapësirë pune e pavarur** që përmban:

-   versionin e vet të Python
-   libraritë
-   varësitë (dependencies)

Kjo do të thotë që projekte të ndryshme mund të përdorin **versione të ndryshme të të njëjtave librari**, pa u konfliktuar me njëra-tjetrën.



# 2. Pse përdorim mjedise (environments)?

Pa përdorur environments:

```
Python i sistemit
 ├── numpy (v1.20)
 ├── scipy (v1.7)
 ├── pandas (v1.4)
```

Nëse një projekt kërkon versione të tjera, instalimi i tyre mund të **prishë projekte të tjera**.

Me Conda environments:

```
env_lab
 ├── numpy
 ├── scipy
 ├── pandas

env_ml
 ├── tensorflow
 ├── pytorch
```

Çdo projekt mbetet **i pastër dhe i riprodhueshëm (reproducible)**.

Kjo është shumë e rëndësishme në:

-   **shkencë**
-   **shkencat kompjuterike**
-   **analizë të dhënash**
-   **punë laboratorike**



# 3. Instalimi i Miniconda

**Miniconda** është një shpërndarje (distribution) minimale e Conda (rekomandohet për fillestarët).

Faqja zyrtare e shkarkimit:

https://docs.conda.io/en/latest/miniconda.html

Zgjidhni instaluesin për sistemin tuaj operativ:

-   Linux
-   macOS
-   Windows



### Shembull instalimi në Linux

Shkarkoni instaluesin:

```bash
wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh
```

Ekzekutoni instalimin:

```bash
bash Miniconda3-latest-Linux-x86_64.sh
```

Ndiqni udhëzimet në terminal.

Pas instalimit **restart terminalin**.

Kontrolloni instalimin:

```bash
conda --version
```



# 4. Koncepte bazë të Conda

### Krijimi i një environment

Shembull: krijojmë një environment të quajtur `lab`

```bash
conda create -n lab python=3.11
```



### Aktivizimi i environment

```bash
conda activate lab
```

Terminali do të tregojë:

```bash
(lab) $
```

Kjo do të thotë që environment është aktiv.



### Çaktivizimi i environment

```bash
conda deactivate
```



# 5. Instalimi i paketave shkencore Python

Pasi environment është aktiv:

```bash
conda activate lab
```

Instaloni paketat:

```bash
conda install numpy scipy pandas matplotlib jupyterlab
```

Conda do të instalojë automatikisht të gjitha varësitë e nevojshme.



# 6. Nisja e JupyterLab

Brenda environment:

```bash
$ conda activate lab
$ jupyter-lab
```

Kjo do të hapë **JupyterLab në default browser**.

Tani mund të krijoni **notebook (.ipynb)** dhe të ekzekutoni kod Python në mënyrë interaktive.



# 7. Workflow tipik

Një workflow minimal për një projekt shkencor:

### 1. Krijoni environment

```bash
conda create -n physics-lab python=3.11
```

### 2. Aktivizoni environment

```bash
conda activate physics-lab
```

### 3. Instaloni paketat

```bash
conda install numpy scipy pandas matplotlib jupyterlab
```

### 4. Nisni JupyterLab

```bash
jupyter-lab
```

### 5. Punoni me notebook

Krijoni skedarë si p.sh.:

```
analysis.ipynb
experiment_report.ipynb
```



# 8. Komanda të dobishme Conda

Lista e environments:

```bash
conda env list
```

Lista e paketave të instaluara:

```bash
conda list
```

Fshirja e një environment:

```bash
conda remove -n lab --all
```

Përditësimi:

```bash
conda update --all
```

Pastrimi:

```bash
conda clean --all
```



# 9. Environment i rekomanduar për këtë kurs

Për analizë të dhënash laboratorike zakonisht do të përdorim:

```bash
conda create -n intro-lab python=3.11 numpy scipy pandas matplotlib jupyterlab
```

Aktivizimi:

```bash
conda activate intro-lab
```

Nisja e JupyterLab:

```bash
jupyter lab
```



# 10. Përmbledhje

Conda ofron:

-   **menaxhim paketash**
-   **izolim të mjediseve**
-   **workflow të riprodhueshëm shkencor**

Përdorimi tipik:

```
krijo environment
aktivizo environment
instalo paketat (librarite)
nis jupyter lab
```

Ky workflow përdoret gjerësisht në:

-   **shkencë**
-   **shkencat kompjuterike**
-   **kërkim shkencor**
-   **analizë të dhënash**

