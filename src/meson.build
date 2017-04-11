configure_file(output: 'config.h', configuration: conf)

marshallers = gnome.genmarshal(
  'biji-marshalers',
  sources: 'biji-marshalers.list',
  prefix: '_biji_marshal',
  install_header: true,
  install_dir: join_paths(libbiji_includedir, libbiji_api_string)
)

headers = [
  'libbiji.h',
  'biji-date-time.h',
  'biji-error.h',
  'biji-info-set.h',
  'biji-item.h',
  'biji-manager.h',
  'biji-notebook.h',
  'biji-note-id.h',
  'biji-note-obj.h',
  'biji-string.h',
  'biji-timeout.h',
  'biji-tracker.h',
  'biji-zeitgeist.h',
  'deserializer/biji-lazy-deserializer.h',
  'deserializer/biji-tomboy-reader.h',
  'editor/biji-editor-selection.h',
  'editor/biji-editor-utils.h',
  'editor/biji-webkit-editor.h',
  'provider/biji-import-provider.h',
  'provider/biji-local-note.h',
  'provider/biji-local-provider.h',
  'provider/biji-memo-note.h',
  'provider/biji-memo-provider.h',
  'provider/biji-own-cloud-note.h',
  'provider/biji-own-cloud-provider.h',
  'provider/biji-provider.h',
  'serializer/biji-lazy-serializer.h',
]

sources = [
  'biji-date-time.c',
  'biji-error.c',
  'biji-info-set.c',
  'biji-item.c',
  'biji-manager.c',
  'biji-notebook.c',
  'biji-note-id.c',
  'biji-note-obj.c',
  'biji-string.c',
  'biji-timeout.c',
  'biji-tracker.c',
  'biji-zeitgeist.c',
  'deserializer/biji-lazy-deserializer.c',
  'deserializer/biji-tomboy-reader.c',
  'editor/biji-editor-selection.c',
  'editor/biji-editor-utils.c',
  'editor/biji-webkit-editor.c',
  'provider/biji-import-provider.c',
  'provider/biji-local-note.c',
  'provider/biji-local-provider.c',
  'provider/biji-memo-note.c',
  'provider/biji-memo-provider.c',
  'provider/biji-own-cloud-note.c',
  'provider/biji-own-cloud-provider.c',
  'provider/biji-provider.c',
  'serializer/biji-lazy-serializer.c',
]

install_headers(headers, subdir: libbiji_api_string)

libbiji_deps = [
  mathlib_dep,
  uuid_dep,
  glib_dep,
  webkit_dep,
  tracker_sparql_dep,
  libecal_dep,
  libedataserver_dep,
  goa_dep
]

DATADIR = '='.join(['-DDATADIR', conf.get('DATADIR')])

libbiji_args = libbiji_cflags + [DATADIR]

if zeitgeist_enabled
  libbiji_deps += zeitgeist_dep
  libbiji_args += '-DBUILD_ZEITGEIST'
endif

libbiji_link_args = []
if cc.get_id() == 'gcc'
  libbiji_link_args += [
    '-Wl,-Bsymbolic-functions',
    '-Wl,-z,relro',
    '-Wl,-z,now',
  ]
endif

libtype = get_option('default_library')
if libtype == 'shared'
  libbiji_lib = shared_library(
                  libbiji_api_string,
                  name_prefix: '',
                  sources: sources + marshallers,
                  version: libversion,
                  soversion: soversion,
                  dependencies: libbiji_deps,
                  c_args: libbiji_args,
                  link_args: libbiji_link_args,
                  install: true
                )
endif

if libtype == 'static'
  libbiji_lib = static_library(
                  libbiji_api_string,
                  name_prefix: '',
                  sources: sources + marshallers,
                  dependencies: libbiji_deps,
                  c_args: libbiji_args,
                  link_args: libbiji_link_args,
                  install: true
                )
endif

pkg.generate(
  libraries: libbiji_lib,
  version: libbiji_version,
  name: libbiji_api_string,
  description: 'Library for note objects',
  filebase: libbiji_api_string,
  subdirs: libbiji_api_string,
)
