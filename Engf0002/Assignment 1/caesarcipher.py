import string
from PyDictionary import PyDictionary

def break_cipher(sentence):
    alphabet = list(string.ascii_uppercase)
    sentence = list(sentence)
    newalphabet = list(string.ascii_uppercase)
    dictionary = PyDictionary()

    def push():
        newalphabet.insert(0, newalphabet.pop())
        return 0

    for x in range(0,26):
        push()
        endsentence = ''
        for y in range(0,len(sentence)):
            if sentence[y] == ' ':
                endsentence += ' '
            else:
                endsentence += newalphabet[alphabet.index(sentence[y])]
        print("Key", x+1, ":", endsentence)
        if dictionary.meaning(endsentence, disable_errors=True):
            print("THIS")

break_cipher(input())