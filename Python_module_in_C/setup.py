from distutils.core import setup, Extension
setup(name='sample_system', version='1.0',ext_modules=[Extension('sample_system', ['samplemodule.c'])])
