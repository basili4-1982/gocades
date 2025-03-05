package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades
#include <stdlib.h>
#include "CCadesAlgorithm.h"
*/
import "C"

import (
	"errors"
)

type GoCadesAlgorithm struct {
	cobjptr *C.CCadesAlgorithm
}

func (obj *GoCadesAlgorithm) GetName() (int, error) {
	var ret int
	val := C.CCadesAlgorithm_get_name(obj.cobjptr)
	err := C.GoString(C.CCadesAlgorithm_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesAlgorithm) SetName(value int) error {
	C.CCadesAlgorithm_put_name(obj.cobjptr, C.int(value))
	err := C.GoString(C.CCadesAlgorithm_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesAlgorithm) GetKeyLength() (int, error) {
	var ret int
	val := C.CCadesAlgorithm_get_key_length(obj.cobjptr)
	err := C.GoString(C.CCadesAlgorithm_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesAlgorithm) SetKeyLength(value int) error {
	C.CCadesAlgorithm_put_key_length(obj.cobjptr, C.int(value))
	err := C.GoString(C.CCadesAlgorithm_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}
