package gocades

/*
#cgo CFLAGS: -I/opt/ccades
#cgo LDFLAGS: -L/opt/ccades -Wl,-rpath=/opt/ccades -lccades
#include <stdlib.h>
#include "CCadesCertificates.h"
*/
import "C"

import (
	"errors"
	"runtime"
	"unsafe"
)

type GoCadesCertificates struct {
	cobjptr *C.CCadesCertificates
}

func (obj *GoCadesCertificates) GetCount() (int, error) {
	var ret int
	val := C.CCadesCertificates_get_count(obj.cobjptr)
	err := C.GoString(C.CCadesCertificates_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesCertificates) GetItem(value int) (*GoCadesCertificate, error) {
	ret := &GoCadesCertificate{C.CCadesCertificates_get_item(obj.cobjptr, C.int(value))}

	runtime.SetFinalizer(ret, func(obj *GoCadesCertificate) {
		C.CCadesCertificate_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesCertificates_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesCertificates) Find(value int, criteria string, validonly bool) (*GoCadesCertificates, error) {
	cstr := C.CString(criteria)
	defer C.free(unsafe.Pointer(cstr))
	ret := &GoCadesCertificates{C.CCadesCertificates_find_s(obj.cobjptr, C.int(value), cstr, C.bool(validonly))}

	runtime.SetFinalizer(ret, func(obj *GoCadesCertificates) {
		C.CCadesCertificates_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesCertificates_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}
