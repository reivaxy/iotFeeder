import subprocess
import sys

revision = (
    subprocess.check_output(["git", "describe", "--always", "--dirty"])
    .strip()
    .decode("utf-8")
)
del sys.argv[0]
for arg in sys.argv:
    print(arg, end = ' ')
print("-DGIT_REV='\"%s\"'" % revision)