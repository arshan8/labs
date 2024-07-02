def counter(file_name):
    words  = lines = chrs = 0
    with open(file_name,'r') as file:
        for line in file:
            lines += 1
            words += len(line.split())
            chrs += len(line)
    return words, lines, chrs

f = 'sample.txt'
a, b, c = counter(f)
print(f"total lines : {a}")
print(f"total words : {b}")
print(f"total characters : {c}")



