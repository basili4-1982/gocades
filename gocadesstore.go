package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades -lccades
#include <stdlib.h>
#include "CCadesStore.h"
*/
import "C"

import (
	"errors"
	"runtime"
	"unsafe"
)

type GoCadesStore struct {
	cobjptr *C.CCadesStore
}

func Store() (*GoCadesStore, error) {
	result := C.CCadesStore_create()
	ret := &GoCadesStore{result}
	runtime.SetFinalizer(ret, func(obj *GoCadesStore) {
		C.CCadesStore_destroy(obj.cobjptr)
	})
	err := C.GoString(result.err)
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesStore) Open(value int, name string, mode int) error {
	cstr := C.CString(name)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesStore_open(obj.cobjptr, C.int(value), cstr, C.int(mode))
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesStore) Close() error {
	C.CCadesStore_close(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesStore) Add(value GoCadesCertificate) error {
	C.CCadesStore_add(obj.cobjptr, value.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesStore) AddCRL(value GoCadesCRL) error {
	C.CCadesStore_add_crl(obj.cobjptr, value.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesStore) GetCertificates() (*GoCadesCertificates, error) {
	ret := &GoCadesCertificates{C.CCadesStore_get_certificates(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesCertificates) {
		C.CCadesCertificates_destroy(obj.cobjptr)
	})
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesStore) GetLocation() (int, error) {
	var ret int
	val := C.CCadesStore_get_location(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesStore) GetName() (string, error) {
	var ret string
	val := C.CCadesStore_get_name(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}
