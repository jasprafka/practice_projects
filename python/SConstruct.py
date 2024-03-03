import utilities
import os
from SCons.Environment import Environment

_ROOT = utilities.get_root()
_C_DIR = os.path.join(_ROOT, 'c')
_GEN_DIR = os.path.join(_C_DIR, 'generated')
_HELP_STR = '\n\tscons {:<15} : {}'

def _create_base_env() -> Environment:
    include_paths = [
        _C_DIR
    ]
    base_env = Environment(CPPPATH=include_paths)
    base_env.Help(_HELP_STR.format('-c', 'clean up build artifacts'))
    return base_env

def _create_demo_targets(demo_env: Environment) -> None:
    sort_demo = 'sort_demo'
    exe_target = os.path.join(_GEN_DIR, sort_demo, sort_demo)
    demo_env.Help(_HELP_STR.format(sort_demo, 'build sorting demonstration'))
    files = [
        os.path.join('sort', 'sort_algorithms.c'),
        os.path.join('utils', 'array_utils.c'),
        os.path.join('demos', 'sorting_demo.c')
    ]
    object_targets = []
    for file in files:
        src = os.path.join(_C_DIR, file)
        tgt = os.path.join(_GEN_DIR, os.path.splitext(file)[0])
        object_targets.append(demo_env.Object(target=tgt, source=src))
    
    sort_demo_tgt = demo_env.Program(target=exe_target, source=object_targets)
    demo_env.Alias(sort_demo, sort_demo_tgt)

base_env = _create_base_env()
_create_demo_targets(base_env.Clone())
