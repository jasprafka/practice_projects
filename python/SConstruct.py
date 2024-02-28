import utilities
import os

_ROOT = utilities.get_root()
_C_DIR = os.path.join(_ROOT, 'c')
_GEN_DIR = os.path.join(_C_DIR, 'generated')

include_paths = [
    _C_DIR
]

main_alias = 'main'

env = Environment(CPPPATH=include_paths)

env.Help(
"""
scons main : build main executable
scons -c : clean up build artifacts
"""
)

# Sources are relative to the _C_DIR
sources = [
    os.path.join('sort', 'sort_algorithms.c'),
    os.path.join('search', 'binary_search.c')
]
objects = []
for src in sources:
    objects.append(env.Object(source=os.path.join(_C_DIR, src), target=os.path.join(_GEN_DIR, os.path.splitext(src)[0])))

program = env.Program(source=objects, target=os.path.join(_GEN_DIR, 'main'))
env.Alias(main_alias, program)