{
  'target_defaults': {
    'type': 'executable',
    'dependencies':
    [
      'deps/jsoncpp/jsoncpp.gyp:jsoncpp'
    ],
    'sources':
    [
      # C++ source files
      'src/main.cpp',
    ],
    'include_dirs':
    [
      'include'
    ],
    'conditions':
    [
      [ 'OS == "linux"', {
        'defines':
        [
          '_POSIX_C_SOURCE=200112',
          '_GNU_SOURCE'
        ]
      }]
    ]
	},
  'targets':
  [
    {
      'target_name': 'json_test',
      'sources':
      [
        # C++ source files
        'src/main.cpp'
      ]
    }
  ]
}
