import math

temp_min = 15
temp_max = 35

g_min = 0.8
g_max = 1.2

archivo = open("log.csv", "r")
next(archivo)

fallos = 0
muestras = 0

for linea in archivo:

    datos = linea.strip().split(",")

    if len(datos) != 5:
        continue

    tiempo = float(datos[0])
    ax = float(datos[1])
    ay = float(datos[2])
    az = float(datos[3])
    temperatura = float(datos[4])

    aceleracion = math.sqrt(ax**2 + ay**2 + az**2)

    temperatura_ok = temp_min <= temperatura <= temp_max

    aceleracion_ok = g_min <= aceleracion <= g_max

    muestras = muestras + 1

    if temperatura_ok and aceleracion_ok:
        print(tiempo, "ms - PASS")
    else:
        print(tiempo, "ms - FAIL")
        fallos = fallos + 1

archivo.close()

print("Muestras:", muestras)
print("Fallos:", fallos)

if fallos == 0 and muestras > 0:
    print("RESULTADO GLOBAL: PASS")
else:
    print("RESULTADO GLOBAL: FAIL")