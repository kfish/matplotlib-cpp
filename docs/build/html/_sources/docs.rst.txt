.. _docs:

The Docs
********

.. _STL vector: https://en.cppreference.com/w/cpp/container/vector

How to use this documentation
=============================

Function definitions
++++++++++++++++++++

To find the definition and explanations for a special command use
the search field on the top left, since this page can get a bit lengthy.

Help for compiling
++++++++++++++++++

The section :ref:`Compiling a program <compile>` explains the compilations of
a program using the ``matplotlibcpp.h`` header.

Supplementary explanations
++++++++++++++++++++++++++

The sections :ref:`The formatting string <style>` and
:ref:`Additional keywords<keywords>` are supplementary for explaining options
in the plot commands.

.. _compile:

Compiling a program
===================

Requirements
++++++++++++

Matplotlib for C++ requires a working Python installation as well as
Matplotlib. Python2.7 and Python3 (>= 3.6) have been tested, but
other versions should work as well. In the linking process the exact
version of Python to use can be specified by linking the according library.

On Unix it is recommended to install Python via the package manager to
assert that all dependencies are installed properly.

.. code-block:: bash

   <package-manager> install python3 python3-dev  # or -devel depending on the platform

If Python is installed from source problems in the linking may occur.
How to resolve these is explained in the next section, or in
:ref:`this <pyfromsource>` code-block.

Install matplotlib via pip

.. code-block:: bash

  pip3 install matplotlib  # or pip for Python 2

Includes and Linking
++++++++++++++++++++

The header ``matplotlibcpp.h`` depends on the Python header, ``Python.h``,
the corresponding Python library ``libpython``, and on ``numpy/arrayobject.h``.
If not in the standard include paths, the paths to the header files,
the path to the library, and the library itself have to be specified
for the compiler using the options ``-I``, ``-L`` and ``-l`` respectively.
Note, that all Python constituents should be of the same Python version.
Matplotlib for C++ supports both, Python 2.7 and Python 3 versions.

In detail:

  - The Python header ``Python.h``

    The Python header comes with the Python installation. It it cannot be
    found on your system try installing the Python development packages.
    The location of this header has to be specified using the option ``-I``.

    Typical locations:

    - Linux: `/usr/local/include/python3.7`
    - Mac: if installed with Homebrew `/usr/local/Cellar/python/3.7.3/Frameworks/Python.framework/Versions/3.7/include/python3.7m`

  - The Python library ``libpython*.so``

    The program has to be linked against the compiled Python library.
    Depending on the Python version the name of the library differs, for
    Python 3.7 it is ``libpython3.7.so`` (or ``libpython3.7m.so``).
    Then link the library by specifying ``-lpython3.7`` (or ``-lpython3.7m``).

    Additionally to the linking the location of the library must be specified
    if not installed in the usual directory. For Linux systems this is
    usually not necessary, for Mac however it mostly is.
    The location of the library has to be specified using the option ``-L``.

    If Python has not been installed using the package manager (but e.g.
    from source) twofold problems with linking the library can occur.
    The first are missing dependencies of the Python library, these can be
    added via ``-lpthread -lutil -ldl``.
    The second is that dynamic libraries have to be exported which is
    resolved by adding ``-Xlinker -export-dynamic``.

    Typical locations:

    - Linux: Path usually already included
    - Mac: `/usr/local/Cellar/python/3.7.3/Frameworks/Python.framework/Versions/3.7/lib`

  - Numpy array ``numpy/arrayobject.h``

    By default Matplotlib for C++ uses Numpy arrays. This requires the above
    header file. However it is possible to avoid this header by defining
    ``-DWITHOUT_NUMPY``.

    - Linux: `/usr/local/lib/python3.7/site-packages/numpy/core/include`
    - Mac: If installed via Homebrew, same as for Linux.

**Examples**

On Linux with the GNU compiler ``g++`` and
C++11.

.. code-block:: bash

   # using Python 2.7
   g++ main.cpp -std=c++11 -I/usr/local/include/python2.7 \
     -I/usr/local/lib/python2.7/site-packages/numpy/core/include -lpython2.7

.. code-block:: bash

   # using Python3.7 and no Numpy
   g++ main.cpp -std=c++11 -DWITHOUT_NUMPY -I/usr/local/include/python2.7 -lpython2.7

On Mac with the GNU compiler ``g++`` and C++14.

