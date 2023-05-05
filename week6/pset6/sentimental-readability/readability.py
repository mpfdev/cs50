def main():
    text = input("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    indexL = average_of_letters(words, letters)
    indexS = average_of_sentences(words, sentences)

    index = index_colemanLiau(indexL, indexS)

    grading_text(index)

def count_letters(text):
    counter = 0
    for c in text:
        if c.isalpha():
            counter += 1
    
    return counter

def count_words(text):
    counter = 1
    for c in text:
        if c.isspace():
            counter += 1
    
    return counter

def count_sentences(text):
    counter = 0
    for c in text:
        if c == '.' or c == '?' or c == '!':
            counter += 1
    
    return counter

def average_of_letters(words, letters):
    return letters * 100.0 / words

def average_of_sentences(words, sentences):
    return sentences * 100.0 / words

def index_colemanLiau(average_letters, average_sentences):
    return 0.0588 * average_letters - 0.296 * average_sentences - 15.8

def grading_text(index):
    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade: {index:.0f}")

main()