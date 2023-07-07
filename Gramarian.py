def read_txt(filename):
    """
    Function to read a text file and return its content as a list.
    """
    with open(filename, 'r') as file:
        words = [line.strip() for line in file]
    return words

def try_combinations(index, spell, letter, words):
    """
    Function to replace each letter in the word one by one, 
    and print the new word if it's found in the dictionary.
    """
    new_spell = ''.join([letter if count == index else l for count, l in enumerate(spell)])
    if new_spell in words:
        print(new_spell)

def main():
    """
    Main function to execute the program logic.
    """
    dictionary = read_txt("dictionary.txt")    
    alphabet = list('abcdefghijklmnopqrstuvwxyz')

    spell = list(input("Please enter spell name:\n---> ").lower())
    
    for index, letter in enumerate(spell):
        for char in alphabet:
            if char != letter:
                try_combinations(index, spell, char, dictionary)

if __name__ == "__main__":
    while True:
        main()
