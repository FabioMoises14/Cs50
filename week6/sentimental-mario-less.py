
altura = int(input("Digite a altura desejada para a escada: "))

for row in range(0, altura + 1):
    espacos = ' ' * (altura - row)
    hashes = '#' * row
    print(espacos + hashes)



