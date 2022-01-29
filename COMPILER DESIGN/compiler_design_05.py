# 1. Keywords = int, main, return, char, if, else………………………………….
# 5. Function name = main(), myFun(),……………….
# 6. Numbers = 1,2,12.44, 43.50,………………………………..
# 2. Operators = +, -, * , &&, ||,>,<,=……………
# 3. Symbols = (,{,],;,),},]………………
# 4. Identifier = my_name, LengthCount, ans123,…..


import re
from itertools import chain


collect_functions = []


def remove_comments(line):
    def replacer(match):
        s = match.group(0)
        return ' ' if s.startswith('/') else s

    pattern = re.compile(r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"', re.DOTALL | re.MULTILINE)
    line = re.sub(pattern, replacer, line)
    line = line.strip()
    return line


def get_functions(s, r):
    m = re.findall(r'[\w.]+\(\)', s)
    t = re.sub(r'[\w.]+\(\)', '', s)
    if m == r:
        return
    for i in chain(m, get_functions(t, m)):
        yield i


def file_preprocessing(fname):
    global collect_functions

    f = open(fname, 'r')
    data = f.read()
    data = remove_comments(data)
    data = re.sub(r'\([^()]+\)', '()', data)
    data = data.replace(';', '')

    collect_functions = list(get_functions(data, []))

    tokens = []
    lines = data.split('\n')
    for line in lines:
        tokens += line.split(' ')

    while '' in tokens:
        tokens.remove('')

    for i in range(len(tokens)):
        # tokens[i] = tokens[i].strip()
        # tokens[i] = tokens[i].replace('\n', '')
        print(tokens[i])

    f.close()
    return tokens


def check_identifier(token):
    regex = '^[A-Za-z_][A-Za-z0-9_]*'
    if re.search(regex, token):
        return True
    return False


def checking(token, Numbers):
    for i in token:
        if i not in Numbers:
            return False
    return True


def print_list(name):
    for i in name:
        print(i, end=' ')
    print()


Keywords = ['auto', 'break', 'case', 'char', 'const', 'continue', 'default', 'do', 'double',
            'else', 'enum', 'extern', 'float', 'for', 'goto', 'if', 'int', 'long', 'register',
            'return', 'short', 'signed', 'sizeof', 'static', 'struct', 'switch', 'typedef',
            'union', 'unsigned', 'void', 'volatile', 'while']
Operators = ['=', '+', '-', '*', '/', '%', '!', '&', '|', '~', '^', '>', '<']
Symbols = ['(', '{', '[', ';', ']', '}', ')']
Numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

keywords_list = []
identifier_list = []
operators_list = []
symbols_list = []
numbers_list = []

fname = 'compiler_design_05_f1.c'
data = file_preprocessing(fname)

if collect_functions:
    print(f"functions_list: ", end='')
    for i in collect_functions:
        print(i, end=' ')
        if i not in data:
            data.remove(i)
    print()

for token in data:
    if token in Keywords and token not in keywords_list:
        keywords_list.append(token)

for token in data:
    if check_identifier(token) and token not in collect_functions and token not in keywords_list and token not in identifier_list:
        identifier_list.append(token)

for token in data:
    if checking(token, Numbers) and token not in numbers_list:
        numbers_list.append(token)

for token in data:
    if checking(token, Operators):
        operators_list.append(token)

for token in data:
    if checking(token, Symbols):
        symbols_list.append(token)

print('keywords_list: ', end='')
print_list(keywords_list)

print('identifier_list: ', end='')
print_list(identifier_list)

print('numbers_list: ', end='')
print_list(numbers_list)

print('operators_list: ', end='')
print_list(operators_list)

print('symbols_list: ', end='')
print_list(symbols_list)