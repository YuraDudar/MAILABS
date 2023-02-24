import os, sys

if not len(sys.argv) == 2:
    print("Use: {} <directory>".format(sys.argv[0]))
    sys.exit(1)

dir_path = sys.argv[1]
if not os.path.isdir(dir_path):
    print("Err: {} is not a directory".format(dir_path))
    sys.exit(1)

for dirpath, dirnames, _ in os.walk(dir_path):
    for dirname in dirnames:
        subdir_path = os.path.join(dirpath, dirname)
        print(subdir_path)
