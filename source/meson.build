target = 'playwithcan'

sources = files(
    'init.c',
    'main.c',
    'fatalerror_' + get_option('buildtype') + '.c'
)

playwithcan_exe = executable(
    target, sources, 
    dependencies: dependencies,
    include_directories: include_dirs
)
