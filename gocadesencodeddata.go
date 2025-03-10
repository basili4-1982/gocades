package gocades

/*
#cgo CFLAGS: -I/opt/ccades
#cgo LDFLAGS: -L/opt/ccades -Wl,-rpath=/opt/ccades -lccades
#include <stdlib.h>
#include "CCadesEncodedData.h"
*/
import "C"

import (
	"errors"
	"unsafe"
)

type GoCadesEncodedData struct {
	cobjptr *C.CCadesEncodedData
}

func (obj *GoCadesEncodedData) Format(value bool) error {
	C.CCadesEncodedData_format(obj.cobjptr, C.bool(value))
	err := C.GoString(C.CCadesEncodedData_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesEncodedData) GetValue(value int) (string, error) {
	var ret string
	val := C.CCadesEncodedData_get_value(obj.cobjptr, C.int(value))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesEncodedData_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}
