import random

def estimate_pi(precision):
    count = 0
    for i in range(0, 20**precision):
        x = random.random()
        y = random.random()
        if x*x + y*y <= 1:
            count += 1
    return (count/(20**precision)*4)
    
print(estimate_pi(int(input())))