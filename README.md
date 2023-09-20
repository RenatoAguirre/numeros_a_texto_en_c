# Numero a texto

En muchas ocasiones en los programas profesionales, como finanzas, facturación, pagos e
incluso algunos legales, se debe transformar un numero a texto, de manera de impedir o al
menos dificultar la alteración posterior de documentos impresos. 
Es muy simple cuando se tiene un numero agregarle ceros al final, a la hora de querer cobrar
en la caja de un banco un cheque con un precio mayor, por esto, que además del número, 
se debe escribir con palabras.

### Algunos ejemplos:

**Entero**:  -183949 --> Menos ciento ochenta y tres mil novecientos cuarenta y nueve.
**Decimal**:  93847.37 --> Noventa y tres mil ochocientos cuarenta y siete punto treinta y siete.
**Rut**: 21873764-k --> Veintiun millones ochocientos setenta y tres mil setecientos sesenta y cuatro raya k

- Para los enteros, se pueden recibir números entre -99999999 y 99999999. El signo
siempre va a ir al principio, sin espacios. Los números no van a llevar separador de miles.

- Para los decimales, el rango va desde -99999999.999 a 99999999.999. El punto representa
el separador decimal.

- En el caso de rut, está compuesto por dos números separados por un guion. La primera
parte es un numero que va entre 1 y 99999999. El segundo número va desde 0 a 9,
sumando la letra k.


Este programa es una tarea de la universidad. Fue entregado el 12 de sept del 2023.
Hecho en una virtual machine con linux 