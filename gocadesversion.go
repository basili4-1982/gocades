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

//func version() *GoCadesVersion {
//	ret := &GoCadesVersion{C.CCadesVersion_create()}
//	runtime.SetFinalizer(ret, func(obj *GoCadesVersion) {
//		C.CCadesVersion_destroy(obj.version)
//	})
//	return ret
//}

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

func (obj *GoCadesVersion) GetMajorVersion() int {
	val := C.CCadesVersion_get_major_version(obj.cobjptr)
	return int(val)
}

func (obj *GoCadesVersion) GetMinorVersion() int {
	val := C.CCadesVersion_get_minor_version(obj.cobjptr)
	return int(val)
}

func (obj *GoCadesVersion) GetBuildVersion() int {
	val := C.CCadesVersion_get_build_version(obj.cobjptr)
	return int(val)
}
