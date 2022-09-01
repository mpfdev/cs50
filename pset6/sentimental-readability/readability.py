text = input("Text: ")

def main():
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    index_L = calculate_L(words, letters)
    index_S = calculate_S(words, sentences)
    index = round(calculate_index(index_L, index_S))

    grade_index = grade(index)
    print(f"{grade_index}")


def count_letters(text):
    text_list = []
    for i in range(len(text)):
        if text[i].isalpha():
            text_list += text[i]

    return len(text_list)

def count_words(text):
    word_counter = 0
    for i in range(len(text)):
        if text[i] == " ":
            word_counter += 1

    return word_counter + 1

def count_sentences(text):
    sentences_counter = 0
    for i in range(len(text)):
        if text[i] == "." or text[i] == "!" or text[i] == "?":
            sentences_counter += 1

    return sentences_counter

# index = 0.0588 * L - 0.296 * S - 15.8

def calculate_L(words, letters):
    return letters / words * 100

def calculate_S(words, sentences):
    return sentences / words * 100

def calculate_index(L, S):
    return (0.0588 * L) - (0.296 * S) - 15.8

# Grading

def grade(index):
    if index < 1:
        return "Before Grade 1"
    elif index >= 16:
        return "Grade 16+"
    else:
        string = "Grade " + str(index)
        return string

main()