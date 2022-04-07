project('tutorial', 'c')
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

dependency('foo', required : get_option('someoption'))

executable('demo', 'hello.c')