.. code-block:: bash

   g++ main.cpp -std=c++14 \
    -I /usr/local/Cellar/python/3.7.3/Frameworks/Python.framework/Versions/3.7/include/python3.7m \
    -I /usr/local/lib/python3.7/site-packages/numpy/core/include \
    -L /usr/local/Cellar/python/3.7.3/Frameworks/Python.framework/Versions/3.7/lib \
    -lpython3.7

With exporting dynamic libraries and linking to all dependencies of
the Python library on a Linux system:

.. _pyfromsource:

.. code-block:: bash

   g++ main.cpp -std=c++11 -I/usr/local/include/python3.7m \
     -I/usr/local/lib/python3.7/site-packages/numpy/core/include \
     -lpython3.7m \ 
     -lpthread -lutil -ldl \ # library dependencies
     -Xlinker -export-dynamic \ # export dynamic libraries


.. _style:

The formatting string
=====================

Bla

.. _keywords:

Additional keywords
===================

Bla


Plot commands
=============

.. cpp:type:: Vector

   Functions in the Matplotlib-C++ library are designed to work with
   a generic vector type where possible. All template types named
   `Vector*` must support the following operations.
   See the `STL vector`_ documentation for more detail on the implementation.

   .. note::

      Check the declarations with the STL doc

   .. cpp:type:: double value_type

      Definition of the underlying type, `double` may be replaced with
      another suitable type.

   .. cpp:function:: std::size_t size()

      Return the size of the vector.

   .. cpp:function:: value_type operator[](const std::size_t i)

   .. cpp:function:: value_type at(const std::size_t i)

      Return the `i` th element of the vector.

   .. cpp:function:: value_type* data()

      Return a pointer to the first element of the data in the vector.
      The data must furthermore be stored in a consecutive manner.

   .. cpp:function:: value_type* begin()

      Return a pointer to the first element of the data in the vector.

   .. cpp:function:: value_type* end()

      Return a pointer directly behind the last element of the data in the vector.


.. cpp:function::
      template <typename VectorX, typename VectorY> \
      bool plot(const VectorX &x, const VectorY &y, const std::string &s = "", \
      const std::map<std::string, std::string> &keywords = {})

   Plot `y` versus `x`.

   The two vectors :math:`x` and :math:`y` must have the same length.
   The formatting string `s` can specify the colour, markers and style of the
   line.
   The map `keywords` may contain additional named arguments for the plot.

   :tparam VectorX: vector-like type, see :cpp:type:`Vector`
   :tparam VectorY: vector-like type, see :cpp:type:`Vector`
   :param x: :math:`x` data for the plot
   :param y: :math:`y` data for the plot
   :param s: (optional) formatting string, see :ref:`here <style>`
   :param keywords: (optional) map specifying additional keywords, see :ref:`here <keywords>`
   :returns: true if no error has occured, false otherwise

   **Minimal working example**

   .. code-block:: cpp

      #include <vector>
      #include "matplotlibcpp.h"
      namespace plt = matplotlibcpp;

      int main() {
        std::vector<double> x = {1, 2, 3, 4};
        std::vector<double> y = {1, 4, 9, 16};

        plt::plot(x, y);
        plt::show();

        return 0;
      }

   **Example with formatting strings**

   .. code-block:: cpp

      plt::plot(x, y, "r*");  // Red stars as markers, no line

   .. code-block:: cpp

      plt::plot(x, y, "bo-");  // Blue dots + blue line

   **Example with keywords**

   .. code-block:: cpp

      plt::plot(x, y, "bo-", {{"label", "f(x)"}});  // add the label f(x)
      plt::legend();                                // remember to activate the legend

   .. code-block:: cpp

      plt::plot(x, y, {{"label", "$y = x^2$"}});  // latex is supported
      plt::legend();


.. cpp:function::
      template <typename VectorY> \
      bool plot(const VectorY &y, const std::string &format = "", \
                const std::map<std::string, std::string> &keywords = {})

   Plot `y`.

   For a vector :math:`y` of size :math:`n`, the :math:`x` data
   is set to :math:`{0, ..., n - 1}`.
   The formatting string `s` can specify the colour, markers and style of the
   line.
   The map `keywords` may contain additional named arguments for the plot.

   :tparam VectorY: vector-like type, see :cpp:type:`Vector`
   :param y: :math:`y` data for the plot
   :param s: (optional) formatting string, see :ref:`here <style>`
   :param keywords: (optional) map specifying additional keywords, see :ref:`here <keywords>`
   :returns: true if no error has occured, false otherwise

