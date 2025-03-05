package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades -lccades
#include <stdlib.h>
#include "CCadesCertificate.h"
*/
import "C"

import (
	"errors"
	"runtime"
	"unsafe"
)

type GoCadesCertificate struct {
	cobjptr *C.CCadesCertificate
}

func Certificate() (*GoCadesCertificate, error) {
	result := C.CCadesCertificate_create()
	ret := &GoCadesCertificate{result}
	runtime.SetFinalizer(ret, func(obj *GoCadesCertificate) {
		C.CCadesCertificate_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesCertificate_error(ret.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesCertificate) Import(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesCertificate_import(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesCertificate) Export(encoding int) (string, error) {
	var ret string
	val := C.CCadesCertificate_export(obj.cobjptr, C.int(encoding))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesCertificate) GetInfo(value int) (string, error) {
	var ret string
	val := C.CCadesCertificate_get_info(obj.cobjptr, C.int(value))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesCertificate) HasPrivateKey() (bool, error) {
	var ret bool
	val := C.CCadesCertificate_has_private_key(obj.cobjptr)
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesCertificate) IsValid() (*GoCadesCertificateStatus, error) {
	ret := &GoCadesCertificateStatus{C.CCadesCertificate_is_valid(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesCertificateStatus) {
		C.CCadesCertificateStatus_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesCertificate) GetBasicConstraints() (*GoCadesBasicConstraints, error) {
	ret := &GoCadesBasicConstraints{C.CCadesCertificate_basic_constraints(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesBasicConstraints) {
		C.CCadesBasicConstraints_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesCertificate) GetExtendedKeyUsage() (*GoCadesExtendedKeyUsage, error) {
	ret := &GoCadesExtendedKeyUsage{C.CCadesCertificate_extended_key_usage(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesExtendedKeyUsage) {
		C.CCadesExtendedKeyUsage_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesCertificate) GetKeyUsage() (*GoCadesKeyUsage, error) {
	ret := &GoCadesKeyUsage{C.CCadesCertificate_key_usage(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesKeyUsage) {
		C.CCadesKeyUsage_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesCertificate) GetPrivateKey() (*GoCadesPrivateKey, error) {
	ret := &GoCadesPrivateKey{C.CCadesCertificate_private_key(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesPrivateKey) {
		C.CCadesPrivateKey_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesCertificate) GetPublicKey() (*GoCadesPublicKey, error) {
	ret := &GoCadesPublicKey{C.CCadesCertificate_public_key(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesPublicKey) {
		C.CCadesPublicKey_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesCertificate) GetSerialNumber() (string, error) {
	var ret string
	val := C.CCadesCertificate_get_serial_number(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesCertificate) GetIssuerName() (string, error) {
	var ret string
	val := C.CCadesCertificate_get_issuer_name(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesCertificate) GetSubjectName() (string, error) {
	var ret string
	val := C.CCadesCertificate_get_subject_name(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesCertificate) GetThumbprint() (string, error) {
	var ret string
	val := C.CCadesCertificate_get_thumbprint(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesCertificate) GetVersion() (int, error) {
	var ret int
	val := C.CCadesCertificate_get_version(obj.cobjptr)
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesCertificate) GetValidToDate() (string, error) {
	var ret string
	val := C.CCadesCertificate_get_valid_to_date(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesCertificate) GetValidFromDate() (string, error) {
	var ret string
	val := C.CCadesCertificate_get_valid_from_date(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesCertificate) FindPrivateKey() error {
	C.CCadesCertificate_find_private_key(obj.cobjptr)
	err := C.GoString(C.CCadesCertificate_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}
