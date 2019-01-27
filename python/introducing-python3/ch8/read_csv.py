import csv

with open('villains', 'rt') as fin:
    cin = csv.reader(fin)
    villains = [row for row in cin]

print(villains)

