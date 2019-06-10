# Put the path to your Python.h here
includes = -I/usr/include/python2.7

# Add the path to the directory containing libpython*.a here if the linking fails
# includes += -L/usr/share/lib/...

# Link your python version 
linkings = -lpython2.7

# Compiler definitions
definitions = -std=c++11

examples: minimal basic modern animation nonblock xkcd quiver bar surface fill_inbetween fill update

minimal: examples/minimal.cpp matplotlibcpp.h
	cd examples && g++ -DWITHOUT_NUMPY minimal.cpp ${includes} ${linkings} -o minimal ${definitions}

basic: examples/basic.cpp matplotlibcpp.h
	cd examples && g++ basic.cpp ${includes} ${linkings} -o basic ${definitions}

modern: examples/modern.cpp matplotlibcpp.h
	cd examples && g++ modern.cpp ${includes} ${linkings} -o modern ${definitions}

animation: examples/animation.cpp matplotlibcpp.h
	cd examples && g++ animation.cpp ${includes} ${linkings} -o animation ${definitions}

nonblock: examples/nonblock.cpp matplotlibcpp.h
	cd examples && g++ nonblock.cpp ${includes} ${linkings} -o nonblock ${definitions}

quiver: examples/quiver.cpp matplotlibcpp.h
	cd examples && g++ quiver.cpp ${includes} ${linkings} -o quiver ${definitions}

xkcd: examples/xkcd.cpp matplotlibcpp.h
	cd examples && g++ xkcd.cpp ${includes} ${linkings} -o xkcd ${definitions}

bar: examples/bar.cpp matplotlibcpp.h
	cd examples && g++ bar.cpp ${includes} ${linkings} -o bar ${definitions}

surface: examples/surface.cpp matplotlibcpp.h
	cd examples && g++ surface.cpp ${includes} ${linkings} -o surface ${definitions}

fill_inbetween: examples/fill_inbetween.cpp matplotlibcpp.h
	cd examples && g++ fill_inbetween.cpp ${includes} ${linkings} -o fill_inbetween ${definitions}

fill: examples/fill.cpp matplotlibcpp.h
	cd examples && g++ fill.cpp ${includes} ${linkings} -o fill ${definitions}
	
update: examples/update.cpp matplotlibcpp.h
	cd examples && g++ update.cpp ${includes} ${linkings} -o update ${definitions}

clean:
	rm -f examples/{minimal,basic,modern,animation,nonblock,xkcd,quiver,bar,surface,fill_inbetween,fill,update}
