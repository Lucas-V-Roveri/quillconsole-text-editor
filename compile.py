import os
import sys
import subprocess

name = sys.argv[1]
files = []
for file in os.listdir('./src'):
    if file.endswith('cpp'):
        files.append('src/' +file);

if name+'.exe' in subprocess.check_output(['tasklist'], shell=True, universal_newlines=True):
    subprocess.run(['taskkill', '/IM', name+'.exe', '/F'], check=True)


output = ' '.join(files)    
os.system('g++ ' + output + ' -o' + name )