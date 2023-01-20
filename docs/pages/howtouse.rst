How to use
=======================================

vrock libs use the meson build system so integrating it into your meson project is fairly easy.
you can create a .wrap file and put it in your `subproject` folder. The file should look like this.

.. code-block:: ini
    :caption: wrap-file

    [wrap-git]
    url=https://github.com/Visual-Rock/vrock.log
    revision=head
    depth=1

    [provide]
    vrocklog=loglib_dep

with this file in your `subproject` you can add the following lines to your meson.build file

.. code-block::
    :caption: dependency object

    loglib_dep = dependency('vrocklog', fallback: ['vrocklog', 'loglib_dep'])
    # you can add the default_options to build tests, examples and docs 
    loglib_dep = dependency('vrocklog', 
        fallback: ['vrocklog', 'loglib_dep'], 
        default_options: ['tests=true', 'examples=true', 'docs=true']
    )

now you can use `loglib_dep` as a meson dependency on your build targets like this.

.. code-block::
    :caption: adding as dependency

    exe = executable(
        'your_executable', 'main.cpp',
        dependencies: [ loglib_dep ]
    )