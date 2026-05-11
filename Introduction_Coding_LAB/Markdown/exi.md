# Electronics — Midterm Exam

**Duration:** 60 minutes
**Total:** 20 points
**Topics:** DC circuits, AC circuits, diodes, basic transistor concepts
**Allowed:** calculator



### Problem 1 — DC voltage divider and loading

**5 points**

A voltage divider has a voltage source with $V_s = 12\ \text{V}$, and two resistors $R_1 = 2.2\ \text{k}\Omega$ and $R_2 = 4.7\ \text{k}\Omega$ connected in series. Positive side of the voltage source is connected to $R_1$ then to $R_2$ and then to the ground. The output voltage $V_{\rm out}$ is measured across $R_2$.

A load resistor $R_L = 10\ \text{k}\Omega$ is then connected in parallel with $R_2$.

##### Questions

*   **a) Unloaded output voltage (1 point):** Find $V_{\rm out}$ before the load resistor is connected.
*   **b) Loaded output voltage (2 points):** Find $V_{out}$ after $R_L$ is connected.
*   **c) Physical interpretation (1 point):** Does the load resistor increase or decrease $V_{\rm out}$? Explain physically.
*   **d) Power in $R_1$ (1 point):** Calculate the power dissipated in $R_1$ in the loaded case.



### Problem 2 — RC filter and frequency response

**5 points**

A sinusoidal input voltage is applied to a series RC circuit. The output voltage is taken across the capacitor. 

Given $R = 1.0\ \text{k}\Omega$, $C = 100\ \text{nF}$ and the input amplitude is $V_{\rm in} = 2.0\ \text{V}$.

##### Questions

*   **a) Transfer function (1.5 points):** Derive the transfer function: $H(j\omega)=\frac{V_{\rm out}}{V_{\rm in}}$.
*   **b) Filter type (1 point):** Is the circuit a low-pass or high-pass filter? Explain using the behavior of the capacitor at low and high frequency.
*   **c) Cutoff frequency (1 point):** Calculate the cutoff frequency $f_c$.
*   **d) Output amplitude at cutoff (1 point):** Find the output amplitude when $f=f_c$.
*   **e) Sketch (0.5 points):** Sketch qualitatively the magnitude response $|H(j\omega)|$ as a function of frequency.



### Problem 3 — Diode limiter circuit

**6 points**

A DC input voltage $V_{\rm in}$ is connected through a resistor $R$ to a node $V_{\rm out}$. From $V_{\rm out}$ to ground there is a silicon diode. The diode is oriented so that it conducts when $V_{\rm out}$ becomes positive. 

Use the constant-voltage diode model $V_t = 0.7\ \text{V}$ and the resistor value $R = 1.0\ \text{k}\Omega$.

```asciiarmor
Vin o---/\/\/\---o Vout
          R      |
                 v D
                 |
               ground
```

##### Questions

*   **a) Small positive input (1 point):** For $V_{\rm in} = 0.4\ \text{V}$, determine whether the diode is ON or OFF. Find $V_{\rm out}$ and $I_D$.
*   **b) Larger positive input (1.5 points):** For $V_{\rm in} = 5\,\text{V}$, determine whether the diode is ON or OFF. Find $V_{\rm out}$ and $I_D$.
*   **c) Negative input (1 point):** For $V_{\rm in} = -3.0 \ \text{V}$, determine whether the diode is ON or OFF. Find $V_{\rm out}$ and $I_D$.
*   **d) Transfer characteristic (1.5 points):** Sketch the approximate transfer characteristic $V_{\rm out}$ versus $V_{\rm in}$ for $-5\ \text{V} \leq V_{in} \leq 5\ \text{V}$. Indicate clearly the OFF region and the ON region of the diode.
*   **e) Sinusoidal input (1 point):** If $V_{\rm in} = 5\, \sin(\omega \,t) \ \text{V}$, describe qualitatively the output waveform. What happens to the positive part of the signal?



### Problem 4 — Theory and practical design

**4 points**

##### 4.1 Basic BJT transistor concepts (**2 points**)

Answer briefly.

*   **a) A BJT has three terminals (0.75 points):** base, collector, and emitter. What is the role of the base in controlling the transistor?
*   **b) (0.75 points):** In an NPN transistor used as a switch, what does it roughly mean for the transistor to be OFF and ON? No calculations required!
*   **c) (0.5 points):** Why can a transistor be useful in electronics even if the input signal or control current is small?

##### 4.2 Practical resistor design (**2 points**)

You have access to many real resistors with the following values, namely: $100\, \Omega$, $220\, \Omega$, $330\, \Omega$.  Each resistor has a maximum power rating of $1/4\ \text{W} = 0.25\ \text{W}$.  Design an equivalent resistor with $R_{\rm eq} = 110\, \Omega$ and power rating at least $0.5\ \text{W}$.

##### Questions

*   **a) (1 point):** Show how to combine the resistors to obtain $R_{eq}=110\ \Omega$.
*   **b) (0.5 points):** Explain why the equivalent resistance is $110\ \Omega$.
*   **c) (0.5 points):** Explain why the power rating is at least $0.5\ \text{W}$.



---

### Marking scheme summary

| Problem                           | Points |
| --------------------------------- | -----: |
| Problem 1: DC divider and loading |      5 |
| Problem 2: RC filter              |      5 |
| Problem 3: Diode limiter          |      6 |
| Problem 4: Theory and design      |      4 |
| **Total**                         | **20** |

