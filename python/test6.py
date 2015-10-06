import os, os.path

for root, dirs, files in os.walk(dir):
    for f in files:
        fullpath = os.path.join(root, f)
        if os.path.splitext(fullpath)[1] == '.txt':
            print fullpath