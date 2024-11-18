import os
import json

root = os.path.abspath('.')

searchable = os.path.join(root, 'src')

build = os.path.join(root, 'build')

def get_files():
    """
    Recovers the file paths of every .cpp file in the src folder.

    Returns:
        list: A list of absolute file paths ending with '.cpp'.
    """
    paths = []
    for file in os.listdir(searchable):
        if file.endswith('.cpp'):
            paths.append(os.path.join(searchable, file))
    return paths

def write_compile_commands(paths):
    """
    Writes the compile_commands.json file with the necessary compile commands.

    Args:
        paths (list): List of absolute paths to .cpp files.
    """
    filename = os.path.join(root, 'compile_commands.json')

    os.makedirs(build, exist_ok=True)

    compile_commands = []
    for file_path in paths:
        file_name = os.path.basename(file_path)
        output_file = os.path.join(build, file_name.replace('.cpp', '.o'))
        command = f"clang++ -Iinclude -std=c++17 -o {output_file} {file_path}"
        compile_command = {
            "directory": build,
            "command": command,
        }
        compile_commands.append(compile_command)

    with open(filename, 'w') as compiledb:
        json.dump(compile_commands, compiledb, indent=4)
    
    print('>> compile_commands.json has been successfully created.')

if __name__ == "__main__":
    print('\n<<| Retrieving .cpp files |>>\n')
    cpp_files = get_files()
    print('<<| Adding compile commands to compile_commands.json |>>\n')
    write_compile_commands(cpp_files)
    print('<<| compile_commands.json successfully generated :) |>>\n')
    