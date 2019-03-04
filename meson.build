project('Playing with CAN', 'c')

# static configuration data
static_libs = []
include_dirs = []
link_dir = 'link/'
memory_layout_linker_script_destination = 'mem.ld'
section_layout_linker_script_destination = 'sections.ld'

boards = {
    'NUCLEO-F103RB': {
        'controller': 'stm32f103rb',
    },
}

bootloader_postfix = {
    'true': 'bootloader',
    'false': 'standalone',
}

# user configuration data
board_name = get_option('board')
use_bootloader = get_option('bootloader')

use_bootloader = use_bootloader ? 'true' : 'false'

memory_layout_linker_script_source = link_dir + boards[board_name]['controller'] + '_' + bootloader_postfix[use_bootloader] + '.ld'
section_layout_linker_script_source = link_dir + section_layout_linker_script_destination

configure_file(output: memory_layout_linker_script_destination, input: memory_layout_linker_script_source, copy: true)
configure_file(output: section_layout_linker_script_destination, input: section_layout_linker_script_source, copy: true)

add_project_link_arguments('-Tmem.ld', '-Tsections.ld', language: 'c')
add_project_link_arguments('-Xlinker', '-Map=mapfile', language: 'c')

subproject('ucapi')
ucapi_dep = dependency('ucapi', fallback: ['ucapi', 'ucapi_dep'])

subproject('ucapi_cortex-m')
ucapi_cortex_m_dep = dependency('ucapi_cortex-m', fallback: ['ucapi_cortex-m', 'ucapi_cortex_m_dep'])

subproject('ucapi_stm32')
ucapi_stm32_dep = dependency('ucapi_stm32_dep', fallback: ['ucapi_stm32', 'ucapi_stm32_dep'])

subdir('include')
subdir('source')
