#Validação
while True:
    try:
        altura = int(input("Digite a altura desejada para a escada: "))
        if 1 < altura <= 8:
            break
    except ValueError:
        print("Digite um número válido")


#Loop

for row in range(0, altura + 1):
    espacos = ' ' * (altura - row)
    hashes = '#' * row
    print(f'{espacos}{hashes} {hashes}')
