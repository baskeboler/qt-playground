TEMPLATE = subdirs

SUBDIRS += personas-core personas-core-test personas-admin-gui
DESTDIR = ../bin
personas-core.subdir=personas
personas-core-test.subdir=personastest
personas-core-test.depends=personas-core
personas-admin-gui.subdir=persona-admin
personas-admin-gui.depends=personas-core

