///Add Method
PyObject * sndMuteSound(PyObject * poSelf, PyObject * poArgs)
{
	CSoundManager::Instance().MuteSound();
	return Py_BuildNone();
}

//Find
		{ "SetMusicVolumef",		sndSetMusicVolume,			METH_VARARGS },
		
///Add
		{ "MuteSound",				sndMuteSound,				METH_VARARGS },