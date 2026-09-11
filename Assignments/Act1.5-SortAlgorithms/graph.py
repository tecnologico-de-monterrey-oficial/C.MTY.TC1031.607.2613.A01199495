import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path

folder = Path(__file__).parent
data = pd.read_csv(folder / "sort_times.csv")

for data_type in data["tipoDato"].unique():
    current_data = data[data["tipoDato"] == data_type]

    plt.figure(figsize=(10, 6))

    for index, row in current_data.iterrows():
        sizes = [1000, 10000, 100000]
        times = [
            row["tiempo1000"],
            row["tiempo10000"],
            row["tiempo100000"]
        ]

        plt.plot(sizes, times, marker="o", label=row["algoritmo"])

    plt.title("Comparacion de algoritmos - " + data_type)
    plt.xlabel("Cantidad de datos")
    plt.ylabel("Tiempo en nanosegundos")
    plt.yscale("log")
    plt.grid()
    plt.legend()
    plt.tight_layout()

    plt.savefig(folder / ("comparacion_" + data_type + ".png"))
    plt.show()