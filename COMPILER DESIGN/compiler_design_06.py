def split(word):
    return [char for char in word]


def printf(matched, stack, input, action):
    print("".join(matched).ljust(30), "".join(stack).ljust(25), "".join(input).ljust(30), action)


def algorithm(sentence, table, starting):
    status = None
    match = []
    stack = [starting, "$"]
    Inp = split(sentence)
    printf(["matched"], ["stack"], ["input"], "action")
    printf(match, stack, Inp, "")

    while len(sentence) > 0 and status != False:
        top_of_input = Inp[0]
        pos = top_of_input
        if stack[0] == "$" and pos == "$":
            printf(match, stack, Inp, "accepted")
            return "accepted"
        if stack[0] == pos:
            printf(match, stack, Inp, "pop")
            match.append(stack[0])
            del (stack[0])
            del (Inp[0])
            continue
        if stack[0] == "0":
            printf(match, stack, Inp, "poping epsilon")
            del (stack[0])
            continue
        try:
            production = table[stack[0]][pos]
            printf(match, stack, Inp, stack[0] + " -> " + production)
        except:
            return "not accepted"

        new = split(production)
        stack = new + stack[1:]
    return "not accepted"


if __name__ == "__main__":
    starting = "E"

    table = {
        "E": {"i": "Te", "(": "Te"},
        "e": {"+": "+Te", ")": "0", "$": "0"},
        "T": {"i": "Ft", "(": "Ft"},
        "t": {"+": "0", "*": "*Ft", ")": "0", "$": "0"},
        "F": {"i": "i", "(": "(E)"}
    }

    sentence = "i+i*i$"
    ans = algorithm(sentence, table, starting)
    print(f'\n{ans}')
