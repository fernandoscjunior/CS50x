def main():
    text = str(input("Insert text:"))
    letters = get_letters(text)
    words = len(text.split())
    sentences = get_sentences(text)
    grade = get_grade(letters, words, sentences)

    if grade > 16:
        print("Grade 16+")
    elif grade <= 0:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")

    # print(letters, words, sentences)


def get_letters(text):
    adder = 0
    for char in text:
        if char.isalpha():
            adder += 1
    return adder


def get_sentences(text):
    sentences = 0

    for i in range(len(text)):
        if text[i] == ".":
            sentences += 1
        elif text[i] == "!":
            sentences += 1
        elif text[i] == "?":
            sentences += 1

    return sentences


def get_grade(letters, words, sentences):

    l = float(letters)
    w = float(words)
    s = float(sentences)

    L = float(l / w * 100)
    S = float(s / w * 100)
    index = float(0.0588 * L - 0.296 * S - 15.8)
    final_index = round(index)

    return final_index


main()
