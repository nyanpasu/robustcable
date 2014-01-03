import os

files = [f for f in os.listdir('.') if os.path.isfile(f)]
for f in files:
        if "dmi" in f:
                newName = f.replace("dmi","png")
                os.rename(f,newName)
                print(f + " has been renamed to " + newName)
