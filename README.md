# Generadores aleatorios
En este repositorio se pueden encontrar diversos programas basados en la generación de numeros aleatorios
para realizar diferentes acciones.

## Compilacion de codigo - Windows
Si usted esta trabajando en Windows y quiere compilar todos los programas puede ejecutar el siguiente comando:

    make win all

Por otro lado, si unicamente quiere compilar uno de los programas puede ejecutar el siguiente comando:

    make win <nombre_programa>
donde nombre_programa es el id del programa (el listado de ids se puede ver en la tabla de abajo).

## Compilacion de codigo - Linux
Si por el contrario usted está trabajando sobre Linux, puede ejecutar los comandos del apartado anterior de la misma forma pero sustiotuyendo win por lnx de la siguinte forma para compilar todos los programas

    make lnx all

o de la siguiente para compilar un programa en especifico

    make lnx <nombre_programa>

## Tabla programas
<table>
<tr style='font-weight:bold'>
    <td>Programa</td><td>ID Programa</td><td>Descripcion</td>
</tr>

<tr>
    <td>Coin Flip</td>
    <td>coin_flip</td>
    <td>Simula el lanzamiento de una moneda</td>
</tr>
<tr>
    <td>Password Generator</td>
    <td>pass_gen</td>
    <td>Genera contraseñas aleatorias</td>
</tr>
<tr>
    <td>Dice Throw</td>
    <td>dice_throw</td>
    <td>Simula el lanzamiento de un dado de N caras</td>
</tr>
</table>