.. cpp:function::
      template <typename VectorX, typename VectorY> \
      bool loglog(const VectorX &x, const VectorY &y, const std::string &s = "", \
                  const std::map<std::string, std::string> &keywords = {})

   Plot `y` versus `x` in double logarithmic scale.

   See :cpp:func:`plot` for explanation of the parameters.

   .. note::
      All following plots will be in double logarithmic scale,
      also calls to `plot`.

.. cpp:function::
      template <typename VectorY> \
      bool loglog(const VectorY &y, const std::string &s = "", \
                  const std::map<std::string, std::string> &keywords = {})

   Plot `y` in double logarithmic scale.

   See :cpp:func:`plot` for explanation of the parameters.

   .. note::
      All following plots will be in double logarithmic scale,
      also calls to `plot`.

.. cpp:function::
      template <typename VectorX, typename VectorY> \
      bool semilogx(const VectorX &x, const VectorY &y, const std::string &s = "", \
                    const std::map<std::string, std::string> &keywords = {})

   Plot `y` versus `x` in logarithmic `x` and linear `y` scale.

   See :cpp:func:`plot` for explanation of the parameters.

   .. note::
      All following plots will inherit the logarithmic `x` scale,
      also calls to `plot`.

.. cpp:function::
      template <typename VectorY> \
      bool semilogx(const VectorY &y, const std::string &s = "", \
                    const std::map<std::string, std::string> &keywords = {})

   Plot `y` in logarithmic `x` and linear `y` scale.

   See :cpp:func:`plot` for explanation of the parameters.

   .. note::
      All following plots will inherit the logarithmic `x` scale,
      also calls to `plot`.

.. cpp:function::
      template <typename VectorX, typename VectorY> \
      bool semilogy(const VectorX &x, const VectorY &y, const std::string &s = "", \
                    const std::map<std::string, std::string> &keywords = {})

   Plot `y` versus `x` in linear `x`  and logarithmic `y` scale.

   See :cpp:func:`plot` for explanation of the parameters.

   .. note::
      All following plots will inherit the logarithmic `y` scale,
      also calls to `plot`.

.. cpp:function::
      template <typename VectorY> \
      bool semilogy(const VectorY &y, const std::string &s = "", \
                    const std::map<std::string, std::string> &keywords = {})

   Plot `y` in linear `x` and logarithmic `y` scale.

   See :cpp:func:`plot` for explanation of the parameters.

   .. note::
      All following plots will inherit the logarithmic `y` scale,
      also calls to `plot`.

.. _layout:

Figure commands
===============

.. cpp:function::
      inline long figure(long number = -1)

    Initialise a new figure with the ID `number`.

    :param number: The number of the figure. If set to `-1` default numbering
                   (increasing from `0` on) is used.
    :return: The number of the figure.

.. cpp:function::
      inline bool fignum_exists(long number)

    Check if a figure of given number exists.

    :param number: The number of the figure
    :return: true, if a figure with given number exists, false otherwise

.. cpp:function::
      inline void figure_size(size_t w, size_t h)

    Set the figure size to `w` x `h` inches.

    :param w: The width of the figure in inches
    :param h: The height of the figure in inches

.. cpp:function::
      template <typename Vector = std::vector<double>> \
      inline void legend(const std::string &loc = "best", \
                         const Vector &bbox_to_anchor = Vector())

    Set the figure legend.

    :tparam Vector: vector-like type, see :cpp:type:`Vector`, defaults
                to `std::vector<double>`
    :param loc: The location of the legend. May be any of:
                "best", "upper left", "upper center", "upper left",
                "center left", "center", "center right" (== "right"),
                "lower left", "lower center", "lower right"
    :param bbox_to_anchor: If set to a vector of length 2 or 4 it
               specifies the location (and size) of the legend's bounding box.
               Format is (`x`, `y`) or (`x`, `y`, `width`, `height`).
               The coordinates are interpreted in the same units as the
               plot axes (thus no normalised coordinates)

.. cpp:function::
      template <typename Numeric> \
      void xlim(Numeric left, Numeric right)

    Set the `y` axis limits.

    :tparam Numeric: A scalar-like type
    :param left: The left axis limit
    :param right: The right axis limit

.. cpp:function::
      template <typename Numeric> \
      void ylim(Numeric bottom, Numeric top)

    Set the `y` axis limits.

    :tparam Numeric: A scalar-like type
    :param bottom: The bottom axis limit
    :param top: The top axis limit

.. cpp:function::
      inline double *xlim()

    Get the `x` axis limits.

    :return: A pointer to an array of length 2 containing `[left, right]`

.. cpp:function::
      inline double *ylim()

    Get the `y` axis limits.

    :return: A pointer to an array of length 2 containing `[bottom, top]`
