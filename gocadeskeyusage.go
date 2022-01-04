package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades -lccades
#include <stdlib.h>
#include "CCadesKeyUsage.h"
*/
import "C"

import (
	"errors"
)

type GoCadesKeyUsage struct {
	cobjptr *C.CCadesKeyUsage
}

func (obj *GoCadesKeyUsage) GetIsPresent() (bool, error) {
	var ret bool
	val := C.CCadesKeyUsage_get_is_present(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesKeyUsage) GetIsCritical() (bool, error) {
	var ret bool
	val := C.CCadesKeyUsage_get_is_critical(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesKeyUsage) GetIsCRLSignEnabled() (bool, error) {
	var ret bool
	val := C.CCadesKeyUsage_get_is_crl_sign_enabled(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesKeyUsage) GetIsDataEnciphermentEnabled() (bool, error) {
	var ret bool
	val := C.CCadesKeyUsage_get_is_data_encipherment_enabled(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesKeyUsage) GetIsDecipherOnlyEnabled() (bool, error) {
	var ret bool
	val := C.CCadesKeyUsage_get_is_decipher_only_enabled(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesKeyUsage) GetIsDigitalSignatureEnabled() (bool, error) {
	var ret bool
	val := C.CCadesKeyUsage_get_is_digital_signature_enabled(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesKeyUsage) GetIsEncipherOnlyEnabled() (bool, error) {
	var ret bool
	val := C.CCadesKeyUsage_get_is_encipher_only_enabled(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesKeyUsage) GetIsKeyAgreementEnabled() (bool, error) {
	var ret bool
	val := C.CCadesKeyUsage_get_is_key_agreement_enabled(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesKeyUsage) GetIsKeyCertSignEnabled() (bool, error) {
	var ret bool
	val := C.CCadesKeyUsage_get_is_key_cert_sign_enabled(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesKeyUsage) GetIsKeyEnciphermentEnabled() (bool, error) {
	var ret bool
	val := C.CCadesKeyUsage_get_is_key_encipherment_enabled(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesKeyUsage) GetIsNonRepudationEnabled() (bool, error) {
	var ret bool
	val := C.CCadesKeyUsage_get_is_non_repudation_enabled(obj.cobjptr)
	err := C.GoString(obj.cobjptr.err)
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}
