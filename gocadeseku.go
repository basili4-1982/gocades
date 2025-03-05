package gocades

/*
#cgo CFLAGS: -I/opt/ccades
#cgo LDFLAGS: -L/opt/ccades -Wl,-rpath=/opt/ccades -lccades
#include <stdlib.h>
#include "CCadesEKU.h"
*/
import "C"

import (
	"errors"
	"unsafe"
)

type GoCadesEKU struct {
	cobjptr *C.CCadesEKU
}

func (obj *GoCadesEKU) GetName() (int, error) {
	var ret int
	val := C.CCadesEKU_get_name(obj.cobjptr)
	err := C.GoString(C.CCadesEKU_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesEKU) SetName(value int) error {
	C.CCadesEKU_put_name(obj.cobjptr, C.int(value))
	err := C.GoString(C.CCadesEKU_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesEKU) GetOID() (string, error) {
	var ret string
	val := C.CCadesEKU_get_oid(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesEKU_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesEKU) PutOID(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesEKU_put_oid(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesEKU_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}
