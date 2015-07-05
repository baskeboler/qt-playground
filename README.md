# qt-playground #
personal qt learning sandbox

## description ##
Simple person crud gui application.
Root project qt-playground is structured with the following subprojects:

### personas ###
Shared library containing "data facade" and class definition of the object we want to store. Data backend is XML.

### personastest ###
Test suite for *personas* project. 

### personas-admin ###
Qt GUI app that links to *personas* shared library. The app loads and saves all data to an xml file, creates, edits and deletes people from the dataset.

## build instructions ##
`$ qmake-qt5`
`$ make`
`$ make install`


more info soon ... 
	