# Markdown për Raporte Shkencore

### Udhëzues i shkurtër për përdorim në Jupyter Notebook



## 1. Çfarë është Markdown?

**Markdown** është një gjuhë e thjeshtë për formatimin e tekstit që përdoret për të shkruar dokumente të strukturuara.

Në **Jupyter Notebook**, qelizat Markdown përdoren për:

-   përshkrimin e eksperimentit
-   shpjegimin e teorisë
-   interpretimin e rezultateve
-   shkrimin e formulave matematikore

Markdown është shumë i thjeshtë sepse përdor vetëm disa **simbolë bazë** për të strukturuar tekstin.



# 2. Titujt (Headings)

Titujt krijohen me simbolin `#`.

| Sintaksa         | Rezultati      |
| ---------------- | -------------- |
| `# Titull`       | Titull kryesor |
| `## Seksion`     | Seksion        |
| `### Nënseksion` | Nënseksion     |

Shembull:

```markdown
# Eksperimenti i Rënies së Lirë

## Objektivi

## Teoria

## Metoda
```



# 3. Formatimi i Tekstit

Markdown lejon formatim bazë të tekstit.

| Sintaksa    | Rezultati          |
| ----------- | ------------------ |
| `**tekst**` | **tekst i trashë** |
| `*tekst*`   | *tekst italic*     |
| ``kod``     | `kod`              |

Shembull:

```markdown
Ky eksperiment mat **përshpejtimin gravitacional**.

Ky është një *parametër fizik i rëndësishëm*.
```



# 4. Listat

### Lista me pika

```markdown
- Matjet
- Analiza
- Përfundimi
```

Rezultati:

-   Matjet
-   Analiza
-   Përfundimi



### Lista e numëruar

```markdown
1. Përgatitja e eksperimentit
2. Kryerja e matjeve
3. Analiza e të dhënave
```

Rezultati:

1.  Përgatitja e eksperimentit
2.  Kryerja e matjeve
3.  Analiza e të dhënave



# 5. Shkrimi i Formulave Matematikore

Markdown në Jupyter mbështet **LaTeX** për formulat matematikore.

### Formula brenda tekstit

```markdown
Ligji i dytë i Njutonit është $F = ma$.
```



### Formula në rresht të veçantë

```markdown
$$
F = ma
$$
```

Shembull tjetër:

```markdown
$$
x(t) = x_0 + v_0 t + \frac{1}{2} a t^2
$$
```



# 6. Futja e Figurave

Në Markdown mund të futen figura.

Sintaksa:

```markdown
![përshkrimi](figura.png)
```

Shembull:

```markdown
![Pendulum Experiment](pendulum.png)
```



# 7. Futja e Links të klikueshëm

```markdown
[Emri i lidhjes](https://example.com)
```

Shembull:

```markdown
Dokumentacioni i Python mund të gjendet këtu:

https://python.org
```

ose

```markdown
[Python Official Website](https://python.org)
```



# 8. Shembull i një Seksioni në Raport

```markdown
## Teoria

Në këtë eksperiment analizojmë lëvizjen e trupit në rënie të lirë.

Ekuacioni i lëvizjes është:

$$
x(t) = x_0 + v_0 t + \frac{1}{2} g t^2
$$

ku:

- $x_0$ është pozicioni fillestar
- $v_0$ është shpejtësia fillestare
- $g$ është përshpejtimi gravitacional
```



# 9. Struktura e një Raporti Laboratori

Një notebook duhet të ketë strukturën e një raporti shkencor.

Shembull:

```markdown
# Titulli i Eksperimentit

## Objektivi

Qëllimi i eksperimentit.

## Teoria

Ligjet dhe formulat përkatëse.

## Metoda

Përshkrimi i aparaturës dhe matjeve.

## Analiza e të Dhënave

Kodi Python për analizë.

## Rezultatet

Grafikët dhe rezultatet numerike.

## Përfundimi

Interpretimi i rezultateve.
```



# 10. Burime të Dobishme

### Markdown Cheat Sheet

Për sintaksën e plotë të Markdown:

https://www.markdownguide.org/cheat-sheet/



### Scientific Python Cheat Sheet

Për përdorimin e Python në analizë shkencore:

https://ipgp.github.io/scientific_python_cheat_sheet/



# Praktika të Mira për Studentët

Kur shkruani një notebook laboratorik:

✔ përdorni **tituj të qartë**
✔ shpjegoni **çfarë bëni dhe pse**
✔ shkruani **formulat në LaTeX**
✔ interpretimi i rezultateve është **po aq i rëndësishëm sa kodi**

