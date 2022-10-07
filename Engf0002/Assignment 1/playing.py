from multiprocessing.sharedctypes import Value

a = 2
b = 'lol'

try:
    c = a - b
except TypeError as e:
    print("There was a non-integer value")
finally:
    print("sucker")