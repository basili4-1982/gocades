package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades -lccades
#include <stdlib.h>
#include "CCadesBlobs.h"
*/
import "C"

import (
	"errors"
	"unsafe"
)

type GoCadesBlobs struct {
	cobjptr *C.CCadesBlobs
}

func (obj *GoCadesBlobs) GetCount() (int, error) {
	var ret int
	val := C.CCadesBlobs_get_count(obj.cobjptr)
	err := C.GoString(C.CCadesBlobs_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesBlobs) GetItem(index int) (string, error) {
	var ret string
	val := C.CCadesBlobs_get_item(obj.cobjptr, C.int(index))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesBlobs_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}
