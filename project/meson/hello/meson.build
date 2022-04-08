project('tutorial', 'c',
  version: '1.2.3.4',
  default_options: ['buildtype=release', 'cpp_std=c++14'])

gst_version = '>= @0@'.format(meson.project_version())

message('project version:', gst_version)
message('build:', build_machine.system())
message('host:', host_machine.system())

if host_machine.system() == 'windows'
  cpp_args += [
    '-DNOMINMAX', # Don't define min and max macros (windows.h)
    # Don't bloat namespace with incompatible winsock versions.
    '-DWIN32_LEAN_AND_MEAN',
    # Don't warn about usage of insecure C functions.
    '-D_CRT_SECURE_NO_WARNINGS',
    '-D_SCL_SECURE_NO_WARNINGS',
    # Introduced in VS 2017 15.8, allow overaligned types in aligned_storage.
    '-D_ENABLE_EXTENDED_ALIGNED_STORAGE',
  ]
endif

dependency('foo', required : get_option('someoption'), method: 'pkg-config')

executable('demo', 'hello.c')

summary({'bindir': get_option('bindir'),
        'libdir': get_option('libdir'),
        'datadir': get_option('datadir'),
        }, section: 'Directories')

summary({'Some boolean': false,
        'Another boolean': true,
        'Some string': 'Hello World',
        'A list': ['string', 1, true],
        }, section: 'Configuration')
