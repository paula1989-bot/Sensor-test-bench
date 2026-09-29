import sys
import math

TEMP_MIN, TEMP_MAX = 15.0, 35.0   # °C
G_MIN, G_MAX = 0.8, 1.2           # módulo de aceleración en reposo (g)

def check_sample(ax, ay, az, temp):
    g = math.sqrt(ax**2 + ay**2 + az**2)
    return TEMP_MIN <= temp <= TEMP_MAX and G_MIN <= g <= G_MAX

def main(path):
    total = fails = 0
    with open(path) as f:
        for line in f:
            parts = line.strip().split(",")
            if len(parts) != 5:
                continue
            try:
                t_ms, ax, ay, az, temp = map(float, parts)
            except ValueError:
                continue  # encabezado o líneas basura
            total += 1
            ok = check_sample(ax, ay, az, temp)
            if not ok:
                fails += 1
            print(f"{int(t_ms):>8} ms  temp={temp:6.2f}  {'PASS' if ok else 'FAIL'}")
    print(f"\nMuestras: {total} | FAIL: {fails}")
    print("RESULTADO GLOBAL:", "PASS" if total and fails == 0 else "FAIL")
    sys.exit(0 if total and fails == 0 else 1)

if __name__ == "__main__":
    main(sys.argv[1] if len(sys.argv) > 1 else "log.csv")