import os

files = []
for file in os.listdir('./src'):
    if file.endswith('cpp'):
        files.append('src/' +file);


output = ' '.join(files)    
os.system('g++ ' + output + ' -o texteditor' )