package gocades

/*
#cgo CFLAGS: -I$/opt/ccades
#cgo LDFLAGS: -L$/opt/ccades -Wl,-rpath=$/opt/ccades -lccades
#include <stdlib.h>
#include "CCadesAttributes.h"
*/
import "C"

import (
	"errors"
	"runtime"
)

type GoCadesAttributes struct {
	cobjptr *C.CCadesAttributes
}

func (obj *GoCadesAttributes) GetCount() (int, error) {
	var ret int
	val := C.CCadesAttributes_get_count(obj.cobjptr)
	err := C.GoString(C.CCadesAttributes_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesAttributes) GetItem(value int) (*GoCadesAttribute, error) {
	ret := &GoCadesAttribute{C.CCadesAttributes_get_item(obj.cobjptr, C.int(value))}

	runtime.SetFinalizer(ret, func(obj *GoCadesAttribute) {
		C.CCadesAttribute_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesAttributes_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesAttributes) Add(value GoCadesAttribute) error {
	C.CCadesAttributes_add(obj.cobjptr, value.cobjptr)
	err := C.GoString(C.CCadesAttributes_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesAttributes) Clear() error {
	C.CCadesAttributes_clear(obj.cobjptr)
	err := C.GoString(C.CCadesAttributes_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesAttributes) Remove(value int) error {
	C.CCadesAttributes_remove(obj.cobjptr, C.int(value))
	err := C.GoString(C.CCadesAttributes_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}
