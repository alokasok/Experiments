#include<Python.h>

static PyObject *SampleError;
static PyObject *sample_system(PyObject *self, PyObject *args)
{
	const char *command;
	int sts;

	if (!PyArg_ParseTuple(args, "s", &command))
		return NULL;
	sts = system(command);
	
	if (sts <0 ){
		PyErr_SetString(SampleError, "System command failed");
		return NULL;
	}
	return Py_BuildValue("i", sts);
}

static PyMethodDef SampleMethods[] = {
    
    {"system",  sample_system, METH_VARARGS,
     "Execute a shell command."},
    
    {NULL, NULL, 0, NULL}        /* Sentinel */
};


PyMODINIT_FUNC initsample_system(void)
{
	PyObject *m;

    m = Py_InitModule("sample_system", SampleMethods);
    if (m == NULL)
        return;

    SampleError = PyErr_NewException("sample.error", NULL, NULL);
    Py_INCREF(SampleError);
    PyModule_AddObject(m, "error", SampleError);
}


