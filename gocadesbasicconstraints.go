package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades -lccades
#include <stdlib.h>
#include "CCadesBasicConstraints.h"
*/
import "C"

import (
	"errors"
)

type GoCadesBasicConstraints struct {
	cobjptr *C.CCadesBasicConstraints
}

func (obj *GoCadesBasicConstraints) GetIsPresent() (bool, error) {
	var ret bool
	val := C.CCadesBasicConstraints_get_is_present(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesBasicConstraints) SetIsPresent(value bool) error {
	C.CCadesBasicConstraints_put_is_present(obj.cobjptr, C.bool(value))
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesBasicConstraints) GetIsCritical() (bool, error) {
	var ret bool
	val := C.CCadesBasicConstraints_get_is_critical(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesBasicConstraints) SetIsCritical(value bool) error {
	C.CCadesBasicConstraints_put_is_critical(obj.cobjptr, C.bool(value))
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesBasicConstraints) GetIsCertificateAuthority() (bool, error) {
	var ret bool
	val := C.CCadesBasicConstraints_get_is_certificate_authority(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesBasicConstraints) GetIsPathLenConstraintPresent() (bool, error) {
	var ret bool
	val := C.CCadesBasicConstraints_get_is_path_len_constraint_present(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesBasicConstraints) GetPathLenConstraint() (int, error) {
	var ret int
	val := C.CCadesBasicConstraints_get_path_len_constraint(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}
