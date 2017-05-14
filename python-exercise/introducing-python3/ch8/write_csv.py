import csv

villains = [
    ['Doctor', 'No'],
    ['Rosa', 'Klebb'],
    ['Ernst', 'Blofeld'],
]

with open('villains', 'wt') as fout:
    csvout = csv.writer(fout)
    csvout.writerows(villains)

