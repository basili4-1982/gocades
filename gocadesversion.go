package gocades

/*
#cgo CFLAGS: -I/opt/ccades
#cgo LDFLAGS: -L/opt/ccades -Wl,-rpath=/opt/ccades -lccades
#include <stdlib.h>
#include "CCadesVersion.h"
*/
import "C"
import (
	"errors"
	"unsafe"
)

type GoCadesVersion struct {
	cobjptr *C.CCadesVersion
}

func (obj *GoCadesVersion) ToString() (string, error) {
	var ret string
	val := C.CCadesVersion_to_string(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesVersion_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesVersion) GetMajorVersion() (int, error) {
	var ret int
	val := C.CCadesVersion_get_major_version(obj.cobjptr)
	err := C.GoString(C.CCadesVersion_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesVersion) GetMinorVersion() (int, error) {
	var ret int
	val := C.CCadesVersion_get_minor_version(obj.cobjptr)
	err := C.GoString(C.CCadesVersion_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesVersion) GetBuildVersion() (int, error) {
	var ret int
	val := C.CCadesVersion_get_build_version(obj.cobjptr)
	err := C.GoString(C.CCadesVersion_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}
