import re
import fileinput


if __name__ == '__main__':
    idx = 1
    key = r'char |int |long |float |double |bool '

    inputs = open("in.txt", "r")
    outputs = open("out.txt", "w")

    for line in inputs:
        line = line.strip()
        line = re.sub(r"int main[\s\S]*", "", line)
        line = re.sub(r"=[\s\S]*,", ",", line)
        line = re.sub(r"=[\s\S]*;", "", line)
        line = re.sub(r"\[[\s\S]*\]", "", line)
        line = re.sub(r";", "", line)

        if re.search(key, line):
            line = re.sub(key, "", line)
            line = line.split(',')

            for i in line:
                i = re.sub(r"=[\s\S]*", "", i)
                ans = f'<{idx},{i}>'
                outputs.write(ans+'\n')
                idx += 1


# https://www.hackerrank.com/contests/03-symbol-table-sec-b/challenges/turn-the-symbol-table/problem