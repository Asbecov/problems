def calculate(x, y):
    parentsX = []
    parentsY = []
    
    while x > 0:
        parentsX.append(x)
        x //= 2

    while y > 0:
        parentsY.append(y)
        y //= 2;
    
    for parent in parentsX:
        if parent in parentsY[::-1]:
            return parent
    
    return 0

if __name__ == "__main__":
    N = int(input())
    x = int(input())
    y = int(input())

    print(calculate(x, y))



