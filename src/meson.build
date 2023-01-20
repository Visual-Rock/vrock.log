src = [
    ''
]

header = [
    ''
]

public_header = include_directories('../include')

loglib = static_library(meson.project_name(), src,
    include_directories: public_header
)

loglib_dep = declare_dependency(
    include_directories: public_header,
    link_with: loglib
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