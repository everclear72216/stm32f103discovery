project('Playing with CAN', 'c')

add_project_link_arguments('-Xlinker', '-Map=mapfile', language: 'c')

devconf_dirs = ['ucapi_cortex-m/devconf', 'ucapi_stm32/devconf']
subdir('devconf')

subdir('link')

subdir('ucapi')
subdir('ucapi_stm32')
subdir('ucapi_cortex-m')

dependencies = [devconf_dep, ucapi_dep, ucapi_cortex_m_dep, ucapi_stm32_dep, playwithcan_link_dep]

include_dirs = []

subdir('include')
subdir('source')
