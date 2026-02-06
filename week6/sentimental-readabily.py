
def main():
    text = input('Enter a text\n>').strip()
    result = calculate_grade(text)
    print(result)

def calculate_grade(text):
    if not text:
        return 'Please enter a text.'

    letters = sum(1 for char in text if char.isalpha())
    words = len(text.split())
    setences = sum(1 for char in text if char in '.?!')

    if words == 0:
        return 'Before Grade 1.'

    L = (letters / words) * 100
    S = (setences / words) * 100

    index = 0.0588 * L - 0.296 * S - 15.8

    if index < 1:
        return  'Before Grade 1'
    elif index > 16:
        return 'After Grade 16'
    else:
        return f'Grade {round(index)}.'

if __name__ == '__main__':
    main()

