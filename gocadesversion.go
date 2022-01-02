package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades -lccades
#include "CCadesVersion.h"
*/
import "C"
import "errors"

type GoCadesVersion struct {
	cobjptr *C.CCadesVersion
}

func (obj *GoCadesVersion) ToString() (string, error) {
	var ret string
	val := C.CCadesVersion_to_string(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesVersion) GetMajorVersion() (int, error) {
	var ret int
	val := C.CCadesVersion_get_major_version(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesVersion) GetMinorVersion() (int, error) {
	var ret int
	val := C.CCadesVersion_get_minor_version(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesVersion) GetBuildVersion() (int, error) {
	var ret int
	val := C.CCadesVersion_get_build_version(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}
