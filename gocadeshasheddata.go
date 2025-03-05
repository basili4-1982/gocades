package gocades

/*
#cgo CFLAGS: -I/opt/ccades
#cgo LDFLAGS: -L/opt/ccades -Wl,-rpath=/opt/ccades -lccades
#include <stdlib.h>
#include "CCadesHashedData.h"
*/
import "C"

import (
	"errors"
	"runtime"
	"unsafe"
)

type GoCadesHashedData struct {
	cobjptr *C.CCadesHashedData
}

func HashedData() (*GoCadesHashedData, error) {
	result := C.CCadesHashedData_create()
	ret := &GoCadesHashedData{result}
	runtime.SetFinalizer(ret, func(obj *GoCadesHashedData) {
		C.CCadesHashedData_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesHashedData_error(ret.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesHashedData) PutAlgorithm(value int) error {
	C.CCadesHashedData_put_algorithm(obj.cobjptr, C.int(value))
	err := C.GoString(C.CCadesHashedData_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesHashedData) GetAlgorithm() (int, error) {
	var ret int
	val := C.CCadesHashedData_get_algorithm(obj.cobjptr)
	err := C.GoString(C.CCadesHashedData_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesHashedData) GetValue() (string, error) {
	var ret string
	val := C.CCadesHashedData_get_value(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesHashedData_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesHashedData) PutDataEncoding(value int) error {
	C.CCadesHashedData_put_data_encoding(obj.cobjptr, C.int(value))
	err := C.GoString(C.CCadesHashedData_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesHashedData) GetDataEncoding() (int, error) {
	var ret int
	val := C.CCadesHashedData_get_data_encoding(obj.cobjptr)
	err := C.GoString(C.CCadesHashedData_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesHashedData) PutKey(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesHashedData_put_key(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesHashedData_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesHashedData) GetKey() (string, error) {
	var ret string
	val := C.CCadesHashedData_get_key(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesHashedData_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesHashedData) Hash(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesHashedData_hash(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesHashedData_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesHashedData) SetHashValue(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesHashedData_set_hash_value(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesHashedData_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}
