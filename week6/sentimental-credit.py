def main():
    card_number = get_card_input()

    if luhn_validate(card_number):
        formatted = ' '.join(card_number[i:i:4] for i in range(0, len(card_number),4))
        print(f'Valid Card: {formatted}')

    else:
        print('Invalid card number.')


def get_card_input():
    while True:
        card_input = input("Enter a credit card number:\n>").replace(' ','').replace('-','')

        if not card_input.isdigit():
            print("Only digits is allowed.")
            continue

        if len(card_input) < 13 or len(card_input) > 19:
            print("Must be 13-19 digits.")
            continue

        return card_input

def luhn_validate(card_number):
    digits = [int(d) for d in str(card_number)][ : -1]

    total = sum(
        digit if i % 2 == 0
        else digit * 2 if digit < 9
        else digit * 2 - 9
        for i,digit in enumerate(digits)
    )



    return total % 10 == 0



if __name__ == '__main__':
    main()

