subdir('devconf')

pcpp_prog = find_program('pcpp')
python_prog = find_program('python3')

pcpp_command = [pcpp_prog]
foreach directory: devconf_dirs
    pcpp_command += '-I'
    pcpp_command += meson.source_root() + '/' + directory
endforeach
pcpp_command += '-o'
pcpp_command += '@OUTPUT@'
pcpp_command += '@INPUT@'

devconf_dc = custom_target('devconf.dc',
    input: devconf_root,
    output: 'devconf.dc',
    command: pcpp_command
)

devconf_dc_dep = declare_dependency(sources: devconf_dc)

devconf_h = custom_target('devconf.h',
    input: devconf_dc,
    output: 'devconf.h',
    depends: devconf_dc,
    command: [python_prog, meson.source_root() + '/ucapi/devconf', '-o', '@OUTPUT@', '@INPUT@']
)

devconf_dep = declare_dependency(
    sources: devconf_h,
    dependencies: devconf_dc_dep
)
