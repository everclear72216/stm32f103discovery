target = 'playwithcan'

sources = files(
    'nmi.c',
    'init.c',
    'main.c',
    'reset.c',
    'vector.c',
    'exceptions.c',

    'fatalerror_' + get_option('buildtype') + '.c'
)

playwithcan_exe = executable(
    target, sources, 
    dependencies: dependencies,
    include_directories: include_dirs
)