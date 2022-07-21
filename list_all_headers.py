import os

files = os.listdir("headers")

for file in files:
    print("#include " + '"' + file + '"')