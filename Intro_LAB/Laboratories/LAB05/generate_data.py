import sys
import hashlib
import numpy as np

# Lista zyrtare e studenteve (dictionary)
STUDENTS = {
    "Albana-1": "Albana",
    "AlexLabDev": "Aleksandro",
    "alesiadanga": "Alesia",
    "artea49": "Artea",
    "arteocarta": "Arteo",
    "bjorn-222": "Bjorn",
    "emanuel2704": "Emanuel L.",
    "emanuelzela56": "Emanuel Z.",
    "Ergi110": "Ergi",
    "esma0718": "Esma",
    "flori-fshn": "Florian",
    "Gledis2009": "Gledis",
    "Gito-Dev": "Horgito",
    "orindakoci21": "Orinda",
    "pavliii-del": "Pavlina",
    "reibruka": "Rei",
    "sergicani": "Sergi",
    "ejzelkurti07": "Zelie",
    "klausdragjoshi": "Klaus",
    "donaldoshtjefni441-cpu": "Donaldo",
    "erikcupi": "Erik"
}


def valido_studentin(user_id):
    """
    Kontrollon nese ID ekziston ne liste.
    Nese jo → ndalon programin.
    """
    if user_id not in STUDENTS:
        print("ERROR: ID e pavlefshme!")
        print("Sigurohuni qe po perdorni EXACT GitHub username tuaj.")
        sys.exit(1)

    return STUDENTS[user_id]


def id_ne_parametra(user_id):
    h = hashlib.sha256(user_id.encode("utf-8")).hexdigest()

    seed = int(h[:8], 16)

    r1 = int(h[8:16], 16) / 16**8
    r2 = int(h[16:24], 16) / 16**8
    r3 = int(h[24:32], 16) / 16**8

    a = 1.0 + 3.0 * r1
    b = -2.0 + 6.0 * r2
    sigma = 0.2 + 1.8 * r3

    return seed, sigma, a, b


def main():
    if len(sys.argv) != 2:
        print("Perdorimi: python script.py GITHUB_USERNAME")
        sys.exit(1)

    user_id = sys.argv[1]

    # Validim + marrja e emrit
    student_name = valido_studentin(user_id)

    # Pershendetje personale
    print(f"\nPershendetje {student_name}!")
    print("Po gjenerohen te dhenat tuaja unike...\n")

    seed, sigma, a, b = id_ne_parametra(user_id)
    rng = np.random.default_rng(seed)

    x = np.arange(1, 11, dtype=float)
    noise = rng.normal(0.0, sigma, size=x.shape)
    y = a * x + b + noise

    data = np.column_stack((x, y))

    np.savetxt(
        "model.dat",
        data,
        delimiter=",",
        header="# x_i, y_i",
        comments=f"# ID={user_id}, a={a:.3f}, b={b:.3f}, sigma={sigma:.3f}\n",
        fmt="%.6f"
    )

    print("Dataset u krijua me sukses!")
    print(f"Studenti : {student_name}")
    print(f"GitHub ID: {user_id}")
    print(f"a = {a:.3f}, b = {b:.3f}, sigma = {sigma:.3f}")
    print("File: model.dat\n")


if __name__ == "__main__":
    main()
