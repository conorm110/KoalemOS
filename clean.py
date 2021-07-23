from os import walk
import os

f = []
for (dirpath, dirnames, filenames) in walk("osbuild/"):
    f.extend(filenames)
    for file in filenames:
        if file[-2] + file[-1] == ".h" or file[-2] + file[-1] == ".c":
            os.system("rm osbuild/" + file)
    break
os.system("rm -rf osbuild/build")