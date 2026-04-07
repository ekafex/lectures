# **LAB 06 — Matje Indirekte: Dendësia dhe Përhapja e Pasigurisë**

## **Qëllimi i Laboratorit**

Ky laborator synon që studenti të kuptojë se shumë madhësi fizike **nuk maten drejtpërdrejt**, por llogariten nga madhësi të tjera të matura. Shembulli kryesor në këtë laborator është **dendësia**.

Objektivat janë:

* Të matet **masa** dhe **përmasat gjeometrike**
* Të llogaritet **vëllimi**
* Të përcaktohet **dendësia**
* Të kuptohet dhe zbatohet **përhapja e pasigurisë**
* Të vlerësohet se cila matje dominon pasigurinë finale



---



## **Hyrje Teorike**

### 1. Matja direkte dhe indirekte

* **Matje direkte**: madhësia lexohet direkt nga instrumenti
  p.sh. masa me peshore, gjatësia me kaliper

* **Matje indirekte**: madhësia llogaritet nga madhësi të tjera të matura
  p.sh. dendësia:
  $$ \rho = \frac{m}{V} $$

Pra, dendësia nuk lexohet direkt; ajo del nga matja e **masës** dhe **vëllimit**.



### 2. Dendësia

Dendësia përkufizohet si masa për njësi vëllimi:

$$ \rho = \frac{m}{V} $$

Njësia SI është:

$$ [\rho] = \mathrm{kg/m^3} $$

Në laborator shpesh përdoret edhe:

$$ \mathrm{g/cm^3} $$



### 3. Pse nevojitet përhapja e pasigurisë?

Nëse (m) dhe (V) kanë pasiguri, atëherë edhe (\rho) do të ketë pasiguri.
Pra nuk mjafton të japim vetëm vlerën e dendësisë; duhet të japim edhe **sa e sigurt është ajo vlerë**.



## **Pajisjet**

* Peshore
* Vizore, kaliper ose mikrometër
* Një ose disa objekte me formë të rregullt:

  * cilindër
  * kub
  * paralelepiped
  * sferë
* Fletore ose Jupyter Notebook për analizën

 

**Konceptet Kryesore**

### **Pasiguria absolute**

Nëse një madhësi matet si:
$$ x = x_0 \pm \Delta x $$
atëherë $\Delta x$ është pasiguria absolute.

### **Pasiguria relative**

$$ \frac{\Delta x}{x} $$

Shpesh shprehet në përqindje:
$$ \frac{\Delta x}{x}\times 100% $$



## **Modeli Fizik i Eksperimentit**

Studenti mat:

* masën (m)
* dimensionet lineare të objektit

Pastaj llogarit:

* vëllimin $V$
* dendësinë $\rho$



---



## **Raste Tipike për Vëllimin**

### **1. Paralelepiped drejtkëndor**

$$ V = abc $$
ku $a$, $b$, $c$ janë gjatësia, gjerësia dhe lartësia.

### **2. Kub**

$$ V = a^3 $$

### **3. Cilindër**

$$ V = \pi r^2 h $$

### **4. Sferë**

$$ V = \frac{4}{3}\pi r^3 $$



---



## **Përhapja e Pasigurisë**

Për një produkt ose herës, pasiguritë relative kombinohen afërsisht si shumë.

### **Shembull 1: Paralelepiped**

$$ V = abc $$

Atëherë:
$$ \frac{\Delta V}{V} \approx \frac{\Delta a}{a} + \frac{\Delta b}{b} + \frac{\Delta c}{c}$$

Dhe për dendësinë:
$$ \rho = \frac{m}{V} $$

pra:
$$ \frac{\Delta \rho}{\rho} \approx \frac{\Delta m}{m} + \frac{\Delta V}{V}  $$

### **Shembull 2: Cilindër**

$$ V = \pi r^2 h $$

Atëherë:
$$ \frac{\Delta V}{V} \approx 2\frac{\Delta r}{r} + \frac{\Delta h}{h} $$

dhe:
$$ \frac{\Delta \rho}{\rho} \approx \frac{\Delta m}{m} + 2\frac{\Delta r}{r} + \frac{\Delta h}{h} $$

---



## **Procedura Eksperimentale**

### **Pjesa A — Matja e masës**

