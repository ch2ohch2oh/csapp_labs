target = 'flyers'
text = 'maduiersnfotvbyl'

for char in target:
    index = text.find(char)
    print(index, '\t->', chr(96 + index))