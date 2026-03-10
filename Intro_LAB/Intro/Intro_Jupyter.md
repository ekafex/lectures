

# Hyrje e Shkurtër në Jupyter Notebook

### Për Analizë Shkencore dhe Raporte Laboratorike



## 1. Çfarë është Jupyter Notebook?

**Jupyter Notebook** është një mjedis interaktiv që lejon të kombinohen në një dokument të vetëm:

-   **Tekst dhe dokumentim**
-   **Formula matematikore**
-   **Kod Python**
-   **Figura dhe grafikë**
-   **Rezultate llogaritjesh**

Një notebook përbëhet nga **qeliza (cells)** që mund të ekzekutohen në mënyrë të pavarur.

Dy llojet kryesore të qelizave janë:

| Lloji i qelizës   | Qëllimi                                      |
| ----------------- | -------------------------------------------- |
| **Markdown**      | Shkrimi i tekstit, shpjegimeve dhe formulave |
| **Code (Python)** | Ekzekutimi i kodit Python                    |

Kjo e bën Jupyter shumë të përshtatshëm për **punë shkencore dhe raporte laboratorike**, sepse në të njëjtin dokument mund të shpjegojmë metodën dhe të tregojmë analizën.



# 2. Struktura Tipike e një Notebook

Një notebook zakonisht organizohet si **një raport shkencor**.

Strukturë tipike:

```
Titulli i Eksperimentit
Objektivi
Teoria
Metoda / Eksperimenti
Analiza e të dhënave (Python)
Rezultatet
Përfundimi
```

Teksti shkruhet në **Markdown**, ndërsa analiza kryhet me **qeliza Python**.



# 3. Qelizat Markdown (Dokumentimi)

Markdown përdoret për të shkruar **tekst shpjegues**.

Për të krijuar një qelizë Markdown:

```
Cell → Markdown
```

Pastaj ekzekuto:

```
Shift + Enter
```



## Shembull

Markdown:

```markdown
# Eksperimenti i Rënies së Lirë

## Objektivi

Matja e përshpejtimit gravitacional duke përdorur të dhëna eksperimentale.
```

Rezultati:

# Eksperimenti i Rënies së Lirë

## Objektivi

Matja e përshpejtimit gravitacional duke përdorur të dhëna eksperimentale.



# 4. Sintaksa Bazë e Markdown

| Sintaksa     | Rezultati          |
| ------------ | ------------------ |
| `# Titull`   | Titull kryesor     |
| `## Seksion` | Seksion            |
| `**tekst**`  | **tekst i trashë** |
| `*tekst*`    | *tekst italic*     |
| `- element`  | listë              |

Shembull:

```
- Matjet
- Analiza e të dhënave
- Përfundimi
```



# 5. Shkrimi i Formulave Matematikore

Jupyter mbështet **LaTeX për formulat matematikore**.

Formula brenda tekstit:

```
$F = ma$
```

Formula në rresht të veçantë:

```
$$
F = ma
$$
```

Shembull:

```markdown
$$ x(t)=x_0 + v_0 t + \frac{1}{2} a t^2 $$
```


$$
x(t) = x_0 + v_0 t + \frac{1}{2} a t^2
$$


# 6. Qelizat e Kodit (Python)

Qelizat e kodit përdoren për të ekzekutuar **Python**.

Ekzekutimi i qelizës bëhet me:

```
Shift + Enter
```

Shembull:

```python
print("Hello world")
```



# 7. Shembull Analize të Thjeshtë

```python
import numpy as np
import matplotlib.pyplot as plt

time = np.array([0,1,2,3,4])
position = np.array([0,5,20,45,80])

plt.plot(time, position, 'o-')
plt.xlabel("Time (s)")
plt.ylabel("Position (m)")
plt.title("Motion Experiment")
plt.grid()
plt.show()
```

Rezultati shfaqet **direkt brenda notebook-ut**.



# 8. Workflow Tipik në Jupyter

Në një raport laboratorik duhet të ndiqet kjo logjikë:

1.  Shkruhet **përshkrimi i eksperimentit** në Markdown
2.  Ngarkohen **të dhënat në Python**
3.  Kryhet **analiza**
4.  Paraqiten **grafikët**
5.  Diskutohen **rezultatet**

Shembull:

```
Markdown: përshkrimi i eksperimentit
Code: ngarkimi i të dhënave
Code: analiza
Code: grafikët
Markdown: diskutimi i rezultateve
```

Ky proces garanton **riprodhueshmëri shkencore**.



# 9. "Shortcuts" Kryesore të Tastierës

| Shortcut          | Veprimi               |
| ----------------- | --------------------- |
| **Shift + Enter** | Ekzekuton qelizën     |
| **Esc + A**       | Qelizë e re sipër     |
| **Esc + B**       | Qelizë e re poshtë    |
| **Esc + M**       | Konverton në Markdown |
| **Esc + Y**       | Konverton në Code     |



# 10. Ruajtja dhe Eksportimi

Notebook ruhen si:

```
filename.ipynb
```

Mund të eksportohen në:

-   HTML
-   PDF
-   Markdown
-   Python script

Shembull:

```
File → Download as → HTML
```



# 11. Praktika të Mira për Raporte Laboratori

Studentët duhet:

✔ të shkruajnë **shpjegime të qarta në Markdown**
✔ të komentojnë **kodin Python**
✔ të etiketojnë **boshtet e grafikëve**
✔ të interpretojnë **rezultatet**

Shembull i mirë:

```python
plt.plot(time, position)
plt.xlabel("Koha (s)")
plt.ylabel("Pozicioni (m)")
plt.title("Matja e Levizjes")
```



# Struktura Minimale e një Raporti Laboratori

```
# Titulli i Eksperimentit

## Objektivi

Qëllimi i eksperimentit.

## Teoria

Ligjet dhe formulat përkatëse.

## Metoda

Përshkrimi i matjeve dhe instrumenteve.

## Analiza e të Dhënave

Kodi Python i përdorur për analizë.

## Rezultatet

Grafikët dhe rezultatet numerike.

## Përfundimi

Interpretimi i rezultateve.
```



# Burime të Dobishme

### Markdown Cheat Sheet

Dokument i shkurtër për sintaksën e Markdown:

https://www.markdownguide.org/cheat-sheet/



### Scientific Python Cheat Sheet

Për përdorimin e bibliotekave shkencore:

-   NumPy
-   Matplotlib
-   SciPy

https://ipgp.github.io/scientific_python_cheat_sheet/

