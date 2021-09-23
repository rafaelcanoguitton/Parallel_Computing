# Análisis programación paralela con MPI

## Introducción

En el presente informe se compara algoritmos implementados de manera secuencial y paralela empleando MIPS. Se hace una comparación de tiempos, *speedup* y eficiencia.

## Resultados

**Matrix - Vector Multiplication**

<table><thead><tr><th rowspan="2">N° de procesos</th><th colspan="5">Dimensiones de Matriz</th></tr><tr><th>1024</th><th>2048</th><th>4096</th><th>8192</th><th>16384</th></tr></thead><tbody><tr><td>1</td><td>0.003153</td><td>0.012754</td><td>0.049961</td><td>0.203809</td><td>0.813616</td></tr><tr><td>2</td><td>0.001974</td><td>0.006330</td><td>0.026936</td><td>0.104198</td><td>0.387516</td></tr><tr><td>4</td><td>0.001552</td><td>0.003372</td><td>0.013236</td><td>0.049211</td><td>0.230796</td></tr><tr><td>8</td><td>0.000554</td><td>0.002174</td><td>0.014557</td><td>0.034458</td><td>0.167254</td></tr><tr><td>16</td><td>0.000780</td><td>0.007270</td><td>0.022699</td><td>0.039639</td><td>0.426620</td></tr></tbody></table>

**Odd even sort**

<table><thead><tr><th rowspan="2">N° de procesos</th><th colspan="5">Número de elementos</th></tr><tr><th>200</th><th>400</th><th>800</th><th>1600</th><th>3200</th></tr></thead><tbody><tr><td>1</td><td>0.000079</td><td>0.000253</td><td>0.000949</td><td>0.003851</td><td>0.014282</td></tr><tr><td>2</td><td>0.000016</td><td>0.000022</td><td>0.000038</td><td>0.000075</td><td>0.000142</td></tr><tr><td>4</td><td>0.000035</td><td>0.000059</td><td>0.000075</td><td>0.000066</td><td>0.000121</td></tr><tr><td>8</td><td>0.000110</td><td>0.000154</td><td>0.000058</td><td>0.000090</td><td>0.000111</td></tr><tr><td>16</td><td>-</td><td>0.003741</td><td>0.000163</td><td>0.001750</td><td>0.004117</td></tr></tbody></table>

## Speedups

**Matrix - Vector Multiplication**

<table><thead><tr><th rowspan="2">N° de procesos</th><th colspan="5">Dimensiones de Matriz</th></tr><tr><th>1024</th><th>2048</th><th>4096</th><th>8192</th><th>16384</th></tr></thead><tbody><tr><td>1</td><td>1.0</td><td>1.0</td><td>1.0</td><td>1.0</td><td>1.0</td></tr><tr><td>2</td><td>1.59</td><td>2.01</td><td>1.85</td><td>1.95</td><td>2.09</td></tr><tr><td>4</td><td>2.03</td><td>3.78</td><td>3.77</td><td>4.14</td><td>3.52</td></tr><tr><td>8</td><td>5.69</td><td>5.86</td><td>3.43</td><td>5.91</td><td>4.86</td></tr><tr><td>16</td><td>4.04</td><td>1.75</td><td>2.20</td><td>5.14</td><td>1.90</td></tr></tbody></table>

**Odd even sort**

<table><thead><tr><th rowspan="2">N° de procesos</th><th colspan="5">Dimensiones de Matriz</th></tr><tr><th>200</th><th>400</th><th>800</th><th>1600</th><th>3200</th></tr></thead><tbody><tr><td>1</td><td>1.0</td><td>1.0</td><td>1.0</td><td>1.0</td><td>1.0</td></tr><tr><td>2</td><td>4.93</td><td>11.5</td><td>24.9</td><td>51.34</td><td>100.57</td></tr><tr><td>4</td><td>2.25</td><td>4.28</td><td>12.65</td><td>58.34</td><td>118.03</td></tr><tr><td>8</td><td>0.71</td><td>1.64</td><td>16.36</td><td>42.78</td><td>128.66</td></tr><tr><td>16</td><td>-</td><td>0.06</td><td>5.82</td><td>2.20</td><td>3.46</td></tr></tbody></table>

## Eficiencia

**Matrix - Vector Multiplication**

<table><thead><tr><th rowspan="2">N° de procesos</th><th colspan="5">Dimensiones de Matriz</th></tr><tr><th>1024</th><th>2048</th><th>4096</th><th>8192</th><th>16384</th></tr></thead><tbody><tr><td>1</td><td>1.0</td><td>1.0</td><td>1.0</td><td>1.0</td><td>1.0</td></tr><tr><td>2</td><td>0.79</td><td>0.10</td><td>0.92</td><td>0.97</td><td>1.04</td></tr><tr><td>4</td><td>0.50</td><td>0.09</td><td>0.94</td><td>1.03</td><td>0.88</td></tr><tr><td>8</td><td>0.71</td><td>0.07</td><td>0.42</td><td>0.73</td><td>0.60</td></tr><tr><td>16</td><td>0.25</td><td>0.01</td><td>0.13</td><td>0.32</td><td>0.11</td></tr></tbody></table>

**Odd even sort**

<table><thead><tr><th rowspan="2">N° de procesos</th><th colspan="5">Dimensiones de Matriz</th></tr><tr><th>200</th><th>400</th><th>800</th><th>1600</th><th>3200</th></tr></thead><tbody><tr><td>1</td><td>1.0</td><td>1.0</td><td>1.0</td><td>1.0</td><td>1.0</td></tr><tr><td>2</td><td>2.46</td><td>5.75</td><td>12.48</td><td>25.67</td><td>50.28</td></tr><tr><td>4</td><td>0.56</td><td>1.07</td><td>3.16</td><td>14.58</td><td>29.50</td></tr><tr><td>8</td><td>0.08</td><td>0.20</td><td>2.04</td><td>5.34</td><td>16.08</td></tr><tr><td>16</td><td>-</td><td>0.004</td><td>0.36</td><td>0.13</td><td>0.21</td></tr></tbody></table>

## Conclusión

Definitivamente las implementaciónes paralelas usando MPI , es más rápida. Obviamente esto está directamente relacionado con el hardware que poseamos, sin embargo, la eficiencia tiene resultados mixtos por lo tanto. Se podría hacer un acercamiento de tareas diferentes paralelas para mejorar la eficiencia de hecho. 
