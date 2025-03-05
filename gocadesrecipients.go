package gocades

/*
#cgo CFLAGS: -I$/opt/ccades
#cgo LDFLAGS: -L$/opt/ccades -Wl,-rpath=$/opt/ccades -lccades
#include <stdlib.h>
#include "CCadesRecipients.h"
*/
import "C"

import (
	"errors"
	"runtime"
)

type GoCadesRecipients struct {
	cobjptr *C.CCadesRecipients
}

func (obj *GoCadesRecipients) GetCount() (int, error) {
	var ret int
	val := C.CCadesRecipients_get_count(obj.cobjptr)
	err := C.GoString(C.CCadesRecipients_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesRecipients) GetItem(value int) (*GoCadesCertificate, error) {
	ret := &GoCadesCertificate{C.CCadesRecipients_get_item(obj.cobjptr, C.int(value))}

	runtime.SetFinalizer(ret, func(obj *GoCadesCertificate) {
		C.CCadesCertificate_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesRecipients_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesRecipients) Add(value GoCadesCertificate) error {
	C.CCadesRecipients_add(obj.cobjptr, value.cobjptr)
	err := C.GoString(C.CCadesRecipients_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesRecipients) Clear() error {
	C.CCadesRecipients_clear(obj.cobjptr)
	err := C.GoString(C.CCadesRecipients_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesRecipients) Remove(value int) error {
	C.CCadesRecipients_remove(obj.cobjptr, C.int(value))
	err := C.GoString(C.CCadesRecipients_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}
