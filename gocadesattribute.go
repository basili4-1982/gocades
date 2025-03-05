package gocades

/*
#cgo CFLAGS: -I/opt/ccades
#cgo LDFLAGS: -L/opt/ccades -Wl,-rpath=/opt/ccades -lccades
#include <stdlib.h>
#include "CCadesAttribute.h"
*/
import "C"

import (
	"errors"
	"runtime"
	"unsafe"
)

type GoCadesAttribute struct {
	cobjptr *C.CCadesAttribute
}

func Attribute() (*GoCadesAttribute, error) {
	result := C.CCadesAttribute_create()
	ret := &GoCadesAttribute{result}
	runtime.SetFinalizer(ret, func(obj *GoCadesAttribute) {
		C.CCadesAttribute_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesAttribute_error(ret.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesAttribute) GetOID() (*GoCadesOID, error) {
	ret := &GoCadesOID{C.CCadesAttribute_get_oid(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesOID) {
		C.CCadesOID_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesAttribute_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesAttribute) PutOID(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesAttribute_put_oid(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesAttribute_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesAttribute) PutValue(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesAttribute_put_value(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesAttribute_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesAttribute) GetValue() (string, error) {
	var ret string
	val := C.CCadesAttribute_get_value(obj.cobjptr)
	err := C.GoString(C.CCadesAttribute_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesAttribute) PutName(value int) error {
	C.CCadesAttribute_put_name(obj.cobjptr, C.int(value))
	err := C.GoString(C.CCadesAttribute_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesAttribute) GetName() (int, error) {
	var ret int
	val := C.CCadesAttribute_get_name(obj.cobjptr)
	err := C.GoString(C.CCadesAttribute_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesAttribute) PutValueEncoding(value int) error {
	C.CCadesAttribute_put_value_encoding(obj.cobjptr, C.int(value))
	err := C.GoString(C.CCadesAttribute_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesAttribute) GetValueEncoding() (int, error) {
	var ret int
	val := C.CCadesAttribute_get_value_encoding(obj.cobjptr)
	err := C.GoString(C.CCadesAttribute_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}
