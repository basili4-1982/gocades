package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades -lccades
#include <stdlib.h>
#include "CCadesRawSignature.h"
*/
import "C"

import (
	"errors"
	"runtime"
	"unsafe"
)

type GoCadesRawSignature struct {
	cobjptr *C.CCadesRawSignature
}

func RawSignature() (*GoCadesRawSignature, error) {
	result := C.CCadesRawSignature_create()
	ret := &GoCadesRawSignature{result}
	runtime.SetFinalizer(ret, func(obj *GoCadesRawSignature) {
		C.CCadesRawSignature_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesRawSignature_error(ret.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesRawSignature) SignHash(hashed GoCadesHashedData, signer GoCadesCertificate) (string, error) {
	var ret string
	val := C.CCadesRawSignature_sign_hash(obj.cobjptr, hashed.cobjptr, signer.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesRawSignature_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesRawSignature) VerifyHash(hashed GoCadesHashedData, signer GoCadesCertificate, value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesRawSignature_verify_hash(obj.cobjptr, hashed.cobjptr, signer.cobjptr, cstr)
	err := C.GoString(C.CCadesRawSignature_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}