1. Mat masën e objektit të paktën **5 herë**.

2. Regjistro vlerat në tabelë.

3. Gjej mesataren:
   $$ \bar{m} = \frac{1}{N}\sum_i m_i $$
   
4. Vlerëso pasigurinë e masës:

* nga rezolucioni i peshorës
* ose nga shpërndarja e matjeve, nëse ajo është më e madhe



### **Pjesa B — Matja e përmasave**

1. Mat dimensionet gjeometrike të objektit:

   * (a,b,c) për paralelepiped
   * (r,h) për cilindër
2. Kryej disa matje për secilin dimension.
3. Regjistro vlerat dhe llogarit mesataret.



### **Pjesa C — Llogaritja e vëllimit**

Përdor formulën gjeometrike të përshtatshme për objektin.

### **Pjesa D — Llogaritja e dendësisë**

$$ \rho = \frac{m}{V} $$

### **Pjesa E — Përhapja e pasigurisë**

1. Llogarit pasiguritë relative të madhësive bazë
2. Gjej pasigurinë relative të $V$
3. Gjej pasigurinë relative të $\rho$
4. Ktheje në pasiguri absolute:
   $$ \Delta \rho = \rho \cdot \frac{\Delta \rho}{\rho} $$

Raporti final jepet si:
$$ \rho = (\rho_0 \pm \Delta \rho) $$



## **Tabela e të Dhënave**

### **Tabela 1 — Masa**

| Matja | (m) (g) |
| ----: | ------: |
|     1 |         |
|     2 |         |
|     3 |         |
|     4 |         |
|     5 |         |

### **Tabela 2 — Përmasat**

| Matja | (a) (cm) | (b) (cm) | (c) (cm) |
| ----: | -------: | -------: | -------: |
|     1 |          |          |          |
|     2 |          |          |          |
|     3 |          |          |          |

ose, për cilindrin:

| Matja | (r) (cm) | (h) (cm) |
| ----: | -------: | -------: |
|     1 |          |          |
|     2 |          |          |
|     3 |          |          |





## **Analiza e të Dhënave**

Studenti duhet të përfshijë:

* mesataret e madhësive të matura
* pasiguritë absolute
* vëllimin e llogaritur
* dendësinë e llogaritur
* përhapjen e pasigurisë
* rezultatin final me njësi dhe me numër të arsyeshëm shifrash domethënëse



## **Pyetje për Diskutim**

1. Cila madhësi kontribuon më shumë në pasigurinë finale të dendësisë?
2. A është më e rëndësishme të përmirësohet matja e masës apo e dimensioneve?
3. Si ndryshon pasiguria e vëllimit kur një dimension hyn me fuqi, si te (r^2) ose (r^3)?
4. A përputhet dendësia e matur me vlera tipike të materialeve të njohura?
5. A ka shenja të gabimeve sistematike?



## **Gabime të Zakonshme**

* Përdorimi i formulës së gabuar për vëllimin
* Harresa e njësive
* Raportimi i shumë shifrave që nuk justifikohen nga pasiguria
* Mosndarja e qartë midis pasigurisë absolute dhe relative
* Llogaritje e dendësisë pa analizë të pasigurisë



## **Rezultati Final**

Rezultati duhet shkruar në formën:

$$ \rho = (\rho_0 \pm \Delta \rho)\,\mathrm{g/cm^3} $$

ose në SI:

$$ \rho = (\rho_0 \pm \Delta \rho)\,\mathrm{kg/m^3} $$



## **Mesazhi Kryesor i Laboratorit**

Ky laborator duhet t’iu bëjë të kuptojnë një ide themelore:

> Në eksperiment, madhësitë e llogaritura nuk janë më të mira se matjet mbi të cilat mbështeten.

Pra, analiza e pasigurisë nuk është shtesë formale; ajo është pjesë e vetë kuptimit fizik të rezultatit.



## **Sugjerim për Jupyter Notebook**

Raporti mund të ketë këtë strukturë:

1. **Qëllimi**
2. **Teoria**
3. **Të dhënat eksperimentale**
4. **Llogaritja e mesatareve**
5. **Llogaritja e vëllimit**
6. **Llogaritja e dendësisë**
7. **Përhapja e pasigurisë**
8. **Diskutim**
9. **Përfundim**
