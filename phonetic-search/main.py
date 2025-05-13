import jellyfish

def print_phonetic(name):
    print(name, "=>", 
          "Soundex:", jellyfish.soundex(name), 
          "| Metaphone:", jellyfish.metaphone(name), 
          "| NYSIIS:", jellyfish.nysiis(name))

def print_phonetic_all(names):
    for name in names:
        print_phonetic(name)

print_phonetic_all(["House", "Houses"])
print_phonetic_all(["schwarzenegger", "schwarzenagar"])
print_phonetic_all(["schwarzenegger", "schwarzenager"])

print_phonetic_all(["night", "knight"])

print_phonetic_all(["prashant", "croissant"])
