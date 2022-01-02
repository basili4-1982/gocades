package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades -lccades
#include <stdlib.h>
#include "CCadesAbout.h"
*/
import "C"

import (
	"errors"
	"runtime"
	"unsafe"
)

type GoCadesAbout struct {
	cobjptr *C.CCadesAbout
}

func About() (*GoCadesAbout, error) {
	result := C.CCadesAbout_create()
	ret := &GoCadesAbout{result}
	runtime.SetFinalizer(ret, func(obj *GoCadesAbout) {
		C.CCadesAbout_destroy(obj.cobjptr)
	})
	err := C.GoString(result.err)
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesAbout) GetVersion() (string, error) {
	var ret string
	val := C.CCadesAbout_get_version(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesAbout) GetMajorVersion() (int, error) {
	var ret int
	val := C.CCadesAbout_get_major_version(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesAbout) GetMinorVersion() (int, error) {
	var ret int
	val := C.CCadesAbout_get_minor_version(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesAbout) GetBuildVersion() (int, error) {
	var ret int
	val := C.CCadesAbout_get_build_version(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesAbout) GetCSPVersion(ProvName string, ProvType int) (*GoCadesVersion, error) {
	cstr := C.CString(ProvName)
	defer C.free(unsafe.Pointer(cstr))
	ret := &GoCadesVersion{C.CCadesAbout_get_csp_version(obj.cobjptr, cstr, C.int(ProvType))}

	runtime.SetFinalizer(ret, func(obj *GoCadesVersion) {
		C.CCadesVersion_destroy(obj.cobjptr)
	})
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesAbout) GetCSPName(ProvType int) (string, error) {
	var ret string
	val := C.CCadesAbout_get_csp_name(obj.cobjptr, C.int(ProvType))
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}
