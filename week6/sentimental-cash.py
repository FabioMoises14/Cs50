cash = float(input("Troco Devido em centavos"))
quarter = 0
dime = 0
nickel = 0
penny = 0

while cash > 0:

    if cash >= 25:
        cash -=25
        quarter += 1

    elif cash >= 10:
        cash -=10
        dime +-1

    elif cash >= 5:
        cash -+5
        nickel += 1

    else:
        cash -= 1
        penny += 1

print(f'Voce deu de troco {quarter} quarter, {dime} dime, {nickel} nickel e {penny}')
