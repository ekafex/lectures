# 📘 Java 2 – Markdown dhe Struktura e Raportit Laboratorik



# 1. Qëllimi i Javës 2

Në këtë javë do të mësoni:

* Si të shkruani profesionalisht në Markdown
* Si të përdorni formula matematikore (LaTeX)
* Si të krijoni tabela
* Si të shtoni figura
* Si të strukturoni një raport laboratorik

Qëllimi është që notebook-u juaj të mos jetë vetëm kod, por një **dokument shkencor i plotë dhe i strukturuar**.

---

# 2. Çfarë është Markdown?

Markdown është një gjuhë e thjeshtë shënimi që përdoret për:

* Strukturimin e tekstit
* Titujt
* Lista
* Tabela
* Formula matematikore

Markdown përdoret në:

* Jupyter
* GitHub
* Dokumentacion teknik
* Artikuj shkencorë



# 3. Titujt

Struktura e titujve bëhet me simbolin `#`.

```markdown
# Titull Kryesor
## Nëntitull
### Seksion
#### Nënseksion
```

Shembull:

```markdown
# Laboratori 1
## Qëllimi
## Baza Teorike
```

Përdorni tituj për të strukturuar dokumentin logjikisht.



# 4. Teksti dhe Formatimi

### Tekst i theksuar

```markdown
**tekst i trashë**
*tekst i pjerrët*
```

Shembull:

**Kjo është e rëndësishme.**



### Lista

```markdown
- Elementi 1
- Elementi 2
- Elementi 3
```

Ose e numëruar:

```markdown
1. Hapi i parë
2. Hapi i dytë
3. Hapi i tretë
```



# 5. Formula Matematikore (LaTeX)

Jupyter mbështet shkrimin e formulave matematikore.



## Formula brenda rreshtit

```markdown
Energjia kinetike është $E_k = \frac{1}{2}mv^2$.
```

Rezultati:

Energjia kinetike është $E_k = \frac{1}{2}mv^2$.



## Formula në rresht të veçantë

```markdown
$$
V = \pi r^2 h
$$
```

Rezultati:

$$
V = \pi r^2 h
$$



## Shembull me pasiguri

```markdown
$$
\sigma_f^2 = \sum_i \left( \frac{\partial f}{\partial x_i} \sigma_{x_i} \right)^2
$$
```

$$
\sigma_f^2 = \sum_i \left( \frac{\partial f}{\partial x_i} \sigma_{x_i} \right)^2
$$



# 6. Tabelat

Tabela krijohen kështu:

```markdown
| Matja | Diametri (mm) |
|-------|--------------|
| 1     | 10.1         |
| 2     | 10.2         |
| 3     | 9.9          |
```

Rezultati:

| Matja | Diametri (mm) |
| ----- | ------------- |
| 1     | 10.1          |
| 2     | 10.2          |
| 3     | 9.9           |



# 7. Shtimi i Figurave

Në Jupyter mund të shtoni figura:

```markdown
![Përshkrimi i figurës](emri_figurës.png)
```

Shembull:

```markdown
![Skema e eksperimentit](setup.png)
```

Figura duhet të shoqërohet gjithmonë me përshkrim.


# 8. Struktura Zyrtare e Raportit Laboratorik

Nga kjo javë, çdo raport do të ndjekë këtë strukturë:



## 1. Titulli

Emri i eksperimentit
Emri i studentit
Data



## 2. Qëllimi

Një paragraf i shkurtër që shpjegon:

* Çfarë po matet?
* Çfarë po verifikohet?



## 3. Baza Teorike

* Përkufizimi fizik
* Formula përkatëse
* Shpjegimi i madhësive fizike
* Njësitë

Formulat duhet të shkruhen në LaTeX.



## 4. Aparatura dhe Procedura

* Lista e instrumenteve
* Përshkrimi i procedurës
* Skema (nëse është e nevojshme)



## 5. Të Dhënat Bruto

* Tabelë me matjet
* Njësitë të deklaruara qartë

Asnjë analizë në këtë seksion.



## 6. Analiza e të Dhënave

* Llogaritja e mesatares
* Devijimi standard
* Grafiqe
* Përllogaritje të madhësive të derivuara



## 7. Analiza e Pasigurisë

* Pasiguria instrumentale
* Pasiguria statistikore
* Propagimi i pasigurisë



## 8. Diskutimi

* A përputhet rezultati me vlerën teorike?
* Cili është burimi kryesor i gabimit?
* A ka gabime sistematike?



## 9. Përfundimi

Një përmbledhje e qartë dhe koncize e rezultatit.



# 9. Gabimet e Zakonshme që Duhet të Shmangen

* Mungesa e njësive
* Figura pa etiketa
* Formula pa shpjegim
* Tabela pa titull
* Përfundime pa analizë

Raporti laboratorik nuk është përshkrim narrativ, por analizë shkencore.



# 10. Detyrë për Javën 2

Krijoni një notebook me titull:

```
Lab_01_Structure.ipynb
```

Notebook-u duhet të përmbajë:

* Një strukturë të plotë raporti (pa të dhëna reale)
* Të paktën:

  * 2 formula
  * 1 tabelë
  * 1 figurë (mund të jetë ilustrative)
  * Strukturë të plotë seksionesh

Qëllimi është të praktikoni strukturën dhe Markdown-in.



# Qëllimi Pedagogjik i Javës 2

Kjo javë vendos:

* Disiplinën e dokumentimit
* Strukturën e mendimit shkencor
* Standardin profesional të raportimit

Nga Java 3, do të fillojmë analizën numerike me NumPy dhe grafikë me Matplotlib.
