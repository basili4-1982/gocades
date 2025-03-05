package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades
#include <stdlib.h>
#include "CCadesPublicKey.h"
*/
import "C"

import (
	"errors"
	"runtime"
)

type GoCadesPublicKey struct {
	cobjptr *C.CCadesPublicKey
}

func (obj *GoCadesPublicKey) GetLength() (int, error) {
	var ret int
	val := C.CCadesPublicKey_get_length(obj.cobjptr)
	err := C.GoString(C.CCadesPublicKey_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesPublicKey) GetAlgorithm() (*GoCadesOID, error) {
	ret := &GoCadesOID{C.CCadesPublicKey_get_algorithm(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesOID) {
		C.CCadesOID_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesPublicKey_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesPublicKey) GetEncodedKey() (*GoCadesEncodedData, error) {
	ret := &GoCadesEncodedData{C.CCadesPublicKey_get_encoded_key(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesEncodedData) {
		C.CCadesEncodedData_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesPublicKey_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesPublicKey) GetEncodedParameters() (*GoCadesEncodedData, error) {
	ret := &GoCadesEncodedData{C.CCadesPublicKey_get_encoded_parameters(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesEncodedData) {
		C.CCadesEncodedData_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesPublicKey_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}
