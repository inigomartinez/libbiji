project('libbiji', 'c',
  version: '3.21.2',
  license: 'GPL3+',
  default_options: [
    'buildtype=debug',
    'c_std=gnu11',
    'warning_level=1'
  ],
  meson_version: '>= 0.36.0'
)

libbiji_name = meson.project_name()
libbiji_version = meson.project_version()

version_array = libbiji_version.split('.')
libbiji_major_version = version_array[0].to_int()
libbiji_minor_version = version_array[1].to_int()
libbiji_micro_version = version_array[2].to_int()

libbiji_api_version = '@0@.0'.format(libbiji_major_version)

libbiji_api_string = '@0@-@1@'.format(libbiji_name, libbiji_api_version)

if libbiji_minor_version.is_odd()
  libbiji_interface_age = 0
else
  libbiji_interface_age = libbiji_micro_version
endif

soversion = 0
current = libbiji_minor_version * 100 + libbiji_micro_version - libbiji_interface_age
revision = libbiji_interface_age
libversion = '@0@.@1@.@2@'.format(soversion, current, revision)

libbiji_prefix = get_option('prefix')
libbiji_libdir = join_paths(libbiji_prefix, get_option('libdir'))
libbiji_datadir = join_paths(libbiji_prefix, get_option('datadir'))
libbiji_includedir = join_paths(libbiji_prefix, get_option('includedir'))

cc = meson.get_compiler('c')

conf = configuration_data()
conf.set('LIBBIJI_MAJOR_VERSION', libbiji_major_version)
conf.set('LIBBIJI_MINOR_VERSION', libbiji_minor_version)
conf.set('LIBBIJI_MICRO_VERSION', libbiji_micro_version)
conf.set('LIBBIJI_VERSION', libbiji_version)

conf.set_quoted('DATADIR', libbiji_datadir)

libbiji_cflags = [
  '-Wpointer-arith',
  '-Wmissing-declarations',
  '-Wformat=2',
  '-Wstrict-prototypes',
  '-Wmissing-prototypes',
  '-Wnested-externs',
  '-Wold-style-definition',
  '-Wdeclaration-after-statement',
  '-Wunused',
  '-Wuninitialized',
  '-Wshadow',
  '-Wmissing-noreturn',
  '-Wmissing-format-attribute',
  '-Wredundant-decls',
  '-Wlogical-op',
  '-Wcast-align',
  '-Wno-unused-local-typedefs',
  '-Werror=implicit',
  '-Werror=nonnull',
  '-Werror=init-self',
  '-Werror=main',
  '-Werror=missing-braces',
  '-Werror=sequence-point',
  '-Werror=return-type',
  '-Werror=trigraphs',
  '-Werror=array-bounds',
  '-Werror=write-strings',
  '-Werror=address',
  '-Werror=int-to-pointer-cast',
  '-Werror=pointer-to-int-cast',
  '-fno-strict-aliasing',
  '-Wno-int-conversion',
]

add_global_arguments(libbiji_cflags, language: 'c')

mathlib_dep = cc.find_library('m', required: true)
uuid_dep = dependency('uuid')
glib_dep = dependency('glib-2.0', version: '>=2.28')
gtk_dep = dependency('gtk+-3.0', version: '>=3.11.4')
webkit_dep = dependency('webkitgtk-3.0')
tracker_sparql_dep = dependency('tracker-sparql-1.0')
libecal_dep = dependency('libecal-1.2', version: '>=3.13.90')
libedataserver_dep = dependency('libedataserver-1.2', version: '>=3.13.90')
goa_dep = dependency('goa-1.0')

zeitgeist_enabled = get_option('enable-zeitgeist')
if zeitgeist_enabled
  zeitgeist_dep = dependency('zeitgeist-2.0')
endif

gnome = import('gnome')
pkg = import('pkgconfig')

subdir('src')
