import os

def get_root(max_depth=8) -> str:
    start_dir = os.getcwd()
    current_dir = start_dir
    return_val = None
    for _ in range(max_depth):

        if os.path.isfile(os.path.join(current_dir, '.root')):
            return_val = current_dir
            break
        os.chdir('../')
        current_dir = os.getcwd()
    os.chdir(start_dir)

    return return_val

