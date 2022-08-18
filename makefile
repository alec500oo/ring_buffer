# Project makefile
#
# For use with Microsoft NMAKE

!include <win32.mak>

CFLAGS = -nologo
CPPFLAGS = -nologo -EHsc -Ilib\doctest\include -Iinclude
LFLAGS = -nologo

O = .\src
S = .\src
obj = $O\main.obj $O\rb_test.obj

all: test.exe 

test: test.exe
	.\test.exe

test.exe: $(obj)
	$(link) $(LFLAGS) $(ldebug) -out:$@ $**

{$S}.cpp{$O}.obj:
	$(CPP) $(CPPFLAGS) /c /Fo$(O)\ $<

clean:
	del *.obj *.pdb *.ilk *.exe
	del $(O)\*.obj

