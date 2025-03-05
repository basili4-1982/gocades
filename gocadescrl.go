package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades -lccades
#include <stdlib.h>
#include "CCadesCRL.h"
*/
import "C"

import (
	"errors"
	"runtime"
	"unsafe"
)

type GoCadesCRL struct {
	cobjptr *C.CCadesCRL
}

func CRL() (*GoCadesCRL, error) {
	result := C.CCadesCRL_create()
	ret := &GoCadesCRL{result}
	runtime.SetFinalizer(ret, func(obj *GoCadesCRL) {
		C.CCadesCRL_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesCRL_error(ret.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesCRL) Import(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesCRL_import(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesCRL_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesCRL) GetThisUpdate() (string, error) {
	var ret string
	val := C.CCadesCRL_get_this_update(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesCRL_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesCRL) GetNextUpdate() (string, error) {
	var ret string
	val := C.CCadesCRL_get_next_update(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesCRL_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesCRL) GetIssuerName() (string, error) {
	var ret string
	val := C.CCadesCRL_get_issuer_name(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesCRL_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesCRL) GetThumbprint() (string, error) {
	var ret string
	val := C.CCadesCRL_get_thumbprint(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesCRL_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesCRL) GetAuthKeyID() (string, error) {
	var ret string
	val := C.CCadesCRL_get_auth_key_id(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesCRL_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesCRL) Export(encoding int) (string, error) {
	var ret string
	val := C.CCadesCRL_export(obj.cobjptr, C.int(encoding))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesCRL_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}
