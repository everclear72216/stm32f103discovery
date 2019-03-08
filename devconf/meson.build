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

devconf_toml = custom_target('devconf.toml',
    input: devconf_root,
    output: 'devconf.toml',
    command: pcpp_command
)

devconf_toml_dep = declare_dependency(sources: devconf_toml)

devconf_h = custom_target('devconf.h',
    input: devconf_toml,
    output: 'devconf.h',
    depends: devconf_toml,
    command: [python_prog, meson.source_root() + '/ucapi/devconf', '-o', '@OUTPUT@', '@INPUT@']
)

devconf_dep = declare_dependency(
    sources: devconf_h,
    dependencies: devconf_toml_dep
)