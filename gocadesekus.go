package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades -lccades
#include <stdlib.h>
#include "CCadesEKUs.h"
*/
import "C"

import (
	"errors"
	"runtime"
)

type GoCadesEKUs struct {
	cobjptr *C.CCadesEKUs
}

func (obj *GoCadesEKUs) GetCount() (int, error) {
	var ret int
	val := C.CCadesEKUs_get_count(obj.cobjptr)
	err := C.GoString(C.CCadesEKUs_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesEKUs) GetItem(value int) (*GoCadesEKU, error) {
	ret := &GoCadesEKU{C.CCadesEKUs_get_item(obj.cobjptr, C.int(value))}

	runtime.SetFinalizer(ret, func(obj *GoCadesEKU) {
		C.CCadesEKU_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesEKUs_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}
