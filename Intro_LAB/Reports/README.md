# Hyrje në Laborator

## Udhëzues për konfigurimin, strukturën dhe vlerësimin e raporteve laboratorike



## 1. Konfigurimi

### 1.1 Krijimi i repository

Në GitHub duhet të krijoni një repository me emrin **saktësisht**:

```
Hyrje_Laborator
```

❗ Nuk lejohet asnjë variacion i emrit.

Ndiqni udhëzimin:
https://docs.github.com/en/repositories/creating-and-managing-repositories/quickstart-for-repositories

>   ⚠️ **Kujdes:** Repositories kontrollohen automatikisht nga një script që pret emrin `Hyrje_Laborator`. Nëse emri nuk përputhet, sistemi e konsideron raportin si **të padërguar**.



### 1.2 Instalimi i Git

Instaloni Git nga:
https://git-scm.com/downloads

Verifikoni instalimin:

```bash
git --version
```

Konfigurimi minimal:

```bash
git config --global user.name "username"
git config --global user.email "email@example.com"
```

vendosni të dhënat e Github-it tuaj.



### 1.3 Klonimi i repository

Klononi repository në kompjuterin tuaj:

```bash
git clone <repository-link>
cd Hyrje_Laborator
```

Ky do të jetë folderi kryesor ku do të punoni dhe nga ku do të bëni `push`.

#### Metodat e klonimit

-   HTTPS:

```
https://github.com/user/Hyrje_Laborator.git
```

-   SSH:

```
git@github.com:user/Hyrje_Laborator.git
```

🔹 Rekomandohet përdorimi i HTTPS për fillestarët.

Dokumentacion:
https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository



### 1.4 Medota e "Authentication"

-   **HTTPS** → përdorni kredencialet tuaja (username + token/password)
-   **SSH** → konfiguroni sipas:
    https://docs.github.com/en/authentication/connecting-to-github-with-ssh



### 1.5 Konfigurimi i `.gitignore`

File `.gitignore` përdoret për të përjashtuar file dhe folder të panevojshëm nga repository.

Krijoni file psh:

```bash
touch .gitignore
```

Kopjoni brënda tij:

```gitignore
# Jupyter Notebook
.ipynb_checkpoints/

# Python
__pycache__/
*.py[cod]

# Jupyter runtime
.jupyter/
.virtual_documents/

# Virtual environments
.venv/
venv/
env/

# OS
.DS_Store
Thumbs.db
```



### 1.6 Workflow bazë me Git

Pas përfundimit të punës:

```bash
git add .
git commit -m "LABXX"
git push origin main
```

❗ Para `push`:

-   Ekzekutoni të gjitha qelizat në notebook
-   Kontrolloni që çdo gjë funksionon

Në Jupyter:
**Kernel → Restart & Run All**



## 2. Struktura e repository

```text
Hyrje_Laborator/
├── LAB01/
├── LAB02/
├── LAB03/
├── ...
├── .gitignore
├── README.md
```

Çdo laborator duhet të jetë në një folder të veçantë me numër sipas javës përkatëse, si psh java parë `LAB01`, java e dytë `LAB02` etj.



## 3. Struktura e çdo laboratori

```text
LABXX/
├── Raport.ipynb
├── data/
├── figs/
```

### Rregulla strikte:

-   Emri i folderit:

```
LAB01, LAB02, LAB03, ...
```

-   Emri i raportit:

```
Raport.ipynb
```

❌ Nuk lejohen variante si:

```
Raporti_Lab1.ipynb
Raport (1).ipynb
Lab01.ipynb
etj...
```

>   ⚠️ **Mosrespektimi i emërtimit → penalizim automatik**



### Organizimi i përmbajtjes

-   `data/` → të dhënat bruto nga matjet
-   `figs/` → figura dhe grafikë
-   `Raport.ipynb` → analiza dhe dokumentimi



## 4. Vlerësimi

| Kriteri          | Përshkrimi                           |
| ---------------- | ------------------------------------ |
| Strukturë (20%)  | Organizimi dhe respektimi i formatit |
| Qartësia (20%)   | Dokumentim i qartë dhe i lexueshëm   |
| Të dhënat (20%)  | Të dhëna të plota dhe të sakta       |
| Analiza (25%)    | Përpunim dhe interpretim korrekt     |
| Përfundime (15%) | Kuptim fizik dhe reflektim           |



### Penalizime (strukturore)

-   Strukturë e gabuar → **-20%**
-   Emërtim i gabuar → **-10%**
-   Pa `commit/push` → **0 pikë**



## 5. Qëllimi i këtij sistemi

-   Organizim profesional i punës
-   Riprodhueshmëri e rezultateve
-   Praktikë reale me Git
-   Dokumentim teknik i standardizuar



## 6. Përfundim

Ky sistem nuk është vetëm për dorëzim raportesh, por një **praktikë profesionale pune**.

Respektimi i rregullave është **i detyrueshëm** dhe pjesë e vlerësimit.
