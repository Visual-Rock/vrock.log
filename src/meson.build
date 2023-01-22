src = [
    'Logger.cpp',
    'LoggerConfig.cpp'
]

header = [
    '../include/vrock/log/Logger.hpp',
    '../include/vrock/log/LoggerConfig.hpp'
]

public_header = include_directories('../include')

spdlog_dep = dependency('spdlog', fallback: ['spdlog', 'spdlog_dep'])
utilslib_dep = dependency('vrockutils', fallback: ['vrockutils', 'vrockutils_dep'])

loglib = static_library(meson.project_name(), src,
    include_directories: public_header,
    dependencies: [ spdlog_dep ]
)

loglib_dep = declare_dependency(
    include_directories: public_header,
    link_with: loglib,
    dependencies: [ spdlog_dep, utilslib_dep ]
)
set_variable(meson.project_name() + '_dep', loglib_dep)

install_headers(header, subdir: 'vrock/log')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : meson.project_name(),
  filebase : meson.project_name(),
  description : '',
  subdirs : meson.project_name(),
  libraries : loglib,
)