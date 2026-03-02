# 📘 Java 1 – Konfigurimi i Mjedisit Shkencor të Punës


# 1. Pse do të përdorim JupyterLab?

Në këtë lëndë, fletorja juaj laboratorike do të jetë **digjitale dhe e ekzekutueshme**.

Do të përdorim:

* **Python** → për llogaritje shkencore
* **NumPy / Matplotlib** → për analizë numerike dhe grafikë
* **JupyterLab** → si fletore laboratorike interaktive

Një notebook Jupyter ju lejon të:

* Shkruani tekst shpjegues (Markdown)
* Shkruani formula matematikore (LaTeX)
* Ekzekutoni kod
* Gjeneroni grafikë
* Ruani analizën në mënyrë të riprodhueshme

Nga ky moment:

> Të gjitha raportet laboratorike do të dorëzohen në format `.ipynb`.



# 2. Instalimi i Mjedisit Shkencor

Do të përdorim **Miniconda** për menaxhimin e mjediseve Python.

### Pse Miniconda?

* Izolon varësitë (dependencies)
* Nuk ndërhyn me Python-in e sistemit
* Siguron riprodhueshmëri
* Funksionon në Linux, macOS dhe Windows



## Hapi 1 — Instalimi i Miniconda

Shkarkoni Miniconda nga:

[https://docs.conda.io/en/latest/miniconda.html](https://docs.conda.io/en/latest/miniconda.html)

Zgjidhni versionin për sistemin tuaj:

* Windows (64-bit)
* macOS
* Linux

Instaloni me opsionet standarde (default).



# 3. Krijimi i Mjedisit të Laboratorit

Pas instalimit:



## 🟢 Në Linux / macOS

Hapni **Terminalin** dhe shkruani:

```bash
conda create -n physlab python=3.11
conda activate physlab
conda install jupyterlab numpy matplotlib
```

Pastaj nisni JupyterLab:

```bash
jupyter lab
```



## 🟢 Në Windows

Hapni **Anaconda Prompt** (instalohet bashkë me Miniconda).

Shkruani:

```bash
conda create -n physlab python=3.11
conda activate physlab
conda install jupyterlab numpy matplotlib
```

Pastaj:

```bash
jupyter lab
```

Do të hapet automatikisht një dritare në shfletues (browser).

---

# 4. Rregull i Rëndësishëm për Mjediset

Çdo herë që punoni për këtë lëndë:

### Në Linux / macOS:

```bash
conda activate physlab
jupyter lab
```

### Në Windows:

Hapni Anaconda Prompt:

```bash
conda activate physlab
jupyter lab
```

Mos instaloni paketa në mjedisin `base`.



# 5. Çfarë është JupyterLab?

JupyterLab është një mjedis interaktiv për punë me notebook.

Një notebook përbëhet nga **qeliza (cells)**:

* Qeliza Markdown → tekst dhe formula
* Qeliza Code → kod Python
* Qeliza Output → rezultate dhe grafikë



# 6. Krijimi i Notebook-ut të Parë

1. Klikoni **File → New → Notebook**
2. Zgjidhni kernel-in **Python 3 (physlab)**
3. Riemërtoni skedarin:

   ```
   Lab_00_Hyrje.ipynb
   ```



# 7. Llojet e Qelizave

Në shiritin e sipërm (toolbar) mund të zgjidhni:

* Code
* Markdown



## Ekzekutimi i një Qelize

Shtypni:

```
Shift + Enter
```



# 8. Qeliza juaj e Parë e Kodit

Shkruani në një qelizë Code:

```python
a = 5
b = 3
a + b
```

Shtypni **Shift + Enter**.

Ju sapo ekzekutuat kod Python.



# 9. Rinisja e Kernel-it

Nëse diçka nuk funksionon:

Menu → **Kernel → Restart Kernel**

Pastaj:
Run → **Run All Cells**

Kuptimi i këtij mekanizmi shmang shumicën e problemeve fillestare.



# 10. Struktura e një Notebook-u Shkencor

Nga tani e tutje, çdo raport laboratorik duhet të ndjekë këtë strukturë:

1. Titulli
2. Qëllimi
3. Baza teorike
4. Aparatura dhe procedura eksperimentale
5. Të dhënat bruto
6. Analiza e të dhënave
7. Analiza e pasigurisë
8. Diskutimi
9. Përfundimi

Këtë strukturë do ta ndërtojmë gradualisht gjatë javëve në vijim.



# 11. Çfarë duhet të keni arritur para Javës 2

* Miniconda të instaluar
* Mjedisin `physlab` të krijuar
* JupyterLab funksional
* Aftësi për të krijuar dhe ekzekutuar një notebook



# 12. Zgjidhja e Problemeve të Zakonshme

Nëse komanda `conda` nuk njihet:

* Rinisni terminalin
* Në Windows përdorni gjithmonë **Anaconda Prompt**
* Në Linux/macOS sigurohuni që Miniconda është shtuar në PATH gjatë instalimit

Nëse JupyterLab nuk hapet automatikisht:

* Kopjoni adresën (URL) që shfaqet në terminal
* Paste në browser manualisht



# 13. Detyrë për Javën 1

1. Krijoni një notebook me emrin:

   ```
   Lab_00_Test.ipynb
   ```

2. Shtoni:

   * Një titull në Markdown
   * Një qelizë Python që llogarit një shprehje të thjeshtë

3. Ekzekutoni të gjitha qelizat me sukses.

Notebook-un silleni në javën e ardhshme.



# Shënim

Java 1 ka për qëllim:

* Eliminimin e pasigurisë teknike
* Standardizimin e mjedisit të punës
* Krijimin e disiplinës së punës
* Vendosjen e kulturës së laboratorit digjital

Java 2 do të fokusohet në:

* Markdown të avancuar
* Shkrimin e formulave
* Strukturimin profesional të raportit
