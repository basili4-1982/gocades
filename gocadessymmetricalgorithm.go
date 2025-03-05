package gocades

/*
#cgo CFLAGS: -I/opt/ccades
#cgo LDFLAGS: -L/opt/ccades -Wl,-rpath=/opt/ccades -lccades
#include <stdlib.h>
#include "CCadesSymmetricAlgorithm.h"
*/
import "C"

import (
	"errors"
	"runtime"
	"unsafe"
)

type GoCadesSymmetricAlgorithm struct {
	cobjptr *C.CCadesSymmetricAlgorithm
}

func SymmetricAlgorithm() (*GoCadesSymmetricAlgorithm, error) {
	result := C.CCadesSymmetricAlgorithm_create()
	ret := &GoCadesSymmetricAlgorithm{result}
	runtime.SetFinalizer(ret, func(obj *GoCadesSymmetricAlgorithm) {
		C.CCadesSymmetricAlgorithm_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesSymmetricAlgorithm_error(ret.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesSymmetricAlgorithm) PutDiversData(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesSymmetricAlgorithm_put_divers_data(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesSymmetricAlgorithm_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSymmetricAlgorithm) GetDiversData() (string, error) {
	var ret string
	val := C.CCadesSymmetricAlgorithm_get_divers_data(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSymmetricAlgorithm_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSymmetricAlgorithm) PutIV(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesSymmetricAlgorithm_put_iv(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesSymmetricAlgorithm_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSymmetricAlgorithm) GetIV() (string, error) {
	var ret string
	val := C.CCadesSymmetricAlgorithm_get_iv(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSymmetricAlgorithm_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSymmetricAlgorithm) ImportKey(data string, cert GoCadesCertificate, password string) error {
	cstr := C.CString(data)
	defer C.free(unsafe.Pointer(cstr))
	cstr2 := C.CString(password)
	defer C.free(unsafe.Pointer(cstr2))
	C.CCadesSymmetricAlgorithm_import_key(obj.cobjptr, cstr, cert.cobjptr, cstr2)
	err := C.GoString(C.CCadesSymmetricAlgorithm_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSymmetricAlgorithm) ExportKey(cert GoCadesCertificate) (string, error) {
	var ret string
	val := C.CCadesSymmetricAlgorithm_export_key(obj.cobjptr, cert.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSymmetricAlgorithm_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSymmetricAlgorithm) GenerateKey(value int) error {
	C.CCadesSymmetricAlgorithm_generate_key(obj.cobjptr, C.int(value))
	err := C.GoString(C.CCadesSymmetricAlgorithm_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSymmetricAlgorithm) DiversifyKey() (*GoCadesSymmetricAlgorithm, error) {
	ret := &GoCadesSymmetricAlgorithm{C.CCadesSymmetricAlgorithm_diversify_key(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesSymmetricAlgorithm) {
		C.CCadesSymmetricAlgorithm_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesSymmetricAlgorithm_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesSymmetricAlgorithm) Encrypt(value string, final bool) (string, error) {
	var ret string
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	val := C.CCadesSymmetricAlgorithm_encrypt(obj.cobjptr, cstr, C.bool(final))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSymmetricAlgorithm_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSymmetricAlgorithm) Decrypt(value string, final bool) (string, error) {
	var ret string
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	val := C.CCadesSymmetricAlgorithm_decrypt(obj.cobjptr, cstr, C.bool(final))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSymmetricAlgorithm_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}
