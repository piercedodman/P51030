
#
# Makefile for P5 (submitted version)
# COSC 1030
# Fall 2024
#

__DRIVER_NAME__ = main
__ARRAY_NAME__ = rd_array
__DATE_NAME__ = Resources
__ERROR_NAME__ = Exceptions
__SUBMIT_NAME__ = submit
__LIBRARY_NAME__ = agLibrary


a.out: $(__DRIVER_NAME__).o $(__ERROR_NAME__).o $(__DATE_NAME__).o
	g++ -std=c++14 $(__DRIVER_NAME__).o $(__ERROR_NAME__).o $(__DATE_NAME__).o

$(__DRIVER_NAME__).o: $(__DRIVER_NAME__).cpp $(__DRIVER_NAME__).h $(__ARRAY_NAME__).h $(__ERROR_NAME__).h $(__DATE_NAME__).h
	g++ -std=c++14 -c $(__DRIVER_NAME__).cpp

$(__ERROR_NAME__).o: $(__ERROR_NAME__).cpp $(__ERROR_NAME__).h
	g++ -std=c++14 -c $(__ERROR_NAME__).cpp

$(__DATE_NAME__).o: $(__DATE_NAME__).cpp $(__DATE_NAME__).h $(__ERROR_NAME__).h
	g++ -std=c++14 -c $(__DATE_NAME__).cpp


.PHONY: submit clean

submit:
	rm -f $(__SUBMIT_NAME__).zip
	zip $(__SUBMIT_NAME__).zip $(__DRIVER_NAME__).cpp $(__DRIVER_NAME__).h $(__ARRAY_NAME__).h $(__ERROR_NAME__).cpp $(__ERROR_NAME__).h $(__DATE_NAME__).cpp $(__DATE_NAME__).h Makefile

clean:
	rm -f *.o core a.out


