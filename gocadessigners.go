package gocades

/*
#cgo CFLAGS: -I$/opt/ccades
#cgo LDFLAGS: -L$/opt/ccades -Wl,-rpath=$/opt/ccades -lccades
#include <stdlib.h>
#include "CCadesSigners.h"
*/
import "C"

import (
	"errors"
	"runtime"
)

type GoCadesSigners struct {
	cobjptr *C.CCadesSigners
}

func (obj *GoCadesSigners) GetCount() (int, error) {
	var ret int
	val := C.CCadesSigners_get_count(obj.cobjptr)
	err := C.GoString(C.CCadesSigners_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesSigners) GetItem(value int) (*GoCadesSigner, error) {
	ret := &GoCadesSigner{C.CCadesSigners_get_item(obj.cobjptr, C.int(value))}

	runtime.SetFinalizer(ret, func(obj *GoCadesSigner) {
		C.CCadesSigner_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesSigners_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}
