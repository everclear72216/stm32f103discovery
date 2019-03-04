pwc_sources = []

pwc_sources += 'nmi.c'
pwc_sources += 'init.c'
pwc_sources += 'main.c'
pwc_sources += 'reset.c'
pwc_sources += 'vector.c'
pwc_sources += 'exceptions.c'

pwc_sources += 'fatalerror_' + get_option('buildtype') + '.c'

executable(
    'pwc',
    pwc_sources,
    dependencies: [
        ucapi_dep,
        ucapi_stm32_dep,
        ucapi_cortex_m_dep
    ],
    include_directories: include_dirs
)
